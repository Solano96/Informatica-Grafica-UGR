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
#include "shaders.hpp"
#include "luz.hpp"

using namespace std;

static Tanque *tanque = NULL;
int p3_grado_libertad_activo, numParametros;
bool animaciones;


FuentePosicional *luzPosicional_p3;
FuenteDireccional *luzDireccional_p3;

ColeccionFL fuentes_p3;

// ---------------------------------------------------------------------
// Función de inicialización Práctica 3 donde se crea una instancia de nodo raiz

void P3_Inicializar( int argc, char *argv[] ){

	tanque = new Tanque();
	tanque->calcularNormales();

	p3_grado_libertad_activo = 0;
	animaciones = false;
	numParametros = tanque->numParametros();

	luzPosicional_p3 = new FuentePosicional(Tupla3f(0,2,5));
	luzDireccional_p3 = new FuenteDireccional(0,0);

	fuentes_p3.fuentes.push_back(luzPosicional_p3);
	fuentes_p3.fuentes.push_back(luzDireccional_p3);
}

// ---------------------------------------------------------------------
// Función teclas de la práctica 3

bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ){	

	if(tecla == 'G'){
		p3_grado_libertad_activo++;
		p3_grado_libertad_activo%=numParametros;
		cout << "Grado de libertad activo: " << tanque->leerPtrParametro(p3_grado_libertad_activo)->leer_descripcion() << endl;
		return true;
	}	
	else if(tecla == 'A'){
		if(animaciones){
			animaciones = false;
			cout << "Animaciones desactivadas." << endl;
		}
		else{
			animaciones = true;
			cout << "Animaciones activadas." << endl;
		}			

		return true;
	}
	else if(tecla == 'R'){
		
		for(int i = 0; i < numParametros; i++){
			tanque->leerPtrParametro(i)->reset();
		}

		animaciones = false;

		cout << "Reset ejecutado." << endl;

		return true;
	}
	else if(tecla == '>'){
		if(animaciones){
			tanque->leerPtrParametro(p3_grado_libertad_activo)->acelerar();
			cout << "Acelerar: " << tanque->leerPtrParametro(p3_grado_libertad_activo)->leer_descripcion() << endl;
		}
		else{
			tanque->leerPtrParametro(p3_grado_libertad_activo)->incrementar();
			cout << "Incrementar: " << tanque->leerPtrParametro(p3_grado_libertad_activo)->leer_descripcion() << endl;
		}

		return true;
	}
	else if(tecla == '<'){
		if(animaciones){
			tanque->leerPtrParametro(p3_grado_libertad_activo)->decelerar();			
			cout << "Decelerar: " << tanque->leerPtrParametro(p3_grado_libertad_activo)->leer_descripcion() << endl;
		}
		else{
			tanque->leerPtrParametro(p3_grado_libertad_activo)->decrementar();
			cout << "decrementar: " << tanque->leerPtrParametro(p3_grado_libertad_activo)->leer_descripcion() << endl;
		}

		return true;
	}

	return false;	
}

void P3_DibujarObjetos( ContextoVis & cv){

	fuentes_p3.activar();
	tanque->visualizarGL(cv);
	fuentes_p3.desactivar();

}


bool P3_FGE_Desocupado(){

	// no hacer nada si no es necesario, y desactivar
	if(!animaciones){
		return false; // provoca la desactivación del evento desocupado
	}

	// modificar los paŕametros animables según sus velocidades actuales	
	tanque->siguienteCuadro();	

	// forzar un evento de redibujado para visualizar siguiente cuadro:
	glutPostRedisplay();

	// terminar, manteniendo activada la gestión del evento
	return true;
}




