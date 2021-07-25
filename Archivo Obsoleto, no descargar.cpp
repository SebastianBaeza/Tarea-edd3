#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define M 1000000
#define VACIA -1
#define C1 1
#define C2 0
#define C3 0
#define l 50

struct producto {
    int cod_producto;
    char nombre_producto[l];
    int precio;
};

struct oferta {
    int cod_producto;
    int cantidad_descuento;
    int descuento;
    int productos_equivalentes[10];
};

int h(int cod_producto){
    return cod_producto % 10;
};

int p(int cod_producto, int i) {
    if (i == 0) return 0;
    return C1*i*i + C2*i + C3;
}

int hashInsertProducto(producto HT[], producto I) {
    int inicio, i;
    int pos = inicio = h(I.cod_producto);
    for (i = 1; HT[pos].cod_producto != VACIA && HT[pos].cod_producto != I.cod_producto; i++)
    pos = (inicio + p(I.cod_producto, i)) % (sizeof(HT)/sizeof(*HT)); // próxima ranura en la secuencia
    if (HT[pos].cod_producto == I.cod_producto)
        return 0; // inserción no exitosa: cod_producto repetida
    else {
        HT[pos].cod_producto = I.cod_producto;
        HT[pos].precio = I.precio;
        for (int j = 0 ; j < l ; j++){
            HT[pos].nombre_producto[j] = I.nombre_producto[j];
        return 1; // inserción exitosa
        }
    };
};

int hashInsertOfertas(oferta HT[], oferta I) {
    int inicio, i;
    int pos = inicio = h(I.cod_producto);
    for (i = 1; HT[pos].cod_producto != VACIA && HT[pos].cod_producto != I.cod_producto; i++)
    pos = (inicio + p(I.cod_producto, i)) % (sizeof(HT)/sizeof(*HT)); // próxima ranura en la secuencia
    if (HT[pos].cod_producto == I.cod_producto)
        return 0; // inserción no exitosa: cod_producto repetida
    else {
        HT[pos].cod_producto = I.cod_producto;
        HT[pos].cantidad_descuento = I.cantidad_descuento;
        HT[pos].descuento = I.descuento;
        for (int j = 0 ; j < 10 ; j++){
            HT[pos].productos_equivalentes[j] = I.productos_equivalentes[j];
        return 1; // inserción exitosa
        }
    };
};



void crear_Hashing_Productos(){
    fstream productos;
    productos.open("productos.dat", ios::in);
    if(!productos.is_open()){
        cerr << "Error al abrir el archivo\n";
        exit(1); 
    };
    int n_productos;
    productos.read((char*)&n_productos, sizeof(int));
    producto *hash_Productos = new producto[n_productos/0.7];
    for (int i = 0 ; i < n_productos ; i++){
        producto nuevo;
        productos.read((char*)&nuevo, sizeof(producto));
        hashInsertProducto(hash_Productos, nuevo);
    };
};

void crear_Hashing_Ofertas(){
    fstream ofertas;
    ofertas.open("ofertas.dat", ios::in);
    if(!ofertas.is_open()){
        cerr << "Error al abrir el archivo\n";
        exit(1); 
    };
    int n_ofertas;
    ofertas.read((char*)&n_ofertas, sizeof(int));
    oferta *hash_Ofertas = new oferta[n_ofertas/0.7];
    for (int i = 0 ; i < n_ofertas ; i++){
        oferta nuevo;
        ofertas.read((char*)&nuevo, sizeof(oferta));
        hashInsertOfertas(hash_Ofertas, nuevo);
    };
};
