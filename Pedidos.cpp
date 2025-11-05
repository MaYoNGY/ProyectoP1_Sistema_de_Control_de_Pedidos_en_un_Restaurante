#include "Pedidos.h"
#include <iostream>
using namespace std;

Pedidos::Pedidos(){
    numPedido = 0;
    nombre = "";
    cliente = "";
    cantidad = 0;
    total = 0.0;
}

Pedidos::Pedidos(NumeroPedido numP, NombrePlatos n, NombreCliente c, CantidadPlatosPedidos ca, TotalPagar t){
    numPedido = numP;
    nombre = n;
    cliente = c;
    cantidad = ca;
    total = t;
}

NumeroPedido Pedidos::getNumeroPedido(){
    return numPedido;
}

void Pedidos::setNumeroPedido(NumeroPedido numP){
    numPedido = numP;
}

NombrePlatos Pedidos::getNombre(){
    return nombre;
}

void Pedidos::setNombre(NombrePlatos n){
    nombre = n;
}

NombreCliente Pedidos::getCliente(){
    return cliente;
}

void Pedidos::setCliente(NombreCliente cli){
    cliente = cli;
}

CantidadPlatosPedidos Pedidos::getCantidad(){
    return cantidad;
}

void Pedidos::setCantidad(CantidadPlatosPedidos cantPlatos){
    cantidad = cantPlatos;
}

TotalPagar Pedidos::getTotal(){
    return total;
}

void Pedidos::setTotal(TotalPagar totalP){
    total = totalP;
}

void Pedidos::mostrarPedido(){
    cout << "Pedido #" << numPedido << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "Plato: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Total a pagar: $" << total << endl;
}
