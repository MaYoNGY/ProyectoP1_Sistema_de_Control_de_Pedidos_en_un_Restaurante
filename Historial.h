#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "Pedido.h"

struct NodoPila{
	Pedido dato;
	NodoPila* siguiente;
	
	NodoPila(const Pedido& p){
		dato = p;
		siguiente = nullptr;
	}
};

class Historial{
	private:
		NodoPila* tope;
		
	public:
		Historial();
		bool pilaVacia();
		void apilarPedido(Pedido p);
		Pedido desapilarPedido();
		void mostrarHistorial();
		
		
};

#endif
