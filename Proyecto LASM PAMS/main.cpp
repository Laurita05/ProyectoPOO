#include "Inventario.h"
#include "Producto.h"
#include "Abarrotes.h"
#include "Alimento.h"
#include "Bebida.h"
#include <iostream>
#include <cstdlib>
#include <locale>
#include <wchar.h>
#include <cmath>

using namespace std;

int main()
{
    string nombre,nombre2;
    float cant, resultado;
    setlocale(LC_ALL, "");//Esto es para que se pongan los acentos en todo :D
    Inventario inventario;//Declaración del objeto inventario, de la clase Inventario valga la redundancia
    char opcion, subOpcion, sobrecargaOpc;//Opciones para el switch del menú y de sub-menús

    Producto *p1;// prueba
    Producto *p2;// prueba
    Producto *p3;// prueba

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
            case '1': { // - - - -INGRESAR PRODUCTOS- - - -
                do{
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
                        case '1': {
                            cout<<"- - - - - -ALIMENTO- - - - - -"<<endl;
                            Alimento* alimento = new Alimento();
                            cin >> *alimento;
                            inventario.agregarProducto(alimento);
                            break;
                        }

                        case '2': {
                            cout<<"- - - - - -BEBIDA- - - - - -"<<endl;
                            Bebida* bebida = new Bebida();
                            cin >> *bebida;
                            inventario.agregarProducto(bebida);
                            break;
                        }

                        case '3': {
                            cout<<"- - - - - -ABARROTES- - - - - -"<<endl;
                            Abarrotes* abarrotes = new Abarrotes();
                            cin >> *abarrotes;
                            inventario.agregarProducto(abarrotes);
                            break;
                        }

                        case '4': {
                            cout<<"Saliendo al menú principal...\n";
                            break;
                        }
                        default: {
                            cout << "Opción inválida. Por favor, elige otra opción." << endl;
                            break;
                            }
                        }
                        system("PAUSE");
                    }while(subOpcion!='4');
                break;
            }// FIN DEL CASE 1

            case '2': {// - - - -BUSCAR UN PRODUCTO- - - -
                if (inventario.inventarioVacio()) {break;}
                cout << "Ingrese el nombre del producto a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                inventario.buscarProducto(nombre);
                break;
            }
            case '3': {// - - - -ELIMINAR PRODUCTOS- - - -
                if (inventario.inventarioVacio()) {break;}
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                inventario.eliminarProducto(nombre);
                break;
            }
            case '4': {// - - - -MOSTRAR PRODUCTOS- - - -
                if (inventario.inventarioVacio()) {break;}
                inventario.mostrarProductos();
                break;
            }
            case '5': {// - - - -Sobrecarguitas- - - -
                do{
                system("CLS");
                cout<<"¿Qué desea hacer?\n";
                cout<<"1. Checkout\n2. Poner oferta\n3. Comprobar si es igual el producto\n4. Volver al menú principal\n";
                cout<<"Elige una opción: ";
                cin>>sobrecargaOpc;
                switch(sobrecargaOpc){
                    case '1': { // - - - -CHECKOUT (sobre carga de... - - - -
                        if (inventario.inventarioVacio()){break;}
                        inventario.mostrarProductos();
                        cout<<"Ingrese de 1 a 3 productos: \n";
                        cin>>cant;
                        Producto *pAux;
                        if(cant==1){p1=inventario.seleccionarProducto();}
                        else if(cant==2){p1=inventario.seleccionarProducto();
                        p2=inventario.seleccionarProducto();}
                        else if(cant==3){p1=inventario.seleccionarProducto();
                        p2=inventario.seleccionarProducto();
                        p3=inventario.seleccionarProducto();}
                        *pAux=*p1+*p2+*p3;
                        cout<<"El resultado de su compra es: \n"<<*pAux<<endl;
                        break;
                    }
                    case '2': { // - - - -PONER OFERTA (sobrecarga de /)- - - -
                        if (inventario.inventarioVacio()) {break;}
                        inventario.mostrarProductos();
                        cout << "\nSelecciona el producto que tendrá oferta: \n";
                        p1 = inventario.seleccionarProducto();
                        cout<<"¿De cuánto es el descuento?\n";
                        cin >> cant ;
                        cout<<"¡¡OFERTA!!\nEl producto antes del descuento:\n"<<*p1<<endl;
                        if(cant==50){ *p1 = *p1 / 2;}
                        else{
                        resultado = p1->getPrecio() * (cant*0.01);
                        p1->setPrecio(p1->getPrecio() - resultado);
                        }
                        cout<<"El producto con descuento:\n"<< *p1 <<endl;
                        if(cant>100){cout<<"            Porfavor llevese el producto, le pagaremos\n";}
                        break;
                    }
                    case '3': { // - - - -¿SON IGUALES? (sobrecarga de == )- - - -
                        if (inventario.inventarioVacio()) {break;}
                        inventario.mostrarProductos();
                        cout << "\nPrimer producto\n";
                        p1 = inventario.seleccionarProducto();
                        cout << "\nSegundo producto\n";
                        p2 = inventario.seleccionarProducto();
                        bool sonIguales = (*p1 == *p2);
                        cout << "\nResultado de comparar "<<p1->getNombre()<<" y "<<p2->getNombre()<<" (==): " << (sonIguales ? "Son iguales" : "Son diferentes") << endl;
                        break;
                    }
                    case '4':
                        cout<<"Saliendo al menú principal...\n";
                        break;
                    default:
                        cout << "Opción inválida. Por favor, elige otra opción." << endl;
                        break;

                }
                    system("PAUSE");
                }while(sobrecargaOpc!='4');
                break;
            }//FIN DEL CASE 5
            case '6': {// - - - -SALIR- - - -
                cout << "¡Hasta luego ! :D " << endl;
                break;
            }
            default:
                cout << "Opción inválida. Por favor, elige otra opción." << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != '6');

    return 0;
}

