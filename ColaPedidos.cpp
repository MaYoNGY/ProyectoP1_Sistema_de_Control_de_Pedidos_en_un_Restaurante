#include "ColaPedidos.h"
#include <iostream>

using namespace std;

ColaPedidos::ColaPedidos(){
    front = nullptr;
    rear = nullptr;
    contador = 0;
    numPedidoActual = 1;
    m = nullptr;
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

void ColaPedidos::agregarPedido(NombreCliente cliente){ //Insertar en el fondo

	CodigoPlato codigo;
    CantidadPlatos cantidad;
    bool cantidadValida = false;
    bool agregar = true;

	if(m == nullptr){
        cout << "El menu esta vacio" << endl;
        return;
    }

    cout << "Creando pedido para " << cliente << endl;

    unsigned int n;
    cout << "Cuantos tipos de platos desea ordenar?: ";
    cin >> n;

    if(n <= 0){
        cout << "Debe ingresar al menos un tipo de plato!!!" << endl;
        return;
    }

    Pedido pe(numPedidoActual++, cliente);

    for(unsigned int i = 0; i < n; i++){
        
        cout << "Ingrese el codigo del plato #" << (i + 1) << ": ";
        cin >> codigo;

        bool codigoDuplicado = false;
        vector<pair<Plato, unsigned int>> platosActuales = pe.getPlatosPedidos();
        for(const auto& par : platosActuales){
            if(par.first.getCodigo() == codigo){
                codigoDuplicado = true;
                break;
            }
        }

        if(codigoDuplicado){
            cout << "Este plato ya fue agregado al pedido!!!" << endl;
            i--;
            continue;
        }

        Plato* p = m->buscarPlatoCo(codigo);

        if(p == nullptr){
            cout << "Codigo de plato no encontrado" << endl;
            i--;
            continue;
        }

        do{
            cout << "Cuantos platos desea pedir?: ";
            cin >> cantidad;

            if(cantidad > p->getCantidad()){
                cout << "Solo hay " << p->getCantidad() << " disponibles" << endl;

                char opcion;
                cout << "Desea pedir esa cantidad maxima disponible (S/N)? ";
                cin >> opcion;

                if(opcion == 'S' || opcion == 's'){
                    cantidad = p->getCantidad();
                    cantidadValida = true;
                }else{
                    cout << "Desea ingresar otra cantidad (S/N)? ";
                    cin >> opcion;

                    if(opcion == 'S' || opcion == 's'){
                        cantidadValida = false;
                    }else{
                        cout << "Plato omitido del pedido..." << endl;
                        agregar = false;
                        cantidadValida = true;
                    }
                }
            }else{
                cantidadValida = true;
            }

        }while(!cantidadValida);

        if(agregar){
        	pe.agregarPlato(*p, cantidad);
            p->setCantidad(p->getCantidad() - cantidad);
            cout << "Plato (" << p->getNombre() << ") agregado al pedido.\n";
        }
        
        cantidadValida = false;
        agregar = true;
    }

    if(pe.getTotal() == 0){
    	cout << endl;
        cout << "No se agrego ningun plato. Pedido cancelado." << endl;
        return;
    }

    NodoPedido* nuevo = new NodoPedido(pe);

    if(estaVacia()){
        front = rear = nuevo;
    }else{
        rear->siguiente = nuevo;
        nuevo->anterior = rear;
        rear = nuevo;
    }

    contador++;
    cout << endl;
    cout << "Pedido agregado exitosamente a la cola!!!" << endl;     
}

void ColaPedidos::agregarPedido(const Pedido& p){
	NodoPedido* nuevo = new NodoPedido(p);
	
	if(estaVacia()){
		front = rear = nuevo;
	}else{
		rear->siguiente = nuevo;
		nuevo->anterior = rear;
		rear = nuevo;
	}
	
	contador++;
	cout << "Pedido #" << p.getNumeroPedido() << " de " << p.getCliente() << " fue restaurado a la cola" << endl;
}

Pedido ColaPedidos::atenderPedido(){
    NodoPedido* temp = front;
    Pedido pedidoAtendido = temp->dato;
    cout << "----- Atendiendo pedido #" << temp->dato.getNumeroPedido() << " -----" << endl;
    pedidoAtendido.mostrarPedido();
    front = front->siguiente;
    
    if(front){
        front->anterior = nullptr;
    }else{
    	rear = nullptr;
	}
	
	delete temp;
    contador--;
    
    return pedidoAtendido;
}

bool ColaPedidos::cancelarPedido(NombreCliente cliente) {
    if(estaVacia()){
        cout << "No hay pedidos en la cola" << endl;
        return false;
    }

    NodoPedido* actual = front;
    bool encontrado = false;

    while(actual != nullptr){
        if (actual->dato.getCliente() == cliente){
            encontrado = true;

            cout << endl;
            cout << "Pedido del cliente (" << cliente << ") encontrado, desea cancelarlo? (S/N): ";
            char opcion;
            cin >> opcion;

            if(opcion != 'S' && opcion != 's'){
                cout << "Cancelacion abortada por el usuario" << endl;
                return false;
            }

            vector<pair<Plato, unsigned int>> platos = actual->dato.getPlatosPedidos();
            for(auto& par : platos){
                Plato& p = par.first;
                int cantidad = par.second;
                Plato* platoEnMenu = m->buscarPlatoCo(p.getCodigo());
                if(platoEnMenu != nullptr){
                    platoEnMenu->setCantidad(platoEnMenu->getCantidad() + cantidad);
                }
            }

            if(actual == front && actual == rear){
                front = rear = nullptr;
            }else if (actual == front){
                front = front->siguiente;
                front->anterior = nullptr;
            }else if (actual == rear){
                rear = rear->anterior;
                rear->siguiente = nullptr;
            }else{
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            contador--;

            cout << endl << "Pedido del cliente (" << cliente << ") ha sido cancelado y los platos devueltos al menu" << endl;
            return true;
        }

        actual = actual->siguiente;
    }

    if(!encontrado){
        cout << "No se encontro ningun pedido del cliente '" << cliente << endl;
    }

    return false;
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
        cout << "--------------------------------" << endl;
        actual = actual->siguiente;
    }
    calcularIngresosEsperados();
    cout << endl;
}

float ColaPedidos::calcularIngresosEsperados() const{

    Pedido acumulador;
    NodoPedido* aux = front;

    while(aux != nullptr){
        float totalAcumulado = acumulador + aux->dato;
        acumulador.setTotal(totalAcumulado);
        aux = aux->siguiente;
    }

    cout << "Ingresos esperados de pedidos: $" << acumulador.getTotal() << endl;
    return acumulador.getTotal();
}

