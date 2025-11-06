#include "ColaPedidos.h"
#include <iostream>

using namespace std;

ColaPedidos::ColaPedidos(){
    front = nullptr;
    rear = nullptr;
    contador = 0;
    numPedidoActual = 1;
}

ColaPedidos::ColaPedidos(MenuRestaurante* menu) {
    m = menu;
    front = rear = nullptr;
    numPedidoActual = 1;
    contador = 0;
}

ColaPedidos::~ColaPedidos(){
    while (!estaVacia()){
        atenderPedido();
    }
}

bool ColaPedidos::estaVacia() const{
    return front == nullptr;
}

void ColaPedidos::agregarPedido(){ //Insertar en el fondo
	
	CodigoPlato codigo;
	CantidadPlatosPedidos cantidad;
	NombreCliente cliente;
	
	cin.ignore();
    cout << "Ingrese su nombre: ";
    getline(cin, cliente);

    cout << "Ingrese el codigo del plato que desea pedir: ";
    cin >> codigo;
	
    Plato* p = m->buscarPlatoCo(codigo);
    
    if(!p){
    	cout << "Plato no existe en el menu!!" << endl;
    	return;
	}
	
	cout << "Cuantos platos desea pedir?: ";
	cin >> cantidad;
	
	if(cantidad > p->getCantidad()){
        cout << "No hay suficientes platos disponibles, solo quedan " << p->getCantidad() << endl;
        return;
    }

    p->setCantidad(p->getCantidad() - cantidad);

    TotalPagar total = p->getPrecio() * cantidad;

    Pedido pe(numPedidoActual++, p->getNombre(), cliente, cantidad, total);
	
    NodoPedido* nuevo = new NodoPedido(pe);
    if(estaVacia()){
        front = rear = nuevo;
    }else{
        rear->siguiente = nuevo;
        nuevo->anterior = rear;
        rear = nuevo;
    }
    contador++;
    cout << "Pedido registrado exitosamente" << endl;
}

void ColaPedidos::atenderPedido(){
    if(estaVacia()){
    	cout << "No hay pedidos pendientes" << endl;
        return;
    }
    NodoPedido* temp = front;
    cout << "Atendiendo pedido #" << temp->dato.getNumeroPedido() << endl;
    front->dato.mostrarPedido();
    front = front->siguiente;
    
    if(front){
        front->anterior = nullptr;
    }else{
    	rear = nullptr;
	}
	
	delete temp;
    contador--;
}

void ColaPedidos::mostrarPedidos() const{
    if(estaVacia()){
        cout << "No hay pedidos en la cola." << endl;
        return;
    }

    cout << "----- Lista de pedidos en cola -----" << endl;
    NodoPedido* actual = front;
    while(actual){
        actual->dato.mostrarPedido();
        cout << "------------------------" << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

