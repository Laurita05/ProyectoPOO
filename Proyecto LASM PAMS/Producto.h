#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

class Producto
{
    protected:
        string nombre;
        string fechaCaducidad;
        float precio;
        int stock;
    public:
        Producto();
        Producto(string);
        Producto(string,string);
        Producto(string,string,float);
        Producto(string,string,float,int);

        virtual void mostrarInfo(void);
};

#endif // PRODUCTO_H
