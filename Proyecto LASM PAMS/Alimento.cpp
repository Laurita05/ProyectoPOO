#include "Alimento.h"
using namespace std;

Alimento::Alimento()
{
    //ctor
}

Alimento::Alimento(string nombre):Producto (nombre){}
Alimento::Alimento(string nombre, string fechaCaducidad):Producto (nombre,fechaCaducidad){}
Alimento::Alimento(string nombre,string fechaCaducidad,float precio):Producto (nombre,fechaCaducidad,precio){}
Alimento::Alimento(string nombre,string fechaCaducidad,float precio,int stock):Producto (nombre,fechaCaducidad,precio,stock){}
Alimento::Alimento(string nombre,string fechaCaducidad,float precio,int stock,string tipo):Producto (nombre,fechaCaducidad,precio,stock)
{
    this->tipo=tipo;
}
Alimento::Alimento(string nombre,string fechaCaducidad,float precio,int stock,string tipo,int gramos):Producto (nombre,fechaCaducidad,precio,stock)
{
    this->tipo=tipo;
    this->gramos=gramos;
}

void Alimento::mostrarInfo(void)
{
    cout<<"Tipo: "<<tipo<<", Gramos: "<<gramos<<endl;
    Producto::mostrarInfo();
}

string Alimento::getTipo(void)
{
    return tipo;
}
void Alimento::setTipo(string tipo)
{
    this->tipo=tipo;
}

int Alimento::getGramos(void)
{
    return gramos;
}
void Alimento::setGramos(int gramos)
{
    this->gramos=gramos;
}
