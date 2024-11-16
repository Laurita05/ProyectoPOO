#include "Inventario.h"
#include "Producto.h"
#include "Abarrotes.h"
#include "Alimento.h"
#include "Bebida.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    cout<<"Laura Alejandra Santana Martínez"<<endl;
    cout<<"Pablo Artemio Medina Sahagun"<<endl;
    cout<<"Programación Orientada a Objetos"<<endl;
    cout<<"Tienda de Abarrotes ''El Fierrote'' "<<endl;
    //Lo siguiente esta todo mal hecho y ocupa mucho perfeccionarse y arreglarse, pero lo haré mañana o luego porque estoy cansada pero queria poner la idea
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
     Inventario inventario;
    int opcion;

    do {
        cout << "1. Agregar producto\n";
        cout << "2. Agregar abarrotes\n";
        cout << "3. Agregar alimento\n";
        cout << "4. Agregar bebida\n";
        cout << "5. Buscar producto\n";
        cout << "6. Eliminar producto\n";
        cout << "7. Mostrar todos los productos\n";
        cout << "8. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Producto* producto = new Producto();
                cin >> *producto;
                inventario.agregarProducto(producto);
                break;
            }
            case 2: {
                Abarrotes* abarrotes = new Abarrotes();
                cin >> *abarrotes;
                inventario.agregarProducto(abarrotes);
                break;
            }
            case 3: {
                Alimento* alimento = new Alimento();
                cin >> *alimento;
                inventario.agregarProducto(alimento);
                break;
            }
            case 4: {
                Bebida* bebida = new Bebida();
                cin >> *bebida;
                inventario.agregarProducto(bebida);
                break;
            }
            case 5: {
                string nombre;
                cout << "Ingrese el nombre del producto a buscar: ";
                cin >> nombre;
                inventario.buscarProducto(nombre);
                break;
            }
            case 6: {
                string nombre;
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin >> nombre;
                inventario.eliminarProducto(nombre);
                break;
            }
            case 7: {
                inventario.mostrarProductos();
                break;
            }
            case 8: {
                cout << "¡Hasta luego!" << endl;
                break;
            }
            default:
                cout << "Opción inválida. Por favor, elige otra opción." << endl;
                break;
        }
    } while (opcion != 8);
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
    return 0;
}

