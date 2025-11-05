#ifndef PEDIDOSSISTEMA_H
#define PEDIDOSSISTEMA_H

#include "Menu.h"
#include "ColaPedidos.h"

class PedidosSistema{
    private:
        Menu* m;
        ColaPedidos cola;
        int numeroPedidoActual;
        
    public:
        PedidosSistema(Menu* m);

        void realizarPedido();
        void atenderPedido();
        void mostrarPedidos();
    
};

#endif