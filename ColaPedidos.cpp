#include "ColaPedidos.h"
#include <iostream>
#include <fstream>

using namespace std;

ColaPedidos::ColaPedidos(){
    front = nullptr;
    rear = nullptr;
    contador = 0;
    numPedidoActual = 1;
    m = nullptr;
}

ColaPedidos::ColaPedidos(MenuRestaurante* menu){
    m = menu;
    front = rear = nullptr;
    numPedidoActual = 1;
    contador = 0;
}

ColaPedidos::~ColaPedidos(){
    while (!estaVacia()){
        NodoPedido* temp = front;
        front = front->siguiente;
        delete temp;
    }
    rear = nullptr;
}

void ColaPedidos::setNumPedidoActual(int num){
    numPedidoActual = num;
}

int ColaPedidos::getNumPedidoActual() const{
    return numPedidoActual;
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
        cout << "El menu esta vacio!!" << endl;
        return;
    }
	
	m->mostrarMenu();
	
    cout << "Creando pedido para " << cliente << endl;
    
    unsigned int n;

    unsigned int totalTiposPlatos = m->getCantidadTiposPlatos();
	n = Validacion::pedirCanTipoPlato();

	if(n <= 0){
	    cout << "Debe ingresar al menos un tipo de plato!!" << endl;
	    return;
	}

	if(n > totalTiposPlatos){
	    cout << "Solo hay " << totalTiposPlatos << " tipos de platos disponibles en el menu!!" << endl;
	    return;
	}	

    Pedido pe(numPedidoActual++, cliente);

    for(unsigned int i = 0; i < n; i++){
        
        cout << "Ingrese el codigo del plato #" << (i + 1) << endl;
        codigo = Validacion::pedirCodigo();

        bool codigoDuplicado = false;
        vector<pair<Plato, unsigned int>> platosActuales = pe.getPlatosPedidos();
        for(const auto& par : platosActuales){ 
            if(par.first.getCodigo() == codigo){  //busqueda de platos por codigo en dentro del vector
                codigoDuplicado = true;
                break;
            }
        }

        if(codigoDuplicado){
            cout << "Este plato ya fue agregado al pedido!!" << endl;
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
            cantidad = Validacion::pedirCantidadPlato();

            if(cantidad > p->getCantidad()){
                cout << "Solo hay " << p->getCantidad() << " disponibles" << endl;

                char opcion;
                cout << "Desea pedir esa cantidad maxima disponible (S/N)? ";
                opcion = Validacion::pedirConfirmacion();

                if(opcion == 'S' || opcion == 's'){
                    cantidad = p->getCantidad();
                    cantidadValida = true;
                }else{
                    cout << "Desea ingresar otra cantidad (S/N)? ";
                    opcion = Validacion::pedirConfirmacion();

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
            cout << "Plato (" << p->getNombre() << ") agregado al pedido..." << endl;
        }
        
        cantidadValida = false;
        agregar = true;
    }

    if(pe.getTotal() == 0){
    	cout << endl;
        cout << "No se agrego ningun plato. Pedido cancelado..." << endl;
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
    cout << "Pedido agregado exitosamente a la cola!!" << endl;     
}

void ColaPedidos::agregarPedido(const Pedido& p){ //Ingreso por el fondo para restaurar pedido
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

Pedido ColaPedidos::atenderPedido(){ //atencion o eliminacion por el frente
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

bool ColaPedidos::cancelarPedido(NombreCliente cliente){ //Elimina pedido
    if(estaVacia()){
        cout << "No hay pedidos en la cola!!" << endl;
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
            opcion = Validacion::pedirConfirmacion();

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

            if(actual == front && actual == rear){ //Elimina cnodo unico de la cola
                front = rear = nullptr;
            }else if(actual == front){ //Elimina nodo que esta al frente
                front = front->siguiente;
                front->anterior = nullptr;
            }else if(actual == rear){ //elimina nodo que esta al final
                rear = rear->anterior;
                rear->siguiente = nullptr;
            }else{ //Elimina el nodo que esta en el medio
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
        cout << "No hay pedidos en la cola!!" << endl;
        return;
    }

    NodoPedido* actual = front;
    while(actual){
        actual->dato.mostrarPedido();
        cout << "---------------------------------------" << endl;
        actual = actual->siguiente;
    }
    calcularIngresosEsperados();
    cout << endl;
}

float ColaPedidos::calcularIngresosEsperados() const{ //usa sobrecarga de operador

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

void ColaPedidos::guardarCola(const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if (!archivo){
        cout << "Error al abrir el archivo para guardar la cola de pedidos." << endl;
        return;
    }
    
    archivo << numPedidoActual << endl;
    archivo << contador << endl;
    
    NodoPedido* temp = front;
    while (temp){
        temp->dato.guardarEnArchivo(archivo);
        temp = temp->siguiente;
    }
    
    archivo.close();
    cout << "Cola de pedidos guardada exitosamente en (" << nombreArchivo << ")." << endl;
}

void ColaPedidos::cargarCola(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if (!archivo){
        cout << "No se encontro archivo previo de pedidos. Iniciando con cola vacia." << endl;
        return;
    }

    while (!estaVacia()){
        NodoPedido* temp = front;
        front = front->siguiente;
        delete temp;
    }
    front = rear = nullptr;
    contador = 0;
    
    archivo >> numPedidoActual;
    archivo.ignore();
    
    int cantidadPedidos;
    archivo >> cantidadPedidos;
    archivo.ignore();
    
    for(int i = 0; i < cantidadPedidos; i++){
        Pedido p;
        p.cargarDesdeArchivo(archivo);
        
        NodoPedido* nuevo = new NodoPedido(p);
        if (estaVacia()){
            front = rear = nuevo;
        } else {
            rear->siguiente = nuevo;
            nuevo->anterior = rear;
            rear = nuevo;
        }
        contador++;
    }
    
    archivo.close();
    cout << "Cola de pedidos cargada exitosamente desde (" << nombreArchivo << ")." << endl;
}


