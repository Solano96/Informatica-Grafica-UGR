
#ifndef ENTRADANGE_HPP
#define ENTRADANGE_HPP

#include <string>
#include "Objeto3D.hpp"
#include "MallaInd.hpp"
#include "tuplasg.hpp"
#include "shaders.hpp"
#include "material.hpp"

// Entrada del nodo del Grafo de Escena

struct EntradaNGE{

	unsigned char tipoE; // 0=objeto, 1=transformación, 2=material
	union{
		Objeto3D * objeto; // ptr. a un objeto (propietario)
		Matriz4f * matriz; // ptr. a matriz 4x4 transf. (prop.)
		Material * material;
	};
	// constructores (uno por tipo)
	EntradaNGE(Objeto3D * pObjeto); // (copia solo puntero)
	EntradaNGE(const Matriz4f & pMatriz); // (crea copia)
	EntradaNGE (Material * material );
};

#endif