#include "Pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido(){
    numPedido = 0;
    nombre = "";
    cliente = "";
    cantidad = 0;
    total = 0.0;
}

Pedido::Pedido(NumeroPedido numP, NombrePlatoPedido n, NombreCliente cli, CantidadPlatosPedidos ca, TotalPagar t){
    numPedido = numP;
    nombre = n;
    cliente = cli;
    cantidad = ca;
    total = t;
}

NumeroPedido Pedido::getNumeroPedido(){
    return numPedido;
}

void Pedido::setNumeroPedido(NumeroPedido numP){
    numPedido = numP;
}

NombrePlatoPedido Pedido::getNombre(){
    return nombre;
}

void Pedido::setNombre(NombrePlatoPedido n){
    nombre = n;
}

NombreCliente Pedido::getCliente(){
    return cliente;
}

void Pedido::setCliente(NombreCliente cli){
    cliente = cli;
}

CantidadPlatosPedidos Pedido::getCantidad(){
    return cantidad;
}

void Pedido::setCantidad(CantidadPlatosPedidos ca){
    cantidad = ca;
}

TotalPagar Pedido::getTotal(){
    return total;
}

void Pedido::setTotal(TotalPagar t){
    total = t;
}

void Pedido::mostrarPedido(){
    cout << "Pedido #" << numPedido << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "Plato: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Total a pagar: $" << total << endl;
}

