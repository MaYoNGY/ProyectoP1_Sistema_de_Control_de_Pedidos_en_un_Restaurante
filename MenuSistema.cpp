#include "MenuSistema.h"
#include <iostream>
#include <string>
using namespace std;

void MenuSistema::ingresarPlatos(){
	string nombre, categoria;
	int codigo;
	float precio;
		
	cin.ignore();
		
	cout << "Ingrese el nombre del plato: ";
	getline(cin, nombre);
		
	cout << "Ingrese el codigo del plato: ";
	cin >> codigo;
		
	cout << "Ingrese el precio del plato: ";
	cin >> precio;
	
	cin.ignore();
	
	cout << "Ingrese la categoria del plato: ";
	getline(cin, categoria); 
		
	m.registrarPlato(nombre, codigo, precio, categoria, true);
}

void MenuSistema::mostrarMenuSistema(){
	do{
		cout << "----- Menu del sistema -----" << endl;
		cout << "1. Ingreso de platos" << endl;
		cout << "2. Busqueda de platos" << endl;
		cout << "3. Eliminacion de platos agotados" << endl;
		cout << "4. Mostrar Menu" << endl;
		cout << "5. Salir del programa" << endl;
		cout << "Ingrese la opcion que desee: ";
		cin >> opc;
		
		switch(opc){
			case 1:
				ingresarPlatos();
				break;
			
			case 2:{
				string nombre;
				
				cin.ignore();
				
				cout << "Ingrese el nombre del plato que desea buscar: ";
				getline(cin, nombre);
				
				m.buscarPlato(nombre);
				break;
			}
				
			case 3:{
				cout << "Opcion no implementada aun..." << endl;
				break;
			}
				
			case 4:{
				m.mostrarMenu();
				break;
			}
				
			case 5:
				cout << "Saliendo del sistema..." << endl;
				break;	
				
			default:
				cout << "Opcion no valida!!! Intente nuevamente..." << endl;
				
		}
		
	}while(opc != 5);
}
