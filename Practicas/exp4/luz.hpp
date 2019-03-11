#ifndef IG_FUENTELUZ
#define IG_FUENTELUZ

#include "aux.hpp"
#include "tuplasg.hpp"
#include <vector>


class FuenteLuz{
	public:
		Tupla4f posvec; // posición (si w=1) o vector de dirección (si w=0)
		Tupla4f colores[3]; // colores: 0=ambiental, 1=difuso, 2=especular
		float longi, lati; // ángulos de rotación (si direccional)

		void activar(int i); // activarla (con ident. OpenGL GL_LIGHT0+i)
		void desactivar(int i);
};


class ColeccionFL{
	public:
		std::vector<FuenteLuz *> fuentes; // vector de fuentes de luz
		void activar(); // activas todas las fuentes de luz
		void desactivar();
};


class FuenteDireccional : public FuenteLuz{
	public:
		// inicializar la fuente de luz
		FuenteDireccional(float alpha_inicial, float beta_inicial);

		// Cambiar ángulo:
		// (angulo==0 -> variar alpha, angulo==1 -> variar beta)
		void variarAngulo(unsigned angulo, float incremento);
};


class FuentePosicional : public FuenteLuz{
	public:
		FuentePosicional(const Tupla3f & posicion);
};


class ColeccionFuentesP4 : public ColeccionFL{
	public:
		ColeccionFuentesP4();
};


#endif