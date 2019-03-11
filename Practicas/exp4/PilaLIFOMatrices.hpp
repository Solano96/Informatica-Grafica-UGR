

#ifndef PILALIFOMATRICES_HPP
#define PILALIFOMATRICES_HPP


#include <vector>
#include "matrices-tr.hpp"

class PilaLIFOMatrices{

	public:
		Matriz4f actual; // matriz actual (inicialmente identidad)
		std::vector<Matriz4f> pila; // matrices apiladas (inicialmente vacía)

		// métodos:
		PilaLIFOMatrices(); // constructor
		void push();        // apilar la matriz actual en el tope
		void pop();			// restaurar matriz actual desde tope, y eliminar tope
		void asignaIdent();	// hacer matriz actual igual a la identidad

		// métodos de composición (actual = actual*matriz)
		void cMatriz(const Matriz4f & mat);
		void cTraslacion(const float dx, const float dy, const float dz);
		void cEscalado(const float sx, const float sy, const float sz);
		void cRotacion(const float ang_gra, const float ex, const float ey, const float ez);
};

#endif










