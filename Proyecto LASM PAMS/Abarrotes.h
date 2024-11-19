#ifndef ABARROTES_H
#define ABARROTES_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Abarrotes: public Producto
{
    private:
        string categoria;
        string cantidadxPaquete;
    public:
        Abarrotes();
        Abarrotes(string);
        Abarrotes(string,string);
        Abarrotes(string,string,float);
        Abarrotes(string,string,float,int);
        Abarrotes(string,string,float,int,string);
        Abarrotes(string,string,float,int,string,string);

        void mostrarInfo(void)override;

        friend istream& operator>>(istream&, Abarrotes&);
        string getCategoria(void);
        void setCategoria(string);
        string getCantidadxPaquete(void);
        void setCantidadxPaquete(string);
};

#endif // ABARROTES_H
