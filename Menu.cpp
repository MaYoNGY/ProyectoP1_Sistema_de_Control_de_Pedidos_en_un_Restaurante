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

void Menu::registrarPlato(string nombre, int codigo, float precio, string categoria, bool disponible) {
    Plato p(nombre, codigo, precio, categoria, disponible);
    NodoSimple* nuevo = new NodoSimple(p);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    cout << endl << "Plato registrado exitosamente!!" << endl;
}

bool Menu::buscarPlato(string nombre) {
    NodoSimple* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato.getNombre() == nombre) {
            cout << "Plato [" << nombre << "] encontrado" << endl;
            cout << "Codigo: " << actual->dato.getCodigo() << endl;
            cout << "Precio: " << actual->dato.getPrecio() << endl;
            cout << "Categoria: " << actual->dato.getCategoria() << endl;
            cout << "Disponible: " << (actual->dato.getDisponible() ? "Si" : "No") << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    cout << "Plato no encontrado en el menu!!" << endl;
    return false;
}

void Menu::eliminarPlato() {
    while (cabeza && !cabeza->dato.getDisponible()) {
        NodoSimple* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    NodoSimple* actual = cabeza;
    while (actual && actual->siguiente) {
        if (!actual->siguiente->dato.getDisponible()) {
            NodoSimple* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
        } else {
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




