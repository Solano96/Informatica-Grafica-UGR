
#include "NodoGrafoEscena.hpp"

void NodoGrafoEscena::visualizarGL(ContextoVis & cv, bool color){

	cv.pilaMateriales.push();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

		for(unsigned i = 0; i < entradas.size(); i++){
			if(entradas[i].tipoE == '0'){ // sub-objeto: visualizarlo
				glColor3f(0.2,1.0/(i/1.5+1.5),0);
				entradas[i].objeto->visualizarGL(cv, color);
			}
			else if(entradas[i].tipoE == '1'){
				glMatrixMode(GL_MODELVIEW);
				glMultMatrixf(*(entradas[i].matriz));
			}
			else{
	            cv.pilaMateriales.activarMaterial(entradas[i].material);
			}
		}

	cv.pilaMateriales.pop();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

int NodoGrafoEscena::agregar(EntradaNGE * entrada){
	entradas.push_back(*entrada);
	return entradas.size()-1;
}

int NodoGrafoEscena::agregar(Objeto3D * pObjeto){
	entradas.push_back(EntradaNGE(pObjeto));
	return entradas.size()-1;
}

int NodoGrafoEscena::agregar(const Matriz4f & pMatriz){
	entradas.push_back(EntradaNGE(pMatriz));
	return entradas.size()-1;
}

int NodoGrafoEscena::agregar(Material * material){
	entradas.push_back(EntradaNGE(material));
	return entradas.size()-1;
}

// el indice i debe ser el correspondiente a una matriz de transformación (nunca a un objeto3D)
Matriz4f * NodoGrafoEscena::obtenerPunteroMatriz(int i){
	return entradas[i].matriz;
}

void NodoGrafoEscena::calcularNormales(){
    for(int i = 0; i < entradas.size(); i++){
        if(entradas[i].tipoE == '0'){
            entradas[i].objeto->calcularNormales();
        }
    }
}



Objeto3D* NodoGrafoEscena::buscarNodoConIdent(int identBuscado){
    Objeto3D* result = NULL;

    if( identBuscado > 0 ){
        if (this->identificador == identBuscado)
            result = this;

        for (int i = 0; i < entradas.size() && (result==NULL); i++){
            if(entradas[i].tipoE == '0' && identificador == 0)
                result = ((NodoGrafoEscena*) (entradas[i].objeto))->buscarNodoConIdent(identBuscado);
        }
    }
    return result;
}

void NodoGrafoEscena::modoSeleccion(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    ContextoVis cv;
    cv.modoVisu = modoSolido;
    glColor3ub(identificador,0,0);

    for (int i=0; i<entradas.size(); ++i){
        if (entradas[i].tipoE == '1'){
            glMultMatrixf(*(entradas[i].matriz));
        }
        else if (entradas[i].tipoE == '0'){
        	if(identificador == 0)
                ((NodoGrafoEscena*)entradas[i].objeto)->modoSeleccion();
            else
            	entradas[i].objeto->visualizarGL(cv, false);
        }
        
    }

    glMatrixMode (GL_MODELVIEW);
    glPopMatrix();
}






/*void NodoGrafoEscena::visualizarGL(ContextoVis & cv){

	Material * materialActivoInicial = materialActivo;

	cv.pilaModelview.push();

		for(unsigned i = 0; i < entradas.size(); i++){
			if(entradas[i].tipoE == '0'){ // sub-objeto: visualizarlo
				glColor3f(0.2,1.0/(i/1.5+1.5),0);
				entradas[i].objeto->visualizarGL(cv);
			}
			else if(entradas[i].tipoE == '1')
				cv.pilaModelview.cMatriz(*(entradas[i].matriz));
			else{
				if(entradas[i].material != materialActivo){ //Activar materiales es costoso!!
	                entradas[i].material->activar();
	                materialActivo = entradas[i].material;
				}
			}
		}

		if(materialActivoInicial != materialActivo){
	        materialActivo = materialActivoInicial ;    // restaurar el original en 'cv'
	        
	        if ( materialActivo != NULL ){              // si el original no era NULL
	            materialActivo->activar();              //    reactivarlo
		    }
		}

	cv.pilaModelview.pop();
}*/