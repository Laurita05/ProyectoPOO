#include "Inventario.h"

Inventario::Inventario()
{
    //ctor
}
//------------------------------------> ¿Esta vacio el inventario? <------------------------------------
bool Inventario::inventarioVacio(){
    if (productos.empty()) {
        cout << "El inventario está vacío. Ingrese algún producto primero, por favor." << endl;
        return true;
    }
    return false;
}

//------------------------------------> Ingresar Productos <------------------------------------
void Inventario::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

//------------------------------------> Mostrar Todos los Productos <------------------------------------
void Inventario::mostrarProductos() {
    for (auto producto : productos) {
        producto->mostrarInfo();
        cout << "-----------------------------" << endl;
    }
}

//------------------------------------> Buscar un Producto <------------------------------------
void Inventario::buscarProducto(string nombre)
{
     for (auto producto : productos) {
        if (producto->getNombre() == nombre) {
            producto->mostrarInfo();
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

//------------------------------------> Eliminar Producto <------------------------------------
void Inventario::eliminarProducto(string nombre)
{
    char confirmacion;
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i]->getNombre() == nombre) {
            cout<<"¿Esta seguro de que desea eliminar este producto? (S = Si, N = No)\n";
            cin>>confirmacion;
            if(confirmacion=='S' || confirmacion=='s')
            {
                delete productos[i]; // Liberar la memoria del producto
                productos.erase(productos.begin() + i); // Eliminar el producto del vector
                cout << "Producto eliminado." << endl;
                return;
            }
            else{
                cout<<"Eliminación cancelada\n";
                return;
            }
        }
    }
    cout << "Producto no encontrado." << endl;
}
