#include "Historial.h"
#include <iostream>
using namespace std;

Historial::Historial(){
	tope = nullptr;
}

bool Historial::pilaVacia(){
	return tope == nullptr;
}

void Historial::apilarPedido(Pedido p){
	NodoPila* nuevo = new NodoPila(p);
	nuevo->siguiente = tope;
	tope = nuevo;
	cout << "Pedido de " << p.getCliente() << "agregado al historial" << endl;	 
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
	
	cout << "----- Historial de pedidos entregados -----" << endl;
	NodoPila* aux = tope;
	while(aux != nullptr){
		aux->dato.mostrarPedido();
		cout << "-----------------------------------------" << endl;
		aux = aux->siguiente;
	}
}
