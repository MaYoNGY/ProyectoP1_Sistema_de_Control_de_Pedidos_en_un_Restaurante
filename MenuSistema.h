#ifndef MENUSISTEMA_H
#define MENUSISTEMA_H

#include "ColaPedidos.h"
using namespace std;

class MenuSistema{
	private:
		MenuRestaurante m;
		Plato p;
		ColaPedidos c;
		
	public:
		MenuSistema();
		void mostrarMenuRestaurante();
		void mostrarMenuSistema();
		void mostrarMenuPedidos();
	
};


#endif
