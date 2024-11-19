#include "Abarrotes.h"
using namespace std;

istream& operator>>(istream &entrada, Abarrotes &obj)
{
    entrada>>static_cast<Producto&>(obj);
    cout<<"Ingrese la categoría del producto: "<<endl;
    entrada.ignore();
    getline(entrada, obj.categoria);
    cout<<"Ingrese la cantidad por paquete: "<<endl;
    while(true){
        entrada>>obj.cantidadxPaquete;
        if(entrada.fail()){
            entrada.clear();
            entrada.ignore(1000,'\n');
            cout<<"Debes de ingresar una cantidad númerica, intenta de nuevo.\n";
        }
        else{break;}
    }

    return entrada;
}
//-----------------------------------------------------
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
    Producto::mostrarInfo();
    cout<<"Categoría: "<<categoria<<" - - - - -   Cantidad por paquete: "<<cantidadxPaquete<<endl;
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
