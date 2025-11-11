#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include "Pedido.h"
#include "Validacion.h"
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
        NodoPedido* front;
        NodoPedido* rear;
        
        MenuRestaurante* m;
    	Validacion v;
        
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
        int getNumPedidoActual() const;
        void setNumPedidoActual(int num);
        
        void guardarCola(const string& nombreArchivo);
        void cargarCola(const string& nombreArchivo);
        
        

};

#endif
