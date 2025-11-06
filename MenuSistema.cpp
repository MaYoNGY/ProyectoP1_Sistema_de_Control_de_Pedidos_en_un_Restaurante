#include "MenuSistema.h"
#include <iostream>
#include <string>
using namespace std;

MenuSistema::MenuSistema(): m(), p(), c(&m){}

void MenuSistema::mostrarMenuRestaurante(){
	int opc;
	do{
		cout << endl;
		cout << "----- Menu del restaurante -----" << endl;
		cout << "1. Ingreso de platos" << endl;
		cout << "2. Busqueda de platos" << endl;
		cout << "3. Eliminacion de platos agotados" << endl;
		cout << "4. Mostrar Menu" << endl;
		cout << "5. Regresar el menu principal" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				m.registrarPlato();
				break;
				
			
			case 2:
				m.buscarPlato();
				break;
			
				
			case 3:
				m.eliminarPlato();
				break;
			
				
			case 4:
				m.mostrarMenu();
				break;
			
				
			case 5:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opc != 5);
}

void MenuSistema::mostrarMenuPedidos(){
	int opc;
	do{
		cout << endl;
		cout << "----- Menu de Pedidos -----" << endl;
		cout << "1. Realizar pedido" << endl;
		cout << "2. Atender pedido" << endl;
		cout << "3. Mostrar pedidos pendientes" << endl;
		cout << "4. Regresar al menu principal" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				c.agregarPedido();
				break;
			
				
			case 2:
				c.atenderPedido();
				break;
			

			case 3:
				c.mostrarPedidos();
				break;
			

			case 4:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opc != 4);
}


void MenuSistema::mostrarMenuSistema(){
	int opc;
	do{
		cout << endl;
		cout << "----- Menu del sistema de restaurante -----" << endl;
		cout << "1. Menu" << endl;
		cout << "2. Pedidos" << endl;
		cout << "3. Historial" << endl;
		cout << "4. Salir del programa" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				mostrarMenuRestaurante();
				break;
			
				
			case 2:
				mostrarMenuPedidos();
				break;
			
				break;
				
			case 3:
				cout << "Opcion no implementada aun..." << endl;
				break;
			
			case 4:
				cout << "Saliendo del sistema..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opc != 4);
}
