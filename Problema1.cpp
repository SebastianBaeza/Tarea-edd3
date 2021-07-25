#include "funciones_Hashings.cpp"



void crear_Hashing_Productos(producto conj_Hash_Productos[]){
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
    conj_Hash_Productos = hash_Productos;
    productos.close();
};

void crear_Hashing_Ofertas(oferta conj_Hash_Ofertas[]){
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
    conj_Hash_Ofertas = hash_Ofertas;
    ofertas.close();
};

int main(){
    for (int i = 0; i< 5 ; i++){
        
    };

    return 0;
};