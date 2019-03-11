#ifndef OBJETO3D_HPP
#define OBJETO3D_HPP

#include <string>
#include "practicas.hpp"
#include "aux.hpp"

class Objeto3D{
	protected:
		std::string nombre_obj;

	public:
		
   		int identificador ;  // identificador entero (0 si el nodo no se selecciona)
		Tupla3f centro ; // punto central del objeto, en coordenadas de mundo
		
		virtual void visualizarGL(ContextoVis & cv, bool color = true) = 0;
		virtual void calcularNormales() = 0;

		Objeto3D * buscarNodoConIdent( int identBuscado ){
			if(identBuscado == identificador){
				return this;
			}
			else{
				return NULL;
			}
		}

		std::string nombre();
};

#endif
