#ifndef BEBIDA_H
#define BEBIDA_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Bebida: public Producto
{
    private:
        string sabor;
        int mililitros;
    public:
        Bebida();
        Bebida(string);
        Bebida(string,string);
        Bebida(string,string,float);
        Bebida(string,string,float,int);
        Bebida(string,string,float,int,string);
        Bebida(string,string,float,int,string,int);

        void mostrarInfo(void)override;

        friend ostream& operator<<(ostream&, const Bebida&);
        friend istream& operator>>(istream&, Bebida&);
        string getSabor(void);
        void setSabor(string);
        int getMililitros(void);
        void setMililitros(int);
};

#endif // BEBIDA_H
