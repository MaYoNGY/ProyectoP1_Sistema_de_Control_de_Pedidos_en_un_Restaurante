#include "Plato.h"
#include <iostream>
using namespace std;

Plato::Plato(){
	nombre = "";
    codigo = 0;
    precio = 0.0;
    categoria = "";
	cantidad = 0;
    disponible = (cantidad > 0);
}

Plato::Plato(NombrePlato nom, CodigoPlato co, PrecioPlato pre, CategoriaPlato cat, CantidadPlatos can){
	nombre = nom;
	codigo = co;
	precio = pre;
	categoria = cat;
	cantidad = can;
	disponible = (can > 0);
}

NombrePlato Plato::getNombre() const{
	return nombre;
}

void Plato::setNombre(NombrePlato n){
	nombre = n;
}

CodigoPlato Plato::getCodigo() const{
	return codigo;
}

void Plato::setCodigo(CodigoPlato c){
	codigo = c;
}

PrecioPlato Plato::getPrecio() const{
	return precio;
}

void Plato::setPrecio(PrecioPlato p){
	precio = p;
}

CategoriaPlato Plato::getCategoria() const{
	return categoria;
}

void Plato::setCategoria(CategoriaPlato ca){
	categoria = ca;
}

PlatoDisponible Plato::getDisponible() const{
	return disponible;
}

void Plato::setDisponible(PlatoDisponible d){
	disponible = d;
}

CantidadPlatos Plato::getCantidad() const{
	return cantidad;
}

void Plato::setCantidad(CantidadPlatos cant){
	cantidad = cant;
	if(cantidad <= 0){
		disponible = false;
	}
}

void Plato::mostrarPlato(){
	cout << endl;
	cout << "------------- Plato -------------" << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Precio: $" << precio << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Cantidad: " << cantidad << endl;
	cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
}

bool operator>(const Plato& a, const Plato& b){
    return a.precio > b.precio;
}

bool operator<(const Plato& a, const Plato& b){
    return a.precio < b.precio;
}

void Plato::guardarEnArchivo(ofstream& archivo) const{
    archivo << nombre << endl;
    archivo << codigo << endl;
    archivo << precio << endl;
    archivo << categoria << endl;
    archivo << cantidad << endl;
    archivo << disponible << endl;
}

void Plato::cargarDesdeArchivo(ifstream& archivo){
    getline(archivo, nombre);
    archivo >> codigo;
    archivo.ignore();
    archivo >> precio;
    archivo.ignore();
    getline(archivo, categoria);
    archivo >> cantidad;
    archivo.ignore();
    archivo >> disponible;
    archivo.ignore();
}

