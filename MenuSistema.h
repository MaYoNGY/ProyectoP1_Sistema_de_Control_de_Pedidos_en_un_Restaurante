#ifndef MENUSISTEMA_H
#define MENUSISTEMA_H

#include "ColaPedidos.h"
#include "Historial.h"
#include "Validacion.h"
using namespace std;

class MenuSistema{
	private:
		MenuRestaurante m;
		ColaPedidos c;
		Historial h;
		
	public:
		MenuSistema();
		~MenuSistema();
		void mostrarMenuRestaurante();
		void mostrarMenuPedidos();
		void mostrarMenuHistorial();
		void mostrarMenuSistema();
		
		void cargarDatos();
		void guardarDatos();
	
};


#endif
