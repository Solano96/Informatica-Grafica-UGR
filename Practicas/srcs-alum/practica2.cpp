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
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"

using namespace std;

static MallaPLY *objeto1 = NULL;     // Objeto MallaPLY
static MallaRevol *objeto2 = NULL;   // Objeto Malla Revolución (sin acabar aún)

unsigned p2_objeto_activo = 1 ; 

void P2_Inicializar( int argc, char *argv[] ){
	string name1 = "../plys/ant.ply";
	string name2 = "../plys/peon.ply";

	objeto1 = new MallaPLY(name1);

	int nperfiles = 8;
	bool cerrar_malla = true;
	bool crear_tapas = true;
	objeto2 = new MallaRevol(name2, nperfiles, crear_tapas, cerrar_malla);
}


bool P2_FGE_PulsarTeclaNormal(  unsigned char tecla ){	
    
	if(tecla == 'O'){
		p2_objeto_activo++;
		p2_objeto_activo%=2;
		return true;
	}

	return false;
	
}

void P2_DibujarObjetos( ContextoVis & cv ){
	if(p2_objeto_activo == 0)
		objeto1->visualizarGL(cv);
	else
		objeto2->visualizarGL(cv);
}



