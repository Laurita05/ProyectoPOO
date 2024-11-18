#include "Inventario.h"
#include "Producto.h"
#include "Abarrotes.h"
#include "Alimento.h"
#include "Bebida.h"
#include <iostream>
#include <cstdlib>
#include <locale>
#include <wchar.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
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
        cout<<"- - - - - - - -Menú Principal- - - - - - - -"<<endl;
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto\n";
        cout << "3. Eliminar producto\n";
        cout << "4. Mostrar todos los productos\n";
        cout << "5. Mostradorcito\n";
        cout << "6. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { // - - - -INGRESAR PRODUCTOS- - - -
                    system("CLS");
                    cout<<"- - - - - - - -Menú de Ingreso- - - - - - - -"<<endl;
                    cout<<"Que tipo de producto desea ingresar?"<<endl;
                    cout << "1. Agregar alimento"<<endl;
                    cout << "2. Agregar bebida"<<endl;
                    cout << "3. Agregar abarrotes"<<endl;
                    cout << "4. Volver al menú principal"<<endl;
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
                            cout<<"Saliendo al menú principal...\n";
                            break;
                        }
                        default: {
                            cout << "Opción inválida. Por favor, elige otra opción." << endl;
                            break;
                            }
                        }
                        system("PAUSE");
                break;
            }// FIN DEL CASE 1

            case 2: {// - - - -BUSCAR UN PRODUCTO- - - -
                string nombre;
                if (inventario.inventarioVacio()) {break;}
                cout << "Ingrese el nombre del producto a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                inventario.buscarProducto(nombre);
                break;
            }
            case 3: {// - - - -ELIMINAR PRODUCTOS- - - -
                string nombre;
                if (inventario.inventarioVacio()) {break;}
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                inventario.eliminarProducto(nombre);
                break;
            }
            case 4: {// - - - -MOSTRAR PRODUCTOS- - - -
                if (inventario.inventarioVacio()) {break;}
                inventario.mostrarProductos();
                break;
            }
            case 5: {// - - - -Yujuu rebajas de verano (MOSTRADORCITO)- - - -

                break;
            }
            case 6: {// - - - -SALIR- - - -
                cout << "¡Hasta luego!" << endl;
                break;
            }
            default:
                cout << "Opción inválida. Por favor, elige otra opción." << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != 6);

    return 0;
}

