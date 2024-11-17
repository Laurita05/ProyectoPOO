#include "Inventario.h"
#include "Producto.h"
#include "Abarrotes.h"
#include "Alimento.h"
#include "Bebida.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout<<"Laura Alejandra Santana Mart�nez"<<endl;
    cout<<"Pablo Artemio Medina Sahagun"<<endl;
    cout<<"Programaci�n Orientada a Objetos"<<endl;
    cout<<"Tienda de Abarrotes ''El Fierrote'' "<<endl;
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    Inventario inventario;
    int opcion, subOpcion;

    do {
        system("CLS");
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto\n";
        cout << "3. Eliminar producto\n";
        cout << "4. Mostrar todos los productos\n";
        cout << "5. Salir\n";
        cout << "Elige una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                //do {
                //system("CLS");
                    cout<<"Que tipo de producto desea ingresar?"<<endl;
                    cout << "1. Agregar alimento"<<endl;
                    cout << "2. Agregar bebida"<<endl;
                    cout << "3. Agregar abarrotes"<<endl;
                    cout << "4. Volver al menu principal"<<endl;
                    cout << "Elige una opci�n: ";
                    cin >> subOpcion;

                    switch (subOpcion) {
                        case 1: {
                            Alimento* alimento = new Alimento();
                            cin >> *alimento;
                            inventario.agregarProducto(alimento);
                            break;
                        }

                        case 2: {
                            Bebida* bebida = new Bebida();
                            cin >> *bebida;
                            inventario.agregarProducto(bebida);
                            break;
                        }

                        case 3: {
                            Abarrotes* abarrotes = new Abarrotes();
                            cin >> *abarrotes;
                            inventario.agregarProducto(abarrotes);
                            break;
                        }

                        case 4: {
                            cout<<"Saliendo al menu principal...\n";
                            break;
                        }
                        default: {
                            cout << "Opci�n inv�lida. Por favor, elige otra opci�n." << endl;
                            break;
                        }
                   // system("PAUSE");
                    //} while (subOpcion != 4);
                }
                break;
            }

            case 2: {
                string nombre;
                cout << "Ingrese el nombre del producto a buscar: ";
                cin >> nombre;
                inventario.buscarProducto(nombre);
                break;
            }
            case 3: {
                string nombre;
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin >> nombre;
                inventario.eliminarProducto(nombre);
                break;
            }
            case 4: {
                inventario.mostrarProductos();
                break;
            }
            case 5: {
                cout << "�Hasta luego!" << endl;
                break;
            }
            default:
                cout << "Opci�n inv�lida. Por favor, elige otra opci�n." << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != 5);
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    return 0;
}

