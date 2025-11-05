#ifndef MENUSISTEMA_H
#define MENUSISTEMA_H

#include "Menu.h"
#include "PedidosSistema.h"
using namespace std;

class MenuSistema{
	private:
		Menu m;
		Plato p;
		PedidosSistema ps{&m};
		
	public:
		void mostrarMenuRestaurante();
		void mostrarMenuSistema();
		void mostrarMenuPedidos();
		void ingresarPlatos();
		void buscarPlatos();
	
};


#endif
