#include "Inventario.h"

Inventario::Inventario()
{
    //ctor
}

void Inventario::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

void Inventario::mostrarProductos() {
    if (productos.empty()) {
        cout << "El inventario está vacío." << endl;
        return;
    }

    for (auto producto : productos) {
        producto->mostrarInfo();
        cout << "-----------------------------" << endl;
    }
}

void Inventario::buscarProducto(string nombre) {
     for (auto producto : productos) {
        if (producto->getNombre() == nombre) {
            producto->mostrarInfo();
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}
void Inventario::eliminarProducto(string nombre)
{
    int i;
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i]->getNombre() == nombre) {
            delete productos[i]; // Liberar la memoria del producto
            productos.erase(productos.begin() + i); // Eliminar el producto del vector
            cout << "Producto eliminado." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

Inventario::~Inventario()
{
    for (auto producto : productos)
    {
        delete producto;
    }
}
