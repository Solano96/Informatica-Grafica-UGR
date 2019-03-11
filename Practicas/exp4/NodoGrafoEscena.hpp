
#ifndef NODOGRAFOESCENA_HPP
#define NODOGRAFOESCENA_HPP

#include <string>
#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include "shaders.hpp"
#include "EntradaNGE.hpp"
#include "material.hpp"

class NodoGrafoEscena : public Objeto3D{

	protected:	
		std::vector<EntradaNGE> entradas; //vector de entradas

	public: 

		NodoGrafoEscena(){
			identificador = 0;
		};

		// visualizar usando OpenGL
		virtual void visualizarGL(ContextoVis & cv, bool color = true);
		// añadir una entrada (al final)
		int agregar(EntradaNGE * entrada); //generica
		// construir una entrada y añadirla (al final)
		int agregar(Objeto3D * pObjeto);   // objeto
		int agregar(const Matriz4f & pMatriz);  // matriz
		int agregar(Material * material);
		Matriz4f * obtenerPunteroMatriz(int i); // devuelve el puntero de la matriz colocada en la posición i de entradas
		void calcularNormales();
    	Objeto3D * buscarNodoConIdent( int identBuscado );
		void modoSeleccion();
};

#endif