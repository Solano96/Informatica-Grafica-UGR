
#include "EntradaNGE.hpp"

EntradaNGE::EntradaNGE(Objeto3D * pObjeto){
	tipoE = '0';
	objeto = pObjeto;
}

EntradaNGE::EntradaNGE(const Matriz4f & pMatriz){
	tipoE = '1';
	matriz = new Matriz4f(pMatriz);
}

EntradaNGE::EntradaNGE(Material* pMaterial){
    material = pMaterial;
    tipoE='2';
}