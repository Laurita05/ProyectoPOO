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
    setlocale(LC_ALL, "");//Esto es para que se pongan los acentos en todo :D
    Inventario inventario;//Declaración del objeto inventario, de la clase Inventario valga la redundancia
    int opcion, subOpcion;//Opciones para el switch del menú y del sub-menú

    Producto p1("Manzana","27/11/2024",12.75, 100);// prueba
    Producto p2("Pera","27/11/2024",10.5, 88);// prueba
    Producto p3("Banano","27/11/2024",13, 100);// prueba

    Producto* manzana = new Producto("Manzana", "27/11/2024", 12.75, 100);
    Producto* pera = new Producto("Pera", "27/11/2024", 10.5, 88);
    Producto* banano = new Producto("Banano", "27/11/2024", 13, 100);
    inventario.agregarProducto(manzana);
    inventario.agregarProducto(pera);
    inventario.agregarProducto(banano);

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
        cout << "5. Extra(sobrecargas)\n";
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
            case 5: {// - - - -Sobrecarguitas- - - -
                cout << "Producto 1: " << p1 << endl;
                cout << "Producto 2: " << p2 << endl;
                cout << "Producto 3: " << p3 << endl;
                Producto suma = p1 + p2; // <--------sobrecarga operador +
                cout << "\nResultado de p1 + p2:" << suma << endl;

                Producto resta = p1 - p2; // <--------sobrecarga operador -
                cout << "\nResultado de p1 - p2:" << resta << endl;

                Producto multiplicacion = p1 * 3; // <--------sobrecarga operador *
                cout << "\nResultado de p1 * 3:" << multiplicacion << endl;

                Producto division = p2 / 2; // <--------sobrecarga operador /
                cout << "\nResultado de p2 / 2:" << division << endl;

                p3 = p1;// <--------sobrecarga operador =
                cout << "\nDespués de la asignación (p3 = p1):\n";
                cout << "Producto 1: " << p1 << endl;
                cout << "Producto 3: " << p3 << endl;

                bool sonIguales = (p1 == p2); // <--------sobrecarga operador ==
                cout << "\nResultado de comparar p1 y p2 (==): " << (sonIguales ? "Son iguales" : "Son diferentes") << endl; //aquí va a decir que nop
                sonIguales = (p1 == p3);
                cout << "\nResultado de comparar p1 y p3 (==): " << (sonIguales ? "Son iguales" : "Son diferentes\n") << endl; //aquí va a decir que sipirili

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

