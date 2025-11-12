#include "Validacion.h"
#include <iostream>
#include <conio.h>

using namespace std;

string Validacion::pedirNombrePlato(){
	string nombrePlato;
	
	do{
		cout << "Ingrese el nombre del plato: ";
		nombrePlato = "";
		char c;
		while(true){
			c = _getch(); //Lee la tecla sin presionar enter
			if(c == 13){ //enter
				cout << endl;
				break;
			}else if(c == 8){ //backspace
				if(!nombrePlato.empty()){
					nombrePlato.pop_back();
					cout << "\b \b";
				}
			}else if((c >= 'a' && c <= 'z') || (c == ' ')){
				nombrePlato += c;
				cout << c;
			}
		}
		if(nombrePlato.empty()){
			cout << "El nombre no puede estar vacio, intente de nuevo..." << endl;
		}
	}while(nombrePlato.empty());
	return nombrePlato;
}

unsigned int Validacion::pedirCodigo(){
	string codigo;

    do{
        cout << "Ingrese el codigo del plato: ";
        codigo = "";
        char c;

        while(true){
            c = _getch();

            if(c == 13){
                cout << endl;
                break;
            }else if(c == 8){
                if(!codigo.empty()){
                    codigo.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= '0' && c <= '9') && (codigo.length() < 4)){
                codigo += c;
                cout << c;
            }
        }
		if(codigo.length() != 4){
            cout << "El codigo debe tener exactamente 4 digitos, intente de nuevo..." << endl;
        }
    }while(codigo.length() != 4);

    return stoi(codigo);
}

float Validacion::pedirPrecio(){
    string precio;
    bool tienePunto = false;

    do{
        cout << "Ingrese el precio del plato: ";
        precio = "";
        tienePunto = false;
        char c;

        while(true){
            c = _getch();

            if(c == 13){
                cout << endl;
                break;
            }else if(c == 8){
                if(!precio.empty()){
                    if (precio.back() == '.') tienePunto = false;
                    precio.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= '0' && c <= '9') && (precio.length() < 5)){
                precio += c;
                cout << c;
            }else if(c == '.' && !tienePunto && !precio.empty()){
                precio += c;
                tienePunto = true;
                cout << c;
            }
        }
        if(precio.empty()){
            cout << "El precio no puede estar vacio, intente de nuevo..." << endl;
        }
    }while(precio.empty());

    return stof(precio);
}

string Validacion::pedirCategoria(){
    string categoria;

    do{
        cout << "Ingrese la categoria del plato: ";
        categoria = "";
        char c;

        while(true){
            c = _getch();

            if(c == 13){
                cout << endl;
                break;
            }else if(c == 8){
                if(!categoria.empty()){
                    categoria.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= 'a' && c <= 'z') || (c == ' ')){
                categoria += c;
                cout << c;
            }
        }
        if(categoria.empty()){
            cout << "La categoria no puede estar vacia, intente de nuevo..." << endl;
        }
    }while(categoria.empty());

    return categoria;
}

unsigned int Validacion::pedirCantidadPlato(){
    string cantidad;

    do{
        cout << "Cuantos platos desea registrar?: ";
        cantidad = "";
        char c;

        while(true){
            c = _getch();

            if(c == 13){
                cout << endl;
                break;
            }else if(c == 8){
                if(!cantidad.empty()){
                    cantidad.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= '0' && c <= '9') && (cantidad.length() < 3)) {
                cantidad += c;
                cout << c;
            }
        }
        if(cantidad.empty()){
            cout << "La cantidad no puede estar vacia, intente de nuevo..." << endl;
        }
    }while(cantidad.empty());

    return stoi(cantidad);
}

string Validacion::pedirNombreCliente(){
    string nombreCliente;

    do{
        cout << "Ingrese el nombre del cliente: ";
        nombreCliente = "";
        char c;

        while(true){
            c = _getch();

            if(c == 13){ 
                cout << endl;
                break;
            }else if(c == 8){
                if (!nombreCliente.empty()){
                    nombreCliente.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= 'a' && c <= 'z') || (c == ' ')){
                nombreCliente += c;
                cout << c;
            }
        }
        if(nombreCliente.empty()){
            cout << "El nombre no puede estar vacio, intente de nuevo..." << endl;
        }
    }while(nombreCliente.empty());

    return nombreCliente;
}

unsigned int Validacion::pedirCanTipoPlato(){
    string cantidad;

    do{
        cout << "Cuantos tipos de platos desea ordenar?: ";
        cantidad = "";
        char c;

        while(true){
            c = _getch();

            if(c == 13){
                cout << endl;
                break;
            }else if(c == 8){ 
                if(!cantidad.empty()){
                    cantidad.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= '0' && c <= '9') && (cantidad.length() < 3)){
                cantidad += c;
                cout << c;
            }
        }
        if(cantidad.empty()){
            cout << "La cantidad no puede estar vacia, intente de nuevo..." << endl;
        }
    }while(cantidad.empty());

    return stoi(cantidad);
}

char Validacion::pedirConfirmacion(){
    char c;

    while(true){
        c = _getch();

        if(c == 's' || c == 'S' || c == 'n' || c == 'N'){
            cout << c << endl;
            break;
        }else{
            cout << endl;
            cout << "Entrada invalida. Presione S/N: ";
        }
    }
    return c;
}

unsigned int Validacion::pedirOpc(){
	string opc;

    do{
        cout << "Ingrese la opcion que desee: ";
        opc = "";
        char c;

        while(true){
            c = _getch();

            if(c == 13){
                cout << endl;
                break;
            }else if(c == 8){
                if(!opc.empty()){
                    opc.pop_back();
                    cout << "\b \b";
                }
            }else if((c >= '0' && c <= '9') && (opc.length() < 1)) {
                opc += c;
                cout << c;
            }
        }
        if(opc.empty()){
            cout << "Entrada invalida intente de nuevo..." << endl;
        }
    }while(opc.empty());

    return stoi(opc);
}

