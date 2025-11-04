#include "Plato.h"
#include <iostream>
using namespace std;

Plato::Plato(){
	nombre = "";
    codigo = 0;
    precio = 0.0;
    categoria = "";
    disponible = true;
}

Plato::Plato(string nom, int co, float pre, string cat, bool dis){
	nombre = nom;
	codigo = co;
	precio = pre;
	categoria = cat;
	disponible = dis;
}

string Plato::getNombre(){
	return nombre;
}

void Plato::setNombre(string n){
	nombre = n;
}

int Plato::getCodigo(){
	return codigo;
}

void Plato::setCodigo(int c){
	codigo = c;
}

float Plato::getPrecio(){
	return precio;
}

void Plato::setPrecio(float p){
	precio = p;
}

string Plato::getCategoria(){
	return categoria;
}

void Plato::setCategoria(string ca){
	categoria = ca;
}

bool Plato::getDisponible(){
	return true;
}

void Plato::setDisponible(bool d){
	disponible = d;
}

void Plato::mostrarPlato(){
	cout << endl;
	cout << "----- Plato -----" << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Precio: $" << precio << endl;
	cout << "Categoria: " << categoria << endl;
	cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
	cout << endl;
}
