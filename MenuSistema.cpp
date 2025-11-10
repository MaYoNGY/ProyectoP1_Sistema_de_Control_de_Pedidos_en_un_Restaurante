#include "MenuSistema.h"
#include <iostream>
#include <string>
using namespace std;

MenuSistema::MenuSistema(): m(), c(&m), h(){}

void MenuSistema::mostrarMenuRestaurante(){
	int opcMR;
	do{
		cout << endl;
		cout << "----- Menu del restaurante -----" << endl;
		cout << "1. Ingreso de platos" << endl;
		cout << "2. Busqueda de platos" << endl;
		cout << "3. Eliminacion de platos agotados" << endl;
		cout << "4. Eliminar plato del menu" << endl;
		cout << "5. Mostrar Menu" << endl;
		cout << "6. Buscar categoria" << endl;
		cout << "7. Comparar precios" << endl;
		cout << "8. Regresar el menu principal" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opcMR;
		
		switch(opcMR){
			case 1:
				m.registrarPlato();
				break;
				
			
			case 2:
				m.buscarPlato();
				break;
			
				
			case 3:
				m.eliminarPlatoAgotado();
				break;
			
			case 4:
				m.eliminarPlato();
				break;
				
			case 5:
				m.mostrarMenu();
				break;
				
			case 6:{
				CategoriaPlato categoria;
				cout << "Ingrese la categoria que desea buscar: ";
				cin >> categoria;
				m.contarPlatosPorCategoria(categoria);
				break;
			}
			
			case 7:{
				m.compararPrecios();
				break;
			}
			
			case 8:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opcMR != 8);
}

void MenuSistema::mostrarMenuPedidos(){
	int opcMP;
	do{
		cout << endl;
		cout << "----- Menu de Pedidos -----" << endl;
		cout << "1. Realizar pedido" << endl;
		cout << "2. Atender pedido" << endl;
		cout << "3. Mostrar pedidos pendientes" << endl;
		cout << "4. Cancelar pedido" << endl;
		cout << "5. Regresar al menu principal" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opcMP;
		
		switch(opcMP){
			case 1:{
				NombreCliente cliente;
				cin.ignore();
    			cout << "Ingrese su nombre: ";
    			getline(cin, cliente);
				c.agregarPedido(cliente);
				break;
			}
				
			case 2:{
				if(!c.estaVacia()){
					Pedido entregado = c.atenderPedido();
					h.apilarPedido(entregado);
				}else{
					cout << "No hay pedidos pendientes" << endl;
				}
				break;
			}
					
			case 3:
				c.mostrarPedidos();
				break;
			
			case 4:{
				NombreCliente cliente;
				cin.ignore();
    			cout << "Ingrese su nombre: ";
    			getline(cin, cliente);
				c.cancelarPedido(cliente);
				break;
			}
				
			case 5:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opcMP != 5);
}

void MenuSistema::mostrarMenuHistorial(){
	int opcMH;
	do{
		cout << endl;
		cout << "----- Menu del historial -----" << endl;
		cout << "1. Mostrar Historial" << endl;
		cout << "2. Desasher ultimo pedido" << endl;
		cout << "3. Regresar al menu principal" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opcMH;
		
		switch(opcMH){
			case 1:
				h.mostrarHistorial();
				h.calcularIngresosRecursivo();
				break;
			
			case 2:{
				Pedido ultimo = h.desapilarPedido();
				if (!ultimo.getCliente().empty()) {
    				c.agregarPedido(ultimo);
				}				
				break;
			}
			
			case 3:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opcMH != 3);
}

void MenuSistema::mostrarMenuSistema(){
	int opcMs;
	do{
		cout << endl;
		cout << "----- Menu del sistema de restaurante -----" << endl;
		cout << "1. Menu" << endl;
		cout << "2. Pedidos" << endl;
		cout << "3. Historial" << endl;
		cout << "4. Salir del programa" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opcMs;
		
		switch(opcMs){
			case 1:
				mostrarMenuRestaurante();
				break;
				
			case 2:
				mostrarMenuPedidos();
				break;
				
			case 3:
				mostrarMenuHistorial();
				break;
			
			case 4:
				cout << "Saliendo del sistema..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opcMs != 4);
}

