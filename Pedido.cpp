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

void Pedido::agregarPlato(Plato& plato, CantidadPlatosPedidos cantidad){
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

float Pedido::operator+(const Pedido& otro) const{
    return this->total + otro.total;
}

void Pedido::guardarEnArchivo(ofstream& archivo) const{
    archivo.write(reinterpret_cast<const char*>(&numPedido), sizeof(numPedido));
    
    size_t len = cliente.length();
    archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
    archivo.write(cliente.c_str(), len);
    
    archivo.write(reinterpret_cast<const char*>(&total), sizeof(total));
    
    size_t numPlatos = platosPedidos.size();
    archivo.write(reinterpret_cast<const char*>(&numPlatos), sizeof(numPlatos));
    
    for (const auto& par : platosPedidos){
        par.first.guardarEnArchivo(archivo);
        archivo.write(reinterpret_cast<const char*>(&par.second), sizeof(par.second));
    }
}

void Pedido::cargarDesdeArchivo(ifstream& archivo){
    archivo.read(reinterpret_cast<char*>(&numPedido), sizeof(numPedido));
    
    size_t len;
    archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
    cliente.resize(len);
    archivo.read(&cliente[0], len);
    
    archivo.read(reinterpret_cast<char*>(&total), sizeof(total));
    
    size_t numPlatos;
    archivo.read(reinterpret_cast<char*>(&numPlatos), sizeof(numPlatos));
    
    platosPedidos.clear();
    for(size_t i = 0; i < numPlatos; i++){
        Plato p;
        p.cargarDesdeArchivo(archivo);
        unsigned int cantidad;
        archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
        platosPedidos.push_back({p, cantidad});
    }
}
