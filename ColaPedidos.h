#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include "Pedido.h"
#include "MenuRestaurante.h"

using namespace std;

//Lista enlazada doble
struct NodoPedido{
    Pedido dato;
    NodoPedido* siguiente;
    NodoPedido* anterior;

    NodoPedido(const Pedido& p){
        dato = p;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

//Cola doble
class ColaPedidos{
	
    private:
    	MenuRestaurante* m;
        NodoPedido* front;
        NodoPedido* rear;
        int numPedidoActual;
        int contador;

    public:

        ColaPedidos();
        ColaPedidos(MenuRestaurante* menu);
        ~ColaPedidos();
        
        bool estaVacia() const;

        void agregarPedido(NombreCliente cliente); // enqueue
        void agregarPedido(const Pedido& p); // enqueue
        Pedido atenderPedido(); // dequeue
        bool cancelarPedido(NombreCliente cliente);
        void mostrarPedidos() const;
        float calcularIngresosEsperados() const;
        

};

#endif
