#include "MenuRestaurante.h"
#include <iostream>
using namespace std;

MenuRestaurante::MenuRestaurante(){ 
    cabeza = nullptr;
}

MenuRestaurante::~MenuRestaurante(){ 
    while(cabeza){
        NodoDoble* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void MenuRestaurante::registrarPlato(){ //Insercion desde el inicio
    
    NodoDoble* actual = cabeza;
    
    NombrePlato nombre;
	CodigoPlato codigo;
	PrecioPlato precio;
	CategoriaPlato categoria;
	CantidadPlatos cantidad;
    
    cout << endl;
	cin.ignore();
	cout << "Ingrese el nombre del plato: ";
	getline(cin, nombre);
    
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
    NodoDoble* nuevo = new NodoDoble(p);
    nuevo->siguiente = cabeza;
    nuevo->anterior = nullptr;
    if(cabeza)
    	cabeza->anterior = nuevo;
    cabeza = nuevo;
    cout << endl << "Plato registrado exitosamente!!" << endl;
}

bool MenuRestaurante::buscarPlato(){ //Busqueda desde el inicio
    NodoDoble* actual = cabeza;
    
    NombrePlato nombre;
    
    cout << endl;
	cin.ignore();
	cout << "Ingrese el nombre del plato: ";
	getline(cin, nombre);
    
    while(actual != nullptr){
        if(actual->dato.getNombre() == nombre){
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

Plato* MenuRestaurante::buscarPlatoCo(CodigoPlato codigo){
    NodoDoble* actual = cabeza;
    
    while(actual){
        if (actual->dato.getCodigo() == codigo){
            return &actual->dato;
        }
        actual = actual->siguiente;
    }
    
    cout << "Plato no encontrado en el menu!!" << endl;
    return nullptr;
}

void MenuRestaurante::eliminarPlato(){
    NodoDoble* actual = cabeza;

    while(actual){
        if (!actual->dato.getDisponible()){
            cout << "Eliminando plato agotado: " << actual->dato.getNombre() << endl;
    
            NodoDoble* eliminar = actual;
            
            if(actual == cabeza){ //Eliminar cabeza
                cabeza = actual->siguiente;
                if(cabeza)
                	cabeza->anterior = nullptr;
                actual = cabeza;
            }else{ //Eliminar intermedio o final
                actual->anterior->siguiente = actual->siguiente;
                if(actual->siguiente)
                	actual->siguiente->anterior = actual->anterior;
                actual = actual->siguiente;
            }
            delete eliminar;
        }else{
            actual = actual->siguiente;
        }  
    }

    cout << "Se eliminaron los platos que estaban agotados." << endl;
}

void MenuRestaurante::mostrarMenu(){ // mostrar menu desde el inicio
    if (!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return;
    }

    NodoDoble* actual = cabeza;
    cout << endl << "------ Menu -------" << endl;
    while(actual){
        actual->dato.mostrarPlato();
        actual = actual->siguiente;
    }
    cout << "---------------" << endl;
}




