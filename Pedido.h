#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
using namespace std;

typedef unsigned int NumeroPedido;
typedef string NombrePlatoPedido;
typedef string NombreCliente;
typedef unsigned int CantidadPlatosPedidos;
typedef float TotalPagar;

class Pedido{
    private:
        NumeroPedido numPedido;
        NombrePlatoPedido nombre;
        NombreCliente cliente;
        CantidadPlatosPedidos cantidad;
        TotalPagar total;

    public:
 
        Pedido();
        
        Pedido(NumeroPedido numP, NombrePlatoPedido n, NombreCliente cli, CantidadPlatosPedidos ca, TotalPagar t);
        
        NumeroPedido getNumeroPedido() const;
        void setNumeroPedido(NumeroPedido numP);
        
        NombrePlatoPedido getNombre();
        void setNombre(NombrePlatoPedido n);
        
        NombreCliente getCliente() const;
        void setCliente(NombreCliente cli);
        
        CantidadPlatosPedidos getCantidad();
        void setCantidad(CantidadPlatosPedidos ca);
        
        TotalPagar getTotal();
        void setTotal(TotalPagar t);
        
        void mostrarPedido();

};

#endif

