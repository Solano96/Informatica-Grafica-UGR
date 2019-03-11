#ifndef MALLAPLY_HPP
#define MALLAPLY_HPP

#include <string>
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "tuplasg.hpp"
#include "file_ply_stl.hpp"

using namespace std;

class MallaPLY : public MallaInd{
	public:
		// constructor
		// se debe especificar el nombre completo del archivo a leer
		MallaPLY(const string & nombre_arch);
};

#endif
