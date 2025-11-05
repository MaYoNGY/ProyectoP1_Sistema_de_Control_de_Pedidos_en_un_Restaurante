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
		
		Plato(NombrePlato nom, CodigoPlato co, PrecioPlato pre, CategoriaPlato cat, CantidadPlatos can, PlatoDisponible dis = true);
				
		NombrePlato getNombre();
		void setNombre(NombrePlato n);
		
		CodigoPlato getCodigo();
		void setCodigo(CodigoPlato c);
		
		PrecioPlato getPrecio();
		void setPrecio(PrecioPlato p);
		
		CategoriaPlato getCategoria();
		void setCategoria(CategoriaPlato ca);
		
		PlatoDisponible getDisponible();
		void setDisponible(PlatoDisponible d);

		CantidadPlatos getCantidad();
		void setCantidad(CantidadPlatos cant);
		
		void mostrarPlato();
		
};

#endif
