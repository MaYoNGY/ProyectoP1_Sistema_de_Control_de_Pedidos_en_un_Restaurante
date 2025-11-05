#ifndef MENU_H
#define MENU_H

#include "Plato.h"
using namespace std;

//Lista enlazada simple
struct NodoSimple{
	Plato dato;
	NodoSimple* siguiente;
	
		NodoSimple(Plato p){
			dato = p;
			siguiente = nullptr;
		}
};

class Menu{
	private:
		NodoSimple* cabeza;
	
	public:
		
		Menu();
		~Menu();

		void registrarPlato(NombrePlato nombre, CodigoPlato codigo, PrecioPlato precio, CategoriaPlato categoria, CantidadPlatos cantidad);
		bool buscarPlato(NombrePlato nombre);
		Plato* buscarPlatoCo(CodigoPlato codigo);
		void eliminarPlato();
		void mostrarMenu();
};


#endif
