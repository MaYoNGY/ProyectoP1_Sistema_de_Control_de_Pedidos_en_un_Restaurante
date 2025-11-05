#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include "Pedidos.h"

using namespace std;

//Cola enlazada simple
struct NodoPedido{
    Pedidos dato;
    NodoPedido* siguiente;

    NodoPedido(Pedidos p){
        dato = p;
        siguiente = nullptr;
    }
};

class ColaPedidos{
    private:
        NodoPedido* frente;
        NodoPedido* final;
        int contador;

    public:

        ColaPedidos();
        ~ColaPedidos();

        void agregarPedido(const Pedidos& p); // enqueue
        void atenderPedido(); // dequeue
        void mostrarPedidos() const;
        bool estaVacia() const;

};

#endif