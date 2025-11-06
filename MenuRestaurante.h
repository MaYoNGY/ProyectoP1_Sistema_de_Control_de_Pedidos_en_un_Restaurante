#ifndef MENURESTAURANTE_H
#define MENURESTAURANTE_H

#include "Plato.h"

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
	
	public:
		
		MenuRestaurante();
		~MenuRestaurante();

		void registrarPlato();
		bool buscarPlato();
		Plato* buscarPlatoCo(CodigoPlato codigo);
		void eliminarPlato();
		void mostrarMenu();
};


#endif
