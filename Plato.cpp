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
    size_t len = nombre.length();
    archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
    archivo.write(nombre.c_str(), len);
    
    archivo.write(reinterpret_cast<const char*>(&codigo), sizeof(codigo));
    archivo.write(reinterpret_cast<const char*>(&precio), sizeof(precio));
    
    len = categoria.length();
    archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
    archivo.write(categoria.c_str(), len);
    
    archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(cantidad));
    archivo.write(reinterpret_cast<const char*>(&disponible), sizeof(disponible));
}

void Plato::cargarDesdeArchivo(ifstream& archivo){
    size_t len;
    archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
    nombre.resize(len);
    archivo.read(&nombre[0], len);
    
    archivo.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
    archivo.read(reinterpret_cast<char*>(&precio), sizeof(precio));
    
    archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
    categoria.resize(len);
    archivo.read(&categoria[0], len);
    
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
    archivo.read(reinterpret_cast<char*>(&disponible), sizeof(disponible));
}

