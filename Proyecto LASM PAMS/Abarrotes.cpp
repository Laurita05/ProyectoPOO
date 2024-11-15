#include "Abarrotes.h"
using namespace std;

Abarrotes::Abarrotes()
{
    //ctor
}

Abarrotes::Abarrotes(string nombre):Producto (nombre){}
Abarrotes::Abarrotes(string nombre, string fechaCaducidad):Producto (nombre,fechaCaducidad){}
Abarrotes::Abarrotes(string nombre,string fechaCaducidad,float precio):Producto (nombre,fechaCaducidad,precio){}
Abarrotes::Abarrotes(string nombre,string fechaCaducidad,float precio,int stock):Producto (nombre,fechaCaducidad,precio,stock){}
Abarrotes::Abarrotes(string nombre,string fechaCaducidad,float precio,int stock,string categoria):Producto (nombre,fechaCaducidad,precio,stock)
{
    this->categoria=categoria;
}
Abarrotes::Abarrotes(string nombre,string fechaCaducidad,float precio,int stock,string categoria,string cantidadxPaquete):Producto (nombre,fechaCaducidad,precio,stock)
{
    this->categoria=categoria;
    this->cantidadxPaquete=cantidadxPaquete;
}

void Abarrotes::mostrarInfo(void)
{
    cout<<"Categoria: "<<categoria<<", Cantidad por paquete: "<<cantidadxPaquete<<endl;
    Producto::mostrarInfo();
}

string Abarrotes::getCategoria(void)
{
    return categoria;
}
void Abarrotes::setCategoria(string categoria)
{
    this->categoria=categoria;
}
string Abarrotes::getCantidadxPaquete(void)
{
    return cantidadxPaquete;
}
void Abarrotes::setCantidadxPaquete(string cantidadxPaquete)
{
    this->cantidadxPaquete=cantidadxPaquete;
}
