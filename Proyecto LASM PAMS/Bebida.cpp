#include "Bebida.h"
using namespace std;

Bebida::Bebida()
{
    //ctor
}

Bebida::Bebida(string nombre):Producto (nombre){}
Bebida::Bebida(string nombre, string fechaCaducidad):Producto (nombre,fechaCaducidad){}
Bebida::Bebida(string nombre,string fechaCaducidad,float precio):Producto (nombre,fechaCaducidad,precio){}
Bebida::Bebida(string nombre,string fechaCaducidad,float precio,int stock):Producto (nombre,fechaCaducidad,precio,stock){}
Bebida::Bebida(string nombre,string fechaCaducidad,float precio,int stock,string sabor):Producto (nombre,fechaCaducidad,precio,stock)
{
    this->sabor=sabor;
}
Bebida::Bebida(string nombre,string fechaCaducidad,float precio,int stock,string sabor,int mililitros):Producto (nombre,fechaCaducidad,precio,stock)
{
    this->sabor=sabor;
    this->mililitros=mililitros;
}

void Bebida::mostrarInfo(void)
{
    cout<<"Sabor: "<<sabor<<", Mililitros: "<<mililitros<<endl;
    Producto::mostrarInfo();
}

string Bebida::getSabor(void)
{
    return sabor;
}
void Bebida::setSabor(string sabor)
{
    this->sabor=sabor;
}
int Bebida::getMililitros(void)
{
    return mililitros;
}
void Bebida::setMililitros(int mililitros)
{
    this->mililitros=mililitros;
}
