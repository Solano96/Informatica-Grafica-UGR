#ifndef IG_TEXTURA_HPP
#define IG_TEXTURA_HPP

#include "jpg_imagen.hpp"
#include "aux.hpp"

class Textura{
	public: 
		GLuint		  idText; // identificador OpenGL de la textura
		jpg::Imagen * img; 	  // puntero a objeto imagen con los texels en RAM
		unsigned 	  mgct;	  // modo de generación cc.tt.: 0 = desactivado, 1 = obeto, 2 = mundo
		float  		  cs[4],  // coeficientes (S) para gerneación de cc.tt. (si mgct != 0)
					  ct[4];  // coeficientes (T) para generación de cc.tt. (si mgct != 0)

		void activar();		
    	Textura( const std::string & archivoJPG, int m = 0); 
};

#endif