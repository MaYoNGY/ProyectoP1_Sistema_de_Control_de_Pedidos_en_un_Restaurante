#ifndef MENURESTAURANTE_H
#define MENURESTAURANTE_H

#include "Plato.h"
#include <iostream>

//Lista enlazada doble
struct NodoDoble{
	Plato dato;
	NodoDoble* siguiente;
	NodoDoble* anterior;
	
		NodoDoble(const Plato& p){
			dato = p;
			siguiente = nullptr;
			anterior = nullptr;
		}
};

class MenuRestaurante{
	private:
		NodoDoble* cabeza;
		NodoDoble* cola;
		
		int contarCategoriaRecursivo(NodoDoble* nodo, CategoriaPlato categoriaBuscada) {
	    if (nodo == nullptr) {
	        return 0;
	    }
	    if (nodo->dato.getCategoria() == categoriaBuscada) {
	    	cout << "Plato: " << nodo->dato.getNombre() << endl;
	    	cout << "Precio: $" << nodo->dato.getPrecio() << endl;
	        return 1 + contarCategoriaRecursivo(nodo->siguiente, categoriaBuscada);
	    } else {
	        return contarCategoriaRecursivo(nodo->siguiente, categoriaBuscada);
	    }
}
	
	public:
		
		MenuRestaurante();
		~MenuRestaurante();

		void registrarPlato();
		NodoDoble* buscarPlato();
		Plato* buscarPlatoCo(CodigoPlato codigo);
		Plato* buscarPlatoNombre(NombrePlato nombre);
		void eliminarPlatoAgotado();
		void eliminarPlato();
		void mostrarMenu();
		void contarPlatosPorCategoria(CategoriaPlato categoria);
		void compararPrecios();
};


#endif
