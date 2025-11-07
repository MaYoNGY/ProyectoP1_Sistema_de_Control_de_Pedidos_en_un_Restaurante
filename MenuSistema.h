#ifndef MENUSISTEMA_H
#define MENUSISTEMA_H

#include "ColaPedidos.h"
#include "Historial.h"
using namespace std;

class MenuSistema{
	private:
		MenuRestaurante m;
		Plato p;
		ColaPedidos c;
		Historial h;
		
	public:
		MenuSistema();
		void mostrarMenuRestaurante();
		void mostrarMenuPedidos();
		void mostrarMenuHistorial();
		void mostrarMenuSistema();
	
};


#endif
