#ifndef MALLAREVOL_HPP
#define MALLAREVOL_HPP

#include <string>
#include "MallaInd.hpp"
#include "tuplasg.hpp"
#include "file_ply_stl.hpp"

using namespace std;
 
class MallaRevol : public MallaInd{
	public: 
		// constructor: crea una malla de revolución
		MallaRevol(){}

		MallaRevol(const string & nombre_arch,   // nombre de archivo ply
					  const unsigned nperfiles,	  // número de perfiles
					  const bool     crear_tapas,   // true para crear tapas
					  const bool     cerrar_malla, int ident = 0); // true para cerrar la malla

		MallaRevol(vector<Tupla3f> vert, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla, int ident = 0);

		void ObtenerRevolucion(vector<Tupla3f> vert, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla);
};

#endif
