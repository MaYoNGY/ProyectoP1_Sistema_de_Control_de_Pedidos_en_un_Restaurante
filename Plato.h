#ifndef PLATO_H
#define PLATO_H

#include <string>
using namespace std;

typedef string NombrePlato;
typedef unsigned int CodigoPlato;
typedef float PrecioPlato;
typedef string CategoriaPlato;
typedef bool PlatoDisponible;
typedef unsigned int CantidadPlatos;

class Plato{
	
	private:
		NombrePlato nombre;
		CodigoPlato codigo;
		PrecioPlato precio;
		CategoriaPlato categoria;
		PlatoDisponible disponible;
		CantidadPlatos cantidad;
	
	public:
		
		Plato();
		
		Plato(NombrePlato nom, CodigoPlato co, PrecioPlato pre, CategoriaPlato cat, CantidadPlatos can);
				
		NombrePlato getNombre() const;
		void setNombre(NombrePlato n);
		
		CodigoPlato getCodigo() const;
		void setCodigo(CodigoPlato c);
		
		PrecioPlato getPrecio() const;
		void setPrecio(PrecioPlato p);
		
		CategoriaPlato getCategoria() const;
		void setCategoria(CategoriaPlato ca);
		
		PlatoDisponible getDisponible() const;
		void setDisponible(PlatoDisponible d);

		CantidadPlatos getCantidad() const;
		void setCantidad(CantidadPlatos cant);
		
		void mostrarPlato();
		
		friend bool operator>(const Plato& a, const Plato& b);
		friend bool operator<(const Plato& a, const Plato& b);
};

#endif

