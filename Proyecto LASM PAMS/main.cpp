#include "Producto.h"
#include "Abarrotes.h"
#include "Alimento.h"
#include "Bebida.h"
#include <vector>
#include <iostream>
using namespace std;
int menu();
int main()
{
    vector<Producto*> inventario;

    cout<<"Laura Alejandra Santana Martínez"<<endl;
    cout<<"Pablo Artemio Medina Sahagun"<<endl;
    cout<<"Programación Orientada a Objetos"<<endl;
    cout<<"Tienda de Abarrotes ''El Fierrote'' "<<endl;
    menu();
    return 0;
}

int menu()
{
    int opcion;
    int regresar=1;
    do
    {
        cout<<"- - - - - - Menu - - - - - -"<<endl;
        cout<<"1. Ingresar productos"<<endl;
        cout<<"2. Buscar un producto"<<endl;
        cout<<"3. Eliminar un producto"<<endl;
        cout<<"4. Mostrar todos los productos"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese el numero de su opcion: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                cout<<"Saliendo del menu..."<<endl;
                break;

            default:
                cout<<"Opcion no valida. Intente de nuevo"<<endl;
        }
        if(opcion!=5){
            cout<<"Desea regresar al menu principal? (1 = Si, 0 = No): "<<endl;
            cin>>regresar;
            if(regresar == 0){
                return 0;
            }
        }
    }while(opcion!=5);
}
