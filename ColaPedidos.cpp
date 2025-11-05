#include "ColaPedidos.h"
#include <iostream>
using namespace std;

ColaPedidos::ColaPedidos(){
    frente = nullptr;
    final = nullptr;
    contador = 0;
}

ColaPedidos::~ColaPedidos(){
    while (!estaVacia()) {
        atenderPedido();
    }
}

bool ColaPedidos::estaVacia() const{
    return frente == nullptr;
}

void ColaPedidos::agregarPedido(const Pedidos& p){
    NodoPedido* nuevo = new NodoPedido(p);
    if (estaVacia()) {
        frente = final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    contador++;
    cout << "Pedido registrado exitosamente" << endl;
}

void ColaPedidos::atenderPedido(){
    if (estaVacia()) {
        cout << "No hay pedidos pendientes" << endl;
        return;
    }
    NodoPedido* temp = frente;
    cout << "Atendiendo pedido #" << frente->dato.getNumeroPedido() << endl;
    frente->dato.mostrarPedido();
    frente = frente->siguiente;
    delete temp;
    if (!frente) {
        final = nullptr;
    }

    contador--;
}

void ColaPedidos::mostrarPedidos() const{
    if (estaVacia()) {
        cout << "No hay pedidos en la cola." << endl;
        return;
    }

    cout << "----- Lista de pedidos en cola -----" << endl;
    NodoPedido* actual = frente;
    while (actual) {
        actual->dato.mostrarPedido();
        cout << "------------------------" << endl;
        actual = actual->siguiente;
    }
}


