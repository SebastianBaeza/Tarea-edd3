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

int h(int k){

};

int p(int k, int i) {
    if (i == 0) return 0;
    return C1*i*i + C2*i + C3;
}

int hashInsert(producto HT[], int k, producto I) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].cod_producto != VACIA && HT[pos].cod_producto != k; i++)
    pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia
    if (HT[pos].cod_producto == k)
        return 0; // inserción no exitosa: cod_producto repetida
    else {
        HT[pos].cod_producto = k;
        for (int j = 0 ; j < l ; j++){
            HT[pos].nombre_producto[j] = I.nombre_producto[j];
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
};


int main(){


    return 0;
};