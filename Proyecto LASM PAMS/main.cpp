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
    setlocale(LC_ALL, "");//Esto es para que se pongan los acentos en todo :D
    Inventario inventario;//Declaraci�n del objeto inventario, de la clase Inventario valga la redundancia
    char opcion, subOpcion, sobrecargaOpc;//Opciones para el switch del men� y de sub-men�s

    Producto* manzana = new Producto("Manzana", "27/11/2024", 12.75, 100);
    Producto* pera = new Producto("Pera", "27/11/2024", 10.5, 88);
    Producto* banano = new Producto("Banano", "27/11/2024", 13, 100);
    inventario.agregarProducto(manzana);
    inventario.agregarProducto(pera);
    inventario.agregarProducto(banano);

    Producto *p1 = nullptr;// prueba
    Producto *p2 = nullptr;// prueba
    Producto *p3 = nullptr;// prueba
    string nombre,nombre2;
    float cant, resultado;

    do {
        system("CLS");
        cout<<"/ / / / / / / / / / / / / / / / / / / / / / / /"<<endl;
        cout<<"Laura Alejandra Santana Mart�nez"<<endl;
        cout<<"Pablo Artemio Medina Sahagun"<<endl;
        cout<<"Programaci�n Orientada a Objetos"<<endl;
        cout<<"/ / / / / / / / / / / / / / / / / / / / / / / /"<<endl;
        cout<<"      \nTienda de Abarrotes ''El Fierrote'' "<<endl;
        cout<<"- - - - - - - -Men� Principal- - - - - - - -"<<endl;
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto\n";
        cout << "3. Eliminar producto\n";
        cout << "4. Mostrar todos los productos\n";
        cout << "5. Extra(sobrecargas)\n";
        cout << "6. Salir\n";
        cout << "Elige una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case '1': { // - - - -INGRESAR PRODUCTOS- - - -
                do{
                    system("CLS");
                    cout<<"- - - - - - - -Men� de Ingreso- - - - - - - -"<<endl;
                    cout<<"Que tipo de producto desea ingresar?"<<endl;
                    cout << "1. Agregar alimento"<<endl;
                    cout << "2. Agregar bebida"<<endl;
                    cout << "3. Agregar abarrotes"<<endl;
                    cout << "4. Volver al men� principal"<<endl;
                    cout << "Elige una opci�n: ";
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
                            cout<<"Saliendo al men� principal...\n";
                            break;
                        }
                        default: {
                            cout << "Opci�n inv�lida. Por favor, elige otra opci�n." << endl;
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
                if (inventario.inventarioVacio()){break;}
                system("CLS");
                cout<<"�Qu� desea hacer?\n";
                cout<<"1. Checkout\n2. Poner oferta\n3. Comprobar si es igual el producto\n4. Volver al men� principal\n";
                cout<<"Elige una opci�n: ";
                cin>>sobrecargaOpc;
                switch(sobrecargaOpc){
                    case '1': { // - - - -CHECKOUT (sobre carga de +, * y =) - - - -
                        if (inventario.inventarioVacio()){break;}
                        int cuanto;
                        Producto *pAux=new Producto;
                        inventario.mostrarProductos();
                        cout<<"Ingrese de 1 a 3 productos: \n";
                        while(true){
                        cin>>cant;
                            if (cin.fail()||cant < 1 || cant > 3) {
                                cin.clear();
                                cin.ignore(100,'\n');
                                cout << "Debes ingresar un n�mero entre 1 y 3.\n";}
                            else{break;}
                        }

                        if(cant>=1){
                            p1=inventario.seleccionarProducto();
                            cout<<"�Cu�ntas unidades del producto llevar�?: ";
                            while(true){
                                cin>>cuanto;
                                if(cin.fail()||cuanto<0||p1->getStock()<cuanto){
                                    cin.clear();
                                    cin.ignore(100,'\n');
                                    cout<<"Ingrese una cantidad valida (si su cantidad es mayor a 0, verifique que no sea mayor al stock)\n";
                                }
                                else{break;}
                            }
                            p1->setStock(p1->getStock()-cuanto);
                            *pAux=(*p1)*(cuanto);

                            if(p1->getStock()-cuanto==0){
                                nombre=p1->getNombre();
                                inventario.seAcaboElProducto(nombre);
                            }
                        }
                        if(cant>=2){
                            p2=inventario.seleccionarProducto();
                            cout<<"�Cu�ntas unidades del producto llevar�?: ";
                            while(true){
                                cin>>cuanto;
                                if(cin.fail()||cuanto<0||p2->getStock()<cuanto){
                                    cin.clear();
                                    cin.ignore(100,'\n');
                                    cout<<"Ingrese una cantidad valida (si su cantidad es mayor a 0, verifique que no sea mayor al stock)\n";
                                }
                                else{break;}
                            }
                            p2->setStock(p2->getStock()-cuanto);
                            *pAux=(*pAux)+((*p2)*(cuanto));
                            if(p2->getStock()-cuanto==0){
                                nombre=p2->getNombre();
                                inventario.seAcaboElProducto(nombre);
                            }
                        }
                        if(cant>=3){
                            p3=inventario.seleccionarProducto();
                            cout<<"�Cu�ntas unidades del producto llevar�?: ";
                            while(true){
                                cin>>cuanto;
                                if(cin.fail()||cuanto<0||p3->getStock()<cuanto){
                                    cin.clear();
                                    cin.ignore(100,'\n');
                                    cout<<"Ingrese una cantidad valida (si su cantidad es mayor a 0, verifique que no sea mayor al stock)\n";
                                }
                                else{break;}
                            }
                            p3->setStock(p3->getStock()-cuanto);
                            *pAux=(*pAux)+((*p3)*(cuanto));

                            if(p3->getStock()-cuanto==0){
                                nombre=p3->getNombre();
                                inventario.seAcaboElProducto(nombre);
                            }
                        }
                        cout<<"El resultado de su compra es: \n"<<*pAux<<endl;

                        delete pAux;
                        break;
                    }
                    case '2': { // - - - -PONER OFERTA (sobrecarga de /)- - - -
                        if (inventario.inventarioVacio()) {break;}
                        inventario.mostrarProductos();
                        cout << "\nSelecciona el producto que tendr� oferta: \n";
                        p1 = inventario.seleccionarProducto();
                        cout<<"�De cu�nto es el descuento?\n";
                        cin >> cant ;
                        cout<<"��OFERTA!!\nEl producto antes del descuento:\n"<<*p1<<endl;
                        if(cant==50){ *p1 = *p1 / 2;}
                        else{
                        resultado = p1->getPrecio() * (cant*0.01);
                        p1->setPrecio(p1->getPrecio() - resultado);
                        }
                        cout<<"El producto con descuento:\n"<< *p1 <<endl;
                        if(cant>100){cout<<" Porfavor llevese el producto, le pagaremos\n";}
                        break;
                    }
                    case '3': { // - - - -�SON IGUALES? (sobrecarga de == )- - - -
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
                        cout<<"Saliendo al men� principal...\n";
                        break;
                    default:
                        cout << "Opci�n inv�lida. Por favor, elige otra opci�n." << endl;
                        break;

                }
                    system("PAUSE");
                }while(sobrecargaOpc!='4');
                break;
            }//FIN DEL CASE 5
            case '6': {// - - - -SALIR- - - -
                cout << "�Hasta luego ! :D " << endl;
                break;
            }
            default:
                cout << "Opci�n inv�lida. Por favor, elige otra opci�n." << endl;
                break;
        }
        system("PAUSE");
    } while (opcion != '6');

    return 0;
}

