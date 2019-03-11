#include "NodoGrafoEscenaParam.hpp"

int NodoGrafoEscenaParam::numParametros(){
	return parametros.size();
}

Parametro * NodoGrafoEscenaParam::leerPtrParametro(unsigned i){
	return &parametros[i];
}

void NodoGrafoEscenaParam::siguienteCuadro(){
	for(int i = 0; i < parametros.size(); i++){
		leerPtrParametro(i)->siguiente_cuadro();
	}
}
