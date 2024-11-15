#include "Producto.h"

Producto::Producto()
{
    //ctor
}

Producto::Producto(string nombre)
{
    this->nombre=nombre;
}
Producto::Producto(string nombre, string fechaCaducidad)
{
    this->nombre=nombre;
    this->fechaCaducidad=fechaCaducidad;
}
Producto::Producto(string nombre, string fechaCaducidad, float precio)
{
    this->nombre=nombre;
    this->fechaCaducidad=fechaCaducidad;
    this->precio=precio;
}
Producto::Producto(string nombre, string fechaCaducidad, float precio,int stock)
{
    this->nombre=nombre;
    this->fechaCaducidad=fechaCaducidad;
    this->precio=precio;
    this->stock=stock;
}

void Producto::mostrarInfo(void)
{
    cout<<"Nombre: "<<nombre<<", Precio: $"<<precio<<endl;
    cout<<"Fecha de Caducidad: "<<fechaCaducidad<<", Stock: "<<stock<<endl;
}
