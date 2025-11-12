#ifndef VALIDACION_H
#define VALIDACION_H

#include <string>
using namespace std;

class Validacion{
	
	public:
		//Se usa static para no crear un objeto
		static string pedirNombrePlato();
		static unsigned int pedirCodigo();
		static float pedirPrecio();
		static string pedirCategoria();
		static unsigned int pedirCantidadPlato();
		static string pedirNombreCliente();
		static unsigned int pedirCanTipoPlato();
		static char pedirConfirmacion();
		static unsigned int pedirOpc();
};

#endif
