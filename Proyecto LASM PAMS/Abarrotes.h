#ifndef ABARROTES_H
#define ABARROTES_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Abarrotes: public Producto
{
    private:
        string categoria;
        int cantidadxPaquete;
    public:
        Abarrotes();
        Abarrotes(string,string,float,int,string);
        Abarrotes(string,string,float,int,string,int);

        void mostrarInfo(void)override;

        friend istream& operator>>(istream&, Abarrotes&);
        string getCategoria(void);
        void setCategoria(string);
        int getCantidadxPaquete(void);
        void setCantidadxPaquete(int);
};

#endif // ABARROTES_H
