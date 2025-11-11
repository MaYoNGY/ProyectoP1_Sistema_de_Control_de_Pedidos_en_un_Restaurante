#include "MenuRestaurante.h"
#include <iostream>
#include <fstream>
using namespace std;

MenuRestaurante::MenuRestaurante(){ 
    cabeza = nullptr;
    cola = nullptr;
}

MenuRestaurante::~MenuRestaurante(){ 
    while(cabeza){
        NodoDoble* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cola = nullptr;
}

void MenuRestaurante::registrarPlato(){ //Insercion desde el inicio
    
    NodoDoble* actual = cabeza;
    
    NombrePlato nombre;
	CodigoPlato codigo;
	PrecioPlato precio;
	CategoriaPlato categoria;
	CantidadPlatos cantidad;
	bool codigoRepetido;
    
    cout << endl;
	nombre = v.pedirNombrePlato();
    
    while(actual){
        if(actual->dato.getNombre() == nombre){
            cout << endl;
            cout << "El plato ya existe en el menu. Actualizando cantidad..." << endl;

            cantidad = v.pedirCantidadPlato();

            Plato adicional(nombre, actual->dato.getCodigo(), actual->dato.getPrecio(), actual->dato.getCategoria(), actual->dato.getCantidad() + cantidad);
            actual->dato = adicional;
            cout << "Cantidad actualizada..." << endl;
            return;
        }
        actual = actual->siguiente;
    }
    
    do{
	    codigoRepetido = false;
	
	    codigo = v.pedirCodigo();
	
	    NodoDoble* actual = cabeza;
	    while (actual) {
	        if (codigo == actual->dato.getCodigo()) {
	            cout << "Codigo ya usado en otro plato. Ingrese otro..." << endl;
	            codigoRepetido = true;
	            break;
	        }
	        actual = actual->siguiente;
	    }
	}while(codigoRepetido);
    	
	precio = v.pedirPrecio();
	
	categoria = v.pedirCategoria();

    cantidad = v.pedirCantidadPlato();

    Plato p(nombre, codigo, precio, categoria, cantidad);
    
    NodoDoble* nuevo = new NodoDoble(p);
    nuevo->siguiente = cabeza;
    nuevo->anterior = nullptr;
    if(cabeza)
    	cabeza->anterior = nuevo;
    else
    	cola = nuevo;
    cabeza = nuevo;
    cout << endl << "Plato registrado exitosamente!!" << endl;
}

NodoDoble* MenuRestaurante::buscarPlato(){ //Busqueda desde el inicio
	if(!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return nullptr;
    }
    
    NodoDoble* actual = cabeza;
    
    NombrePlato nombre;
    
    cout << endl;
	nombre = v.pedirNombrePlato();
    
    while(actual != nullptr){
        if(actual->dato.getNombre() == nombre){
            cout << endl;
            cout << "Plato (" << nombre << ") encontrado" << endl;
            cout << "Codigo: " << actual->dato.getCodigo() << endl;
            cout << "Precio: $" << actual->dato.getPrecio() << endl;
            cout << "Categoria: " << actual->dato.getCategoria() << endl;
            cout << "Cantidad: " << actual->dato.getCantidad() << endl;
            cout << "Disponible: " << (actual->dato.getDisponible() ? "Si" : "No") << endl;
            return actual;
        }
        actual = actual->siguiente;
    }
    cout << "Plato no encontrado en el menu!!" << endl;
    return nullptr;
}

Plato* MenuRestaurante::buscarPlatoCo(CodigoPlato codigo){ //Busqueda de codigo desde el inicio de la lista
    NodoDoble* actual = cabeza;
    
    while(actual){
        if(actual->dato.getCodigo() == codigo){
            return &actual->dato;
        }
        actual = actual->siguiente;
    }
    
    cout << "Plato no encontrado en el menu!!" << endl;
    return nullptr;
}

Plato* MenuRestaurante::buscarPlatoNombre(NombrePlato nombre){ //Busqueda de nombre desde el inicio de la lista
    NodoDoble* actual = cabeza;
    while(actual){
        if(actual->dato.getNombre() == nombre)
            return &(actual->dato);
        actual = actual->siguiente;
    }
    return nullptr;
}

void MenuRestaurante::eliminarPlatoAgotado(){ //Eliminacion de platoAgotado
	if(!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return;
    }
    NodoDoble* actual = cabeza;
	cout << endl;
    while(actual){
        if(!actual->dato.getDisponible()){
    		cout << "Eliminando plato agotado: " << actual->dato.getNombre() << " del menu..." << endl;

   			NodoDoble* eliminar = actual;

		    if(actual == cabeza){ //elimina cabeza
		        cabeza = actual->siguiente;
		        if(cabeza)
		            cabeza->anterior = nullptr;
		        else
		            cola = nullptr;
		        actual = cabeza;
		    }else if(actual->siguiente == nullptr){ //eliminar cola
		        cola = actual->anterior;
		        cola->siguiente = nullptr;
		        actual = nullptr;
		    }else{ //eliminar medio
		        actual->anterior->siguiente = actual->siguiente;
		        actual->siguiente->anterior = actual->anterior;
		        actual = actual->siguiente;
		    }
    		delete eliminar;
		}else{
            actual = actual->siguiente;
        }  
    }
}

void MenuRestaurante::eliminarPlato(){ //eliminar plato especifico
	if(!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return;
    }
    
	NodoDoble* actual = buscarPlato();
	
	if(actual == nullptr) return;
	
	cout << "Eliminando plato: " << actual->dato.getNombre() << " del menu..." << endl;
	
	if(actual == cabeza){ //elimina cabeza
		cabeza = cabeza->siguiente;
		if(cabeza != nullptr) cabeza->anterior = nullptr;
	}else if(actual==cola){ //elimina cola
		cola = cola->anterior;
		if(cola != nullptr) cola->siguiente = nullptr;
	}else{ //elimina medio
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
	}
	
	delete actual;
	
}

void MenuRestaurante::mostrarMenu(){ // mostrar menu desde el inicio
    if(!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return;
    }
	cout << "----------------- Menu -----------------" << endl;
    NodoDoble* actual = cabeza;
    while(actual){
        actual->dato.mostrarPlato();
        actual = actual->siguiente;
    }
    cout << "----------------------------------------" << endl;
}


void MenuRestaurante::contarPlatosPorCategoria(CategoriaPlato categoria){ //uso de la funcion recursiva para contar categorias
	if(!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return;
    }
    cout << "Platos en la categoria (" << categoria << "):" << endl;
    int cantidad = contarCategoriaRecursivo(cabeza, categoria);
     if (cantidad == 0)
        cout << "No se encontraron platos en esta categoria!!" << endl;
    else
        cout << "Total de platos encontrados: " << cantidad << endl;
}

void MenuRestaurante::compararPrecios(){ //comparacion con sobrecarga de operadores
	if(!cabeza){
        cout << "El menu esta vacio!!" << endl;
        return;
    }
	NombrePlato n1, n2;
	n1 = v.pedirNombrePlato();
	n2 = v.pedirNombrePlato();
	
	Plato* p1 = buscarPlatoNombre(n1);
	Plato* p2 = buscarPlatoNombre(n2);
	
	if(!p1 || !p2){
        cout << "Uno o ambos platos no existen en el menu!!" << endl;
        return;
    }

    if(*p1 > *p2){
        cout << "El plato " << p1->getNombre() << " tiene un precio mayor que " 
             << p2->getNombre() << "." << endl;
    }else if(*p1 < *p2){
        cout << "El plato " << p2->getNombre() << " tiene un precio mayor que " 
             << p1->getNombre() << "." << endl;
    }else{
        cout << "Ambos platos tienen el mismo precio." << endl;
    }
}

void MenuRestaurante::guardarMenu(const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if(!archivo){
        cout << "Error al abrir el archivo para guardar el menu." << endl;
        return;
    }
    
    int contador = 0;
    NodoDoble* temp = cabeza;
    while(temp){
        contador++;
        temp = temp->siguiente;
    }
    
    archivo << contador << endl;
    
    temp = cabeza;
    while(temp){
        temp->dato.guardarEnArchivo(archivo);
        temp = temp->siguiente;
    }
    
    archivo.close();
    cout << "Menu guardado exitosamente en (" << nombreArchivo << ")." << endl;
}

void MenuRestaurante::cargarMenu(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cout << "No se encontro archivo previo del menu. Iniciando con menu vacio." << endl;
        return;
    }
    
    // Limpiar menu actual
    while(cabeza){
        NodoDoble* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cabeza = nullptr;
    cola = nullptr;
    
    int contador;
    archivo >> contador;
    archivo.ignore();
    
    for(int i = 0; i < contador; i++){
        Plato p;
        p.cargarDesdeArchivo(archivo);
        
        NodoDoble* nuevo = new NodoDoble(p);
        nuevo->siguiente = cabeza;
        nuevo->anterior = nullptr;
        if(cabeza)
            cabeza->anterior = nuevo;
        else
            cola = nuevo;
        cabeza = nuevo;
    }
    
    archivo.close();
    cout << "Menu cargado exitosamente desde (" << nombreArchivo << ")." << endl;
}


