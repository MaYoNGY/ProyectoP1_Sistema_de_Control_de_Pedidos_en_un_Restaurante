#ifndef PLATO_H
#define PLATO_H

#include <string>
using namespace std;

typedef string NombrePlato;
typedef unsigned int CodigoPlato;
typedef float PrecioPlato;
typedef string CategoriaPlato;
typedef bool PlatoDisponible;

class Plato{
	
	private:
		NombrePlato nombre;
		CodigoPlato codigo;
		PrecioPlato precio;
		CategoriaPlato categoria;
		PlatoDisponible disponible;
	
	public:
		
		Plato();
		
		Plato(string nom, int co, float pre, string cat, bool dis = true);
				
		string getNombre();
		void setNombre(string n);
		
		int getCodigo();
		void setCodigo(int c);
		
		float getPrecio();
		void setPrecio(float p);
		
		string getCategoria();
		void setCategoria(string ca);
		
		bool getDisponible();
		void setDisponible(bool d);
		
		void mostrarPlato();
		
};

#endif
