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
		
		void registrarPlato(string nombre, int codigo, float precio, string categoria, bool disponible);
		bool buscarPlato(string nombre);
		void eliminarPlato();
		void mostrarMenu();
};


#endif
