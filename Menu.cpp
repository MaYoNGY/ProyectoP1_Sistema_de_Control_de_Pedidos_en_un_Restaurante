#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
    cabeza = nullptr;
}

Menu::~Menu() {
    while (cabeza) {
        NodoSimple* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void Menu::registrarPlato(NombrePlato nombre, CodigoPlato codigo, PrecioPlato precio, CategoriaPlato categoria, CantidadPlatos cantidad) {
    
    NodoSimple* actual = cabeza;
    while(actual){
        if(actual->dato.getNombre() == nombre){
            cout << endl;
            cout << "El plato ya existe en el menu. Actualizando cantidad..." << endl;

            cout << "Cuantos platos desea registrar?: ";
	        cin >> cantidad;

            Plato adicional(nombre, actual->dato.getCodigo(), actual->dato.getPrecio(), actual->dato.getCategoria(), actual->dato.getCantidad() + cantidad);
            actual->dato = adicional;
            cout << "Cantidad actualizada" << endl;
            return;
        }
        actual = actual->siguiente;
    }

    cout << "Ingrese el codigo del plato: ";
	cin >> codigo;
		
	cout << "Ingrese el precio del plato: ";
	cin >> precio;
	
	cin.ignore();
	
	cout << "Ingrese la categoria del plato: ";
	getline(cin, categoria); 

    cout << "Cuantos platos desea registrar?: ";
    cin >> cantidad;

    Plato p(nombre, codigo, precio, categoria, cantidad);
    NodoSimple* nuevo = new NodoSimple(p);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    cout << endl << "Plato registrado exitosamente!!" << endl;
}

bool Menu::buscarPlato(NombrePlato nombre) {
    NodoSimple* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato.getNombre() == nombre) {
            cout << endl;
            cout << "Plato [" << nombre << "] encontrado" << endl;
            cout << "Codigo: " << actual->dato.getCodigo() << endl;
            cout << "Precio: $" << actual->dato.getPrecio() << endl;
            cout << "Categoria: " << actual->dato.getCategoria() << endl;
            cout << "Cantidad: " << actual->dato.getCantidad() << endl;
            cout << "Disponible: " << (actual->dato.getDisponible() ? "Si" : "No") << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    cout << "Plato no encontrado en el menu!!" << endl;
    return false;
}

Plato* Menu::buscarPlatoCo(CodigoPlato codigo) {
    NodoSimple* actual = cabeza;
    while (actual) {
        if (actual->dato.getCodigo() == codigo) {
            return &actual->dato;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Menu::eliminarPlato() {
    NodoSimple* actual = cabeza;
    NodoSimple* anterior = nullptr;

    while (actual) {
        if (!actual->dato.getDisponible()) {
            cout << "Eliminando plato agotado: " << actual->dato.getNombre() << endl;
            if(actual == cabeza){
                cabeza = cabeza->siguiente;
                delete actual;
                actual = cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
                delete actual;
                actual = anterior->siguiente;
            }
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
        
    }

    cout << "Se eliminaron los platos que estaban agotados." << endl;
}

void Menu::mostrarMenu() {
    if (!cabeza) {
        cout << "El menu esta vacio!!" << endl;
        return;
    }

    NodoSimple* actual = cabeza;
    cout << endl << "----- Menu ------" << endl;
    while (actual != nullptr) {
        actual->dato.mostrarPlato();
        actual = actual->siguiente;
    }
}




