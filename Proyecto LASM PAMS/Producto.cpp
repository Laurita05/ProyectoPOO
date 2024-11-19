#include "Producto.h"

ostream& operator<<(ostream &salida, const Producto &obj)
{
    salida<<"Nombre: "<<obj.nombre<<" - - - - -  Precio: $"<<obj.precio<<endl;
    return salida;
}
istream& operator>>(istream &entrada, Producto &obj)
{
    cout<<"Ingrese el nombre del producto: "<<endl;
    entrada.ignore();
    getline(entrada, obj.nombre);
    cout<<"Ingrese el precio del producto: "<<endl;
    while(true){
        entrada>>obj.precio;
        if(entrada.fail()){
            entrada.clear();
            entrada.ignore(1000,'\n');
            cout<<"Debes de ingresar una cantidad númerica, intenta de nuevo.\n";
        }
        else{break;}
    }
    cout<<"Ingrese la fecha de caducidad del producto (DD/MM/AAAA): "<<endl;
    entrada.ignore();
    getline(entrada, obj.fechaCaducidad);
    cout<<"Ingrese el stock del producto: "<<endl;
    while(true){
        entrada>>obj.stock;
        if(entrada.fail()){
            entrada.clear();
            entrada.ignore(1000,'\n');
            cout<<"Debes de ingresar una cantidad númerica, intenta de nuevo.\n";
        }
        else{break;}
    }
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
    aux.precio=precio-obj.precio;
    return aux;
}
Producto Producto::operator*(int cantidad)
{
    Producto aux;
    aux.nombre=nombre+" x "+to_string(cantidad);
    aux.precio=precio*cantidad;
    return aux;
}
Producto Producto::operator/(int cantidad)
{
    Producto aux;
    aux.nombre=nombre+" / "+to_string(cantidad);
    aux.precio=precio/cantidad;
    return aux;
}
Producto Producto::operator=(const Producto &obj)
{
    if (this != &obj)
    {
        nombre = obj.nombre;
        precio = obj.precio;
    }
    return *this;
}
bool Producto::operator==(const Producto &obj)
{
    return (nombre == obj.nombre && precio == obj.precio);
}
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
    cout<<"Nombre: "<<nombre<<" - - - - -   Precio: $"<<precio<<endl;
    cout<<"Fecha de Caducidad: "<<fechaCaducidad<<" - - - - -   Stock: "<<stock<<endl;
}

string Producto::getNombre(void)
{
    return nombre;
}
