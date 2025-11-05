#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <string>
using namespace std;

typedef unsigned int NumeroPedido;
typedef string NombrePlatos;
typedef string NombreCliente;
typedef unsigned int CantidadPlatosPedidos;
typedef float TotalPagar;

class Pedidos{
    private:
        NumeroPedido numPedido;
        NombrePlatos nombre;
        NombreCliente cliente;
        CantidadPlatosPedidos cantidad;
        TotalPagar total;

    public:
 
        Pedidos();
        Pedidos(NumeroPedido numP, NombrePlatos n, NombreCliente c, CantidadPlatosPedidos ca, TotalPagar t);
        NumeroPedido getNumeroPedido();
        void setNumeroPedido(NumeroPedido numPedido);
        NombrePlatos getNombre();
        void setNombre(NombrePlatos nombre);
        NombreCliente getCliente();
        void setCliente(NombreCliente cliente);
        CantidadPlatosPedidos getCantidad();
        void setCantidad(CantidadPlatosPedidos cantidad);
        TotalPagar getTotal();
        void setTotal(TotalPagar total);
        void mostrarPedido();

};

#endif
