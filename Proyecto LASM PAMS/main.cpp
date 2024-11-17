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

    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    Inventario inventario;
    int opcion, subOpcion;

    do {
        system("CLS");
        cout<<"/ / / / / / / / / / / / / / / / / / / / / / / /"<<endl;
        cout<<"Laura Alejandra Santana Martínez"<<endl;
        cout<<"Pablo Artemio Medina Sahagun"<<endl;
        cout<<"Programación Orientada a Objetos"<<endl;
        cout<<"/ / / / / / / / / / / / / / / / / / / / / / / /"<<endl;
        cout<<"      \nTienda de Abarrotes ''El Fierrote'' "<<endl;
        cout<<"- - - - - - - -Menu Principal- - - - - - - -"<<endl;
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto\n";
        cout << "3. Eliminar producto\n";
        cout << "4. Mostrar todos los productos\n";
        cout << "5. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { //CASE 1
                    system("CLS");
                    cout<<"- - - - - - - -Menu de Ingreso- - - - - - - -"<<endl;
                    cout<<"Que tipo de producto desea ingresar?"<<endl;
                    cout << "1. Agregar alimento"<<endl;
                    cout << "2. Agregar bebida"<<endl;
                    cout << "3. Agregar abarrotes"<<endl;
                    cout << "4. Volver al menu principal"<<endl;
                    cout << "Elige una opción: ";
                    cin >> subOpcion;

                    switch (subOpcion) {
                        case 1: {
                            cout<<"- - - - - -ALIMENTO- - - - - -"<<endl;
                            Alimento* alimento = new Alimento();
                            cin >> *alimento;
                            inventario.agregarProducto(alimento);
                            break;
                        }

                        case 2: {
                            cout<<"- - - - - -BEBIDA- - - - - -"<<endl;
                            Bebida* bebida = new Bebida();
                            cin >> *bebida;
                            inventario.agregarProducto(bebida);
                            break;
                        }

                        case 3: {
                            cout<<"- - - - - -ABARROTES- - - - - -"<<endl;
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
                            cout << "Opción inválida. Por favor, elige otra opción." << endl;
                            break;
                            }
                        }
                        system("PAUSE");
                break;
            }//CASE 1

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
                cout << "¡Hasta luego!" << endl;
                break;
            }
            default:
                cout << "Opción inválida. Por favor, elige otra opción." << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != 5);
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    return 0;
}

