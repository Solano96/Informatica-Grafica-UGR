#include "PilaLIFOMatrices.hpp"

PilaLIFOMatrices::PilaLIFOMatrices(){
	actual = MAT_Ident();
}

void PilaLIFOMatrices::push(){
	pila.push_back(actual);
}

void PilaLIFOMatrices::pop(){
	actual = pila[pila.size()-1];
	pila.pop_back();
}

void PilaLIFOMatrices::asignaIdent(){
	actual = MAT_Ident();
}

void PilaLIFOMatrices::cMatriz(const Matriz4f & mat){
	actual = actual * mat;
}

void PilaLIFOMatrices::cTraslacion(const float dx, const float dy, const float dz){
	actual = actual * MAT_Traslacion(dx,dy,dz);
}

void PilaLIFOMatrices::cEscalado(const float sx, const float sy, const float sz){
	actual = actual * MAT_Escalado(sx,sy,sz);
}

void PilaLIFOMatrices::cRotacion(const float ang_gra, const float ex, const float ey, const float ez){
	actual = actual * MAT_Rotacion(ang_gra, ex, ey, ez);
}
