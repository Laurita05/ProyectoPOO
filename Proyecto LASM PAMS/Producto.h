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

        friend ostream& operator<<(ostream&, const Producto&);
        friend istream& operator>>(istream&, Producto&);
        Producto operator+(const Producto&);
        Producto operator-(const Producto&);
        Producto operator*(int);
        Producto operator/(int);
        Producto operator=(const Producto&);
        bool operator==(const Producto&);

        string getNombre(void);
        float getPrecio(void);
        void setPrecio(float);
        int getStock(void);
        void setStock(int);
        virtual ~Producto() {}
};

#endif // PRODUCTO_H
