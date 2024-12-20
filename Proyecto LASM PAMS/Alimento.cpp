#include "Alimento.h"
using namespace std;

istream& operator>>(istream &entrada, Alimento &obj)
{
    entrada>>static_cast<Producto&>(obj);
    cout<<"Ingrese el tipo del producto: "<<endl;
    entrada.ignore();
    getline(entrada, obj.tipo);
    cout<<"Ingrese los gramos: "<<endl;
    while(true){
        entrada>>obj.gramos;
        if(entrada.fail()|| obj.gramos < 0){
            entrada.clear();
            entrada.ignore(1000,'\n');
            cout<<"Debes de ingresar una cantidad n�merica positiva, intenta de nuevo.\n";
        }
        else{break;}
    }

    return entrada;
}
//-----------------------------------------------------
Alimento::Alimento()
{
    //ctor
}

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
    Producto::mostrarInfo();
    cout<<"Tipo: "<<tipo<<" - - - - -   Gramos: "<<gramos<<endl;
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
