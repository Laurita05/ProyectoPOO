#ifndef ALIMENTO_H
#define ALIMENTO_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Alimento: public Producto
{
    private:
        string tipo;
        int gramos;
    public:
        Alimento();
        Alimento(string);
        Alimento(string,string);
        Alimento(string,string,float);
        Alimento(string,string,float,int);
        Alimento(string,string,float,int,string);
        Alimento(string,string,float,int,string,int);

        void mostrarInfo(void)override;

        friend istream& operator>>(istream&, Alimento&);
        string getTipo(void);
        void setTipo(string);
        int getGramos(void);
        void setGramos(int);
};

#endif // ALIMENTO_H
