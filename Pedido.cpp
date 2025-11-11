#include "Pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido(){
    numPedido = 0;
    cliente = "";
    total = 0.0;
}

Pedido::Pedido(NumeroPedido numP, NombreCliente cli){
    numPedido = numP;
    cliente = cli;
    total = 0.0;
}

NumeroPedido Pedido::getNumeroPedido() const{
    return numPedido;
}

void Pedido::setNumeroPedido(NumeroPedido numP){
    numPedido = numP;
}

NombreCliente Pedido::getCliente() const{
    return cliente;
}

void Pedido::setCliente(NombreCliente cli){
    cliente = cli;
}

TotalPagar Pedido::getTotal() const{
    return total;
}

void Pedido::setTotal(TotalPagar t){
    total = t;
}

vector<pair<Plato, unsigned int>> Pedido::getPlatosPedidos() const{
	return platosPedidos;
}

void Pedido::agregarPlato(Plato& plato, CantidadPlatosPedidos cantidad){ //guarda platos desde el ultimo
    if(cantidad == 0) return;

    platosPedidos.push_back({plato, cantidad});
    total += plato.getPrecio() * cantidad;
}

void Pedido::mostrarPedido() const{
	cout << endl;
    cout << "Pedido #" << numPedido << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "--------------------------------" << endl;

    for(const auto& par : platosPedidos){
        const Plato& p = par.first;
        CantidadPlatosPedidos cant = par.second;

        cout << "Plato: " << p.getNombre() << endl;
        cout << "Precio: $" << p.getPrecio() << endl;
        cout << "Cantidad: " << cant << endl;
        cout << "Subtotal: $" << p.getPrecio() * cant << endl;
        cout << "--------------------------------" << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "Total a pagar: $" << total << endl;
}


float Pedido::operator+(const Pedido& otro) const{ //sobre carga de operador para calcular valores esperados de los pedidos
    return this->total + otro.total;
}

void Pedido::guardarEnArchivo(ofstream& archivo) const{
    archivo << numPedido << endl;
    archivo << cliente << endl;
    archivo << total << endl;
    
    archivo << platosPedidos.size() << endl;
    
    for (const auto& par : platosPedidos){
        par.first.guardarEnArchivo(archivo);
        archivo << par.second << endl;
    }
}

void Pedido::cargarDesdeArchivo(ifstream& archivo){
    archivo >> numPedido;
    archivo.ignore();
    getline(archivo, cliente);
    archivo >> total;
    archivo.ignore();
    
    size_t numPlatos;
    archivo >> numPlatos;
    archivo.ignore();
    
    platosPedidos.clear();
    for(size_t i = 0; i < numPlatos; i++){
        Plato p;
        p.cargarDesdeArchivo(archivo);
        unsigned int cantidad;
        archivo >> cantidad;
        archivo.ignore();
        platosPedidos.push_back({p, cantidad});
    }
}
