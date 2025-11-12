#include "MenuSistema.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

MenuSistema::MenuSistema(): m(), c(&m), h(){
	cargarDatos();
}

MenuSistema::~MenuSistema() {
	guardarDatos();
}

void MenuSistema::cargarDatos() {
	cout << "----- Cargando datos del sistema -----" << endl;
	m.cargarMenu("menu.txt");
	c.cargarCola("pedidos.txt");
	h.cargarHistorial("historial.txt");
	cout << "---------------------------------------" << endl;
	cout << endl;
}

void MenuSistema::guardarDatos() {
	cout << endl;
	cout << "----- Guardando datos del sistema -----" << endl;
	m.guardarMenu("menu.txt");
	c.guardarCola("pedidos.txt");
	h.guardarHistorial("historial.txt");
	cout << "---------------------------------------" << endl;
}

void MenuSistema::mostrarMenuRestaurante(){
	unsigned int opcMR;
	do{
		system("cls");
		cout << endl;
		cout << "=============================================" << endl;
		cout << "|             GESTION DEL MENU              |" << endl;
		cout << "=============================================" << endl;
		cout << "|  1. Registro de platos                    |" << endl;
		cout << "|  2. Busqueda de platos                    |" << endl;
		cout << "|  3. Eliminacion de platos agotados        |" << endl;
		cout << "|  4. Eliminar plato del menu 	            |" << endl;
		cout << "|  5. Mostrar Menu                          |" << endl;
		cout << "|  6. Buscar categoria                      |" << endl;
		cout << "|  7. Comparar precios                      |" << endl;
		cout << "|  8. Regresar                              |" << endl;
		cout << "=============================================" << endl;
		opcMR = Validacion::pedirOpc();
		
		system("cls");
		switch(opcMR){
			case 1:
				cout << "---------- Registro de plato ----------" << endl;
				m.registrarPlato();
				system("pause");
				break;
				
			
			case 2:
				cout << "---------- Busqueda de plato ----------" << endl;
				m.buscarPlato();
				system("pause");
				break;
			
				
			case 3:
				cout << "----- Eliminacion de plato agotado -----" << endl;
				m.eliminarPlatoAgotado();
				system("pause");
				break;
			
			case 4:
				cout << "--------- Eliminacion de plato ---------" << endl;
				m.eliminarPlato();
				system("pause");
				break;
				
			case 5:
				m.mostrarMenu();
				system("pause");
				break;
				
			case 6:{
				cout << "-------- Busqueda por categoria --------" << endl;
				CategoriaPlato categoria;
				categoria = Validacion::pedirCategoria();
				m.contarPlatosPorCategoria(categoria);
				system("pause");
				break;
			}
			
			case 7:{
				cout << "-------- Comparacion de precios --------" << endl;
				m.compararPrecios();
				system("pause");
				break;
			}
			
			case 8:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				system("pause");
				
		}
		
	}while(opcMR != 8);
}

void MenuSistema::mostrarMenuPedidos(){
	unsigned int opcMP;
	do{
		system("cls");
		cout << endl;
		cout << "=============================================" << endl;
		cout << "|            GESTION DE PEDIDOS             |" << endl;
		cout << "=============================================" << endl;
		cout << "|  1. Realizar pedido                       |" << endl;
		cout << "|  2. Atender pedido                        |" << endl;
		cout << "|  3. Mostrar pedidos pendientes            |" << endl;
		cout << "|  4. Cancelar pedido                       |" << endl;
		cout << "|  5. Regresar                              |" << endl;
		cout << "=============================================" << endl;
		opcMP = Validacion::pedirOpc();
		system("cls");
		
		switch(opcMP){
			case 1:{
				cout << "---------- Registro de pedido ----------" << endl;
				NombreCliente cliente;
				cliente = Validacion::pedirNombreCliente();
				c.agregarPedido(cliente);
				system("pause");
				break;
			}
				
			case 2:{
				cout << "---------- Atencion de pedido ----------" << endl;
				if(!c.estaVacia()){
					Pedido entregado = c.atenderPedido();
					h.apilarPedido(entregado);
				}else{
					cout << "No hay pedidos pendientes" << endl;
				}
				system("pause");
				break;
			}
					
			case 3:
				cout << "---------- Pedidos en la cola ----------" << endl;
				c.mostrarPedidos();
				system("pause");
				break;
			
			case 4:{
				cout << "-------- Cancelacion de pedido --------" << endl;
				NombreCliente cliente;
				cliente = Validacion::pedirNombreCliente();
				c.cancelarPedido(cliente);
				system("pause");
				break;
			}
				
			case 5:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				system("pause");
				
		}
		
	}while(opcMP != 5);
}

void MenuSistema::mostrarMenuHistorial(){
	unsigned int opcMH;
	do{
		system("cls");
		cout << endl;
		cout << "=============================================" << endl;
		cout << "|            HISTORIAL DE ENTREGAS          |" << endl;
		cout << "=============================================" << endl;
		cout << "|  1. Mostrar Historial                     |" << endl;
		cout << "|  2. Deshacer ultima entrega               |" << endl;
		cout << "|  3. Regresar                              |" << endl;
		cout << "=============================================" << endl;
		opcMH = Validacion::pedirOpc();
		system("cls");
		
		switch(opcMH){
			case 1:
				cout << "---- Historial de pedidos entregados ----" << endl;
				h.mostrarHistorial();
				h.calcularIngresosRecursivo();
				system("pause");
				break;
			
			case 2:{
				cout << "---- Deshacer ultimo pedido entregado ----" << endl;
				Pedido ultimo = h.desapilarPedido();
				if (!ultimo.getCliente().empty()) {
    				c.agregarPedido(ultimo);
				}
				system("pause");				
				break;
			}
			
			case 3:
				cout << "Regresando al menu principal..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				system("pause");
				
		}
		
	}while(opcMH != 3);
}

void MenuSistema::mostrarMenuSistema(){
	unsigned int opcMs;
	do{
		system("cls");
		cout << endl;
		cout << "=============================================" << endl;
		cout << "| SISTEMA DE CONTROL DE PEDIDOS-RESTAURANTE |" << endl;
		cout << "=============================================" << endl;
		cout << "|  1. Gestion del menu                      |" << endl;
		cout << "|  2. Gestion de pedidos                    |" << endl;
		cout << "|  3. Historial de entregas                 |" << endl;
		cout << "|  4. Salir del programa                    |" << endl;
		cout << "=============================================" << endl;
		opcMs = Validacion::pedirOpc();
		system("cls");
		
		switch(opcMs){
			case 1:
				mostrarMenuRestaurante();
				system("pause");
				break;
				
			case 2:
				mostrarMenuPedidos();
				system("pause");
				break;
				
			case 3:
				mostrarMenuHistorial();
				system("pause");
				break;
			
			case 4:
				cout << "Saliendo del sistema..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				system("pause");
				
		}
		
	}while(opcMs != 4);
}

