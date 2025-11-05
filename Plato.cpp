#include "Plato.h"
#include <iostream>
using namespace std;

Plato::Plato(){
	nombre = "";
    codigo = 0;
    precio = 0.0;
    categoria = "";
	cantidad = 0;
    disponible = true;
}

Plato::Plato(NombrePlato nom, CodigoPlato co, PrecioPlato pre, CategoriaPlato cat, CantidadPlatos can, PlatoDisponible dis){
	nombre = nom;
	codigo = co;
	precio = pre;
	categoria = cat;
	cantidad = can;
	disponible = dis;
}

NombrePlato Plato::getNombre(){
	return nombre;
}

void Plato::setNombre(NombrePlato n){
	nombre = n;
}

CodigoPlato Plato::getCodigo(){
	return codigo;
}

void Plato::setCodigo(CodigoPlato c){
	codigo = c;
}

PrecioPlato Plato::getPrecio(){
	return precio;
}

void Plato::setPrecio(PrecioPlato p){
	precio = p;
}

CategoriaPlato Plato::getCategoria(){
	return categoria;
}

void Plato::setCategoria(CategoriaPlato ca){
	categoria = ca;
}

PlatoDisponible Plato::getDisponible(){
	return disponible;
}

void Plato::setDisponible(PlatoDisponible d){
	disponible = d;
}

CantidadPlatos Plato::getCantidad(){
	return cantidad;
}

void Plato::setCantidad(CantidadPlatos cant){
	cantidad = cant;
}

void Plato::mostrarPlato(){
	cout << endl;
	cout << "----- Plato -----" << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Precio: $" << precio << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Cantidad: " << cantidad << endl;
	cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
	cout << endl;
}
