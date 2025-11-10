#include "Historial.h"
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

Historial::Historial(){
	tope = nullptr;
}

Historial::~Historial(){
    while(!pilaVacia()){
        desapilarPedido();
    }
}

bool Historial::pilaVacia(){
	return tope == nullptr;
}

void Historial::apilarPedido(Pedido p){
	NodoPila* nuevo = new NodoPila(p);
	nuevo->siguiente = tope;
	tope = nuevo;
	cout << "Pedido de " << p.getCliente() << " agregado al historial" << endl;	 
}

Pedido Historial::desapilarPedido(){
	if(pilaVacia()){
		cout << "Historial vacio" << endl;
		return Pedido();
	}else{
		NodoPila* temp = tope;
		Pedido p = temp->dato;
		tope = tope->siguiente;
		delete temp;
		cout << "Se deshizo la entrega del pedido de " << p.getCliente() << endl;
		return p;
	}
}

void Historial::mostrarHistorial(){
	if(pilaVacia()){
		cout << "Historial vacio" << endl;
		return;
	}
	cout << endl;
	cout << "----- Historial de pedidos entregados -----" << endl;
	NodoPila* aux = tope;
	while(aux != nullptr){
		aux->dato.mostrarPedido();
		cout << "-----------------------------------------" << endl;
		aux = aux->siguiente;
	}
}

double Historial::calcularIngresosRecursivo(){
    if(pilaVacia()){
        cout << "No hay pedidos entregados" << endl;
        return 0;
    }

    double total = sumarIngresos(tope);
    cout << "Ingresos totales por pedidos entregados: $" << total << endl;
    return total;
}

void Historial::guardarHistorial(const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if(!archivo){
        cout << "Error al abrir el archivo para guardar el historial." << endl;
        return;
    }
    
    // Contar elementos
    int contador = 0;
    NodoPila* temp = tope;
    while(temp){
        contador++;
        temp = temp->siguiente;
    }
    
    archivo << contador << endl;
    
    // Guardar en orden (del tope hacia abajo)
    temp = tope;
    while (temp){
        temp->dato.guardarEnArchivo(archivo);
        temp = temp->siguiente;
    }
    
    archivo.close();
    cout << "Historial guardado exitosamente en (" << nombreArchivo << ")." << endl;
}

void Historial::cargarHistorial(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cout << "No se encontro archivo previo del historial. Iniciando con historial vacio." << endl;
        return;
    }
    
    // Limpiar historial actual
    while(!pilaVacia()){
        NodoPila* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
    tope = nullptr;
    
    int contador;
    archivo >> contador;
    archivo.ignore();
    
    // Cargar pedidos en orden inverso para mantener el orden original de la pila
    stack<Pedido> tempStack;
    for(int i = 0; i < contador; i++){
        Pedido p;
        p.cargarDesdeArchivo(archivo);
        tempStack.push(p);
    }
    
    // Apilar en orden correcto
    while(!tempStack.empty()){
        Pedido p = tempStack.top();
        tempStack.pop();
        
        NodoPila* nuevo = new NodoPila(p);
        nuevo->siguiente = tope;
        tope = nuevo;
    }
    
    archivo.close();
    cout << "Historial cargado exitosamente desde (" << nombreArchivo << ")." << endl;
}
