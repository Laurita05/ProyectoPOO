#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Producto.h"
#include "Abarrotes.h"
#include "Alimento.h"
#include "Bebida.h"
#include <vector>
#include <iostream>
using namespace std;

class Inventario
{
    private:
        vector<Producto*> productos;
    public:
    Inventario();
    bool inventarioVacio(void);
    void agregarProducto(Producto*);
    void mostrarProductos(void);
    void buscarProducto(string);
    void eliminarProducto(string);
    ~Inventario(); // Destructor

};

#endif // INVENTARIO_H
