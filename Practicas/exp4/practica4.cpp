// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include <cmath>
#include <string>
#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica1.hpp"
#include "practica3.hpp"
#include "modelo.hpp"
#include "NodoGrafoEscena.hpp"
#include "luz.hpp"

#include "shaders.hpp"

using namespace std;

FuentePosicional * luzPosicional = NULL;
FuenteDireccional * luzDireccional = NULL;

ColeccionFL fuentes;

Escena * escena = NULL;

int angulo = 0;

// ---------------------------------------------------------------------
// Función de inicialización Práctica 3 donde se crea una instancia de nodo raiz

void P4_Inicializar( int argc, char *argv[] ){

	escena = new Escena();
	escena->calcularNormales();
	luzPosicional = new FuentePosicional(Tupla3f(20,15,-20));
	luzDireccional = new FuenteDireccional(0,0);

	fuentes.fuentes.push_back(luzPosicional);
	fuentes.fuentes.push_back(luzDireccional);
}

// ---------------------------------------------------------------------
// Función teclas de la práctica 3

bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ){	

	if(tecla == 'G'){
		angulo++;
		angulo%=2;
		return true;
	}	
	if(tecla == '<'){
        luzDireccional->variarAngulo(angulo,-0.1);
        return true;
    }
    if(tecla == '>'){
        luzDireccional->variarAngulo(angulo,0.1);
        return true;
    }
	
	return false;	
}

void P4_DibujarObjetos( ContextoVis & cv){
		fuentes.activar();
		escena->visualizarGL(cv);
		fuentes.desactivar();
}




