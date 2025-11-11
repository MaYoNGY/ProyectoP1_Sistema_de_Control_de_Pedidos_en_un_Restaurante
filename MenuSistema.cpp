#include "MenuSistema.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

MenuSistema::MenuSistema(): m(), c(&m), v(), h(){
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
		cout << "----- Menu del restaurante -----" << endl;
		cout << "1. Ingreso de platos" << endl;
		cout << "2. Busqueda de platos" << endl;
		cout << "3. Eliminacion de platos agotados" << endl;
		cout << "4. Eliminar plato del menu" << endl;
		cout << "5. Mostrar Menu" << endl;
		cout << "6. Buscar categoria" << endl;
		cout << "7. Comparar precios" << endl;
		cout << "8. Regresar el menu principal" << endl;
		opcMR = v.pedirOpc();
		
		system("cls");
		switch(opcMR){
			case 1:
				m.registrarPlato();
				system("pause");
				break;
				
			
			case 2:
				m.buscarPlato();
				system("pause");
				break;
			
				
			case 3:
				m.eliminarPlatoAgotado();
				system("pause");
				break;
			
			case 4:
				m.eliminarPlato();
				system("pause");
				break;
				
			case 5:
				m.mostrarMenu();
				system("pause");
				break;
				
			case 6:{
				CategoriaPlato categoria;
				categoria = v.pedirCategoria();
				m.contarPlatosPorCategoria(categoria);
				system("pause");
				break;
			}
			
			case 7:{
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
		cout << "----- Menu de Pedidos -----" << endl;
		cout << "1. Realizar pedido" << endl;
		cout << "2. Atender pedido" << endl;
		cout << "3. Mostrar pedidos pendientes" << endl;
		cout << "4. Cancelar pedido" << endl;
		cout << "5. Regresar al menu principal" << endl;
		opcMP = v.pedirOpc();
		system("cls");
		
		switch(opcMP){
			case 1:{
				NombreCliente cliente;
				cliente = v.pedirNombreCliente();
				c.agregarPedido(cliente);
				system("pause");
				break;
			}
				
			case 2:{
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
				c.mostrarPedidos();
				system("pause");
				break;
			
			case 4:{
				NombreCliente cliente;
				cliente = v.pedirNombreCliente();
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
		cout << "----- Menu del historial -----" << endl;
		cout << "1. Mostrar Historial" << endl;
		cout << "2. Desasher ultimo pedido" << endl;
		cout << "3. Regresar al menu principal" << endl;
		opcMH = v.pedirOpc();
		system("cls");
		
		switch(opcMH){
			case 1:
				h.mostrarHistorial();
				h.calcularIngresosRecursivo();
				system("pause");
				break;
			
			case 2:{
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
		cout << "----- Menu del sistema de restaurante -----" << endl;
		cout << "1. Menu" << endl;
		cout << "2. Pedidos" << endl;
		cout << "3. Historial" << endl;
		cout << "4. Salir del programa" << endl;
		opcMs = v.pedirOpc();
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

