#include "PedidosSistema.h"
#include <iostream>
using namespace std;

PedidosSistema::PedidosSistema(Menu* menu) {
    m = menu;
    numeroPedidoActual = 1;
}

void PedidosSistema::realizarPedido() {
    CodigoPlato codigo;
    CantidadPlatosPedidos cantidad;
    NombreCliente cliente;

    cin.ignore();
    cout << "Ingrese su nombre: ";
    getline(cin, cliente);

    cout << "Ingrese el codigo del plato que desea pedir: ";
    cin >> codigo;

    Plato* p = m->buscarPlatoCo(codigo);

    if(!p){
        cout << "Plato no encontrado en el menu." << endl;
        return;
    }

    cout << "Cuantos platos desea pedir?: ";
    cin >> cantidad;

    if(cantidad > p->getCantidad()){
        cout << "No hay suficientes platos disponibles, solo quedan " << p->getCantidad() << endl;
        return;
    }

    p->setCantidad(p->getCantidad() - cantidad);

    TotalPagar total = p->getPrecio() * cantidad;

    Pedidos nuevo(numeroPedidoActual++, p->getNombre(), cliente, cantidad, total);
    cola.agregarPedido(nuevo);

}

void PedidosSistema::atenderPedido() {
    cola.atenderPedido();
}

void PedidosSistema::mostrarPedidos() {
    cola.mostrarPedidos();
}