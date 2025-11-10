#ifndef PEDIDO_H
#define PEDIDO_H

#include "Plato.h"
#include <vector>
#include <string>
using namespace std;

typedef unsigned int NumeroPedido;
typedef string NombreCliente;
typedef unsigned int CantidadPlatosPedidos;
typedef float TotalPagar;

class Pedido{
    private:
        NumeroPedido numPedido;
        NombreCliente cliente;
        TotalPagar total;
        vector<pair<Plato*, CantidadPlatosPedidos>> platosPedidos;

    public:
 
        Pedido();
        
        Pedido(NumeroPedido numP, NombreCliente cli);
        
        NumeroPedido getNumeroPedido() const;
        void setNumeroPedido(NumeroPedido numP);
        
        NombreCliente getCliente() const;
        void setCliente(NombreCliente cli);
        
        TotalPagar getTotal() const;
        void setTotal(TotalPagar t);
        
        vector<pair<Plato*, unsigned int>> getPlatosPedidos() const;
        
        void agregarPlato(Plato* plato, CantidadPlatosPedidos cantidad);
        
        void mostrarPedido() const;
        
        float operator+(const Pedido& otro) const;

};

#endif

