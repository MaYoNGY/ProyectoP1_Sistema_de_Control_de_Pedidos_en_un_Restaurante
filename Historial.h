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
		
	double sumarIngresos(NodoPila* nodo){
    	if(nodo == nullptr){
        return 0;
    	}
    	return nodo->dato.getTotal() + sumarIngresos(nodo->siguiente);
	}	
		
	public:
		Historial();
		~Historial();
		bool pilaVacia();
		void apilarPedido(Pedido p);
		Pedido desapilarPedido();
		void mostrarHistorial();
		double calcularIngresosRecursivo();
		
		void guardarHistorial(const string& nombreArchivo);
		void cargarHistorial(const string& nombreArchivo);
};

#endif
