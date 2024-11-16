#include "Producto.h"

ostream& operator<<(ostream &salida, const Producto &obj)
{
    salida<<"Nombre: "<<obj.nombre<<", Precio: $"<<obj.precio<<endl;
    return salida;
}
istream& operator>>(istream &entrada, Producto &obj)
{
    cout<<"Ingrese el nuevo nombre del producto: "<<endl;
    entrada>>obj.nombre;
    cout<<"Ingrese el nuevo precio del producto: "<<endl;
    entrada>>obj.precio;
    return entrada;
}
Producto Producto::operator+(const Producto &obj)
{
    Producto aux;
    aux.nombre=nombre+" + "+obj.nombre;
    aux.precio=precio+obj.precio;
    return aux;
}
Producto Producto::operator-(const Producto &obj)
{
    Producto aux;
    aux.nombre=nombre+" - "+obj.nombre;
    aux.precio=precio+obj.precio;
    return aux;
}
Producto Producto::operator*(const Producto &obj)
{
    Producto aux;
    aux.nombre=nombre+" x "+obj.nombre;
    aux.precio=precio+obj.precio;
    return aux;
}
Producto Producto::operator/(const Producto &obj)
{
    Producto aux;
    aux.nombre=nombre+" / "+obj.nombre;
    aux.precio=precio+obj.precio;
    return aux;
}
/*Producto Producto::operator=(const Producto &obj);
bool Producto::operator==(const Producto &obj)
{
    return (nombre == other.nombre && precio == other.precio);
}*/
//-----------------------------------------------------
Producto::Producto()
{
    //ctor
}
//-----------------------------------------------------

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
