// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 3  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA3_HPP
#define IG_PRACTICA3_HPP

#include "MallaInd.hpp"

void P3_Inicializar( int argc, char *argv[] ) ;
bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P3_DibujarObjetos( ContextoVis & cv) ;

// Func. de gestión del evento desocupado de la práctica 3
// debe devolver: false: si queremos que se desactive el evento
//				  true : si queremos que el evento permanezca activado
bool P3_FGE_Desocupado();

#endif
