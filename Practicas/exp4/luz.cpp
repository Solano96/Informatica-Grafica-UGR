#include "luz.hpp"
#include <iostream>

void FuenteLuz::activar(int i){
	glEnable(GL_LIGHT0+i);	

	glLightfv( GL_LIGHT0+i, GL_POSITION, posvec);
	glLightfv(GL_LIGHT0+i, GL_AMBIENT, colores[0]);
	glLightfv(GL_LIGHT0+i, GL_DIFFUSE, colores[1]);
	glLightfv(GL_LIGHT0+i, GL_SPECULAR, colores[2]);	
	
}

void FuenteLuz::desactivar(int i){
	glDisable(GL_LIGHT0+i);
}

void ColeccionFL::activar(){
	glEnable(GL_LIGHTING);
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);

	for(int i = 0; i < fuentes.size(); i++)
		fuentes[i]->activar(i);

}

void ColeccionFL::desactivar(){
	for(int i=0; i<fuentes.size(); i++){
		fuentes[i]->desactivar(i);
	}

	glDisable(GL_LIGHTING);
}

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial){	
	longi = alpha_inicial;
	lati = beta_inicial;

    posvec = Tupla4f(longi, lati, 1, 0);

    // colores[]: 0=ambiental, 1=difuso, 2=especular.    
	colores[0] = Tupla4f(0.0,0.0,0.0, 1.0);
	colores[1] = Tupla4f(1.0,1.0,1.0, 1.0);
	colores[2] = Tupla4f(1.0,1.0,1.0, 1.0);
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento){
	 if(angulo == 0){
        longi += incremento;
    }
    else{    	
        lati += incremento;
    }

    posvec = Tupla4f(longi, lati, 1, 0);
}

FuentePosicional::FuentePosicional( const Tupla3f & posicion ){
    // posición (si w=1) o vector (w=0)
    posvec = Tupla4f(posicion[0], posicion[1], posicion[2], 1); //en este caso w=1
    // colores[]: 0=ambiental, 1=difuso, 2=especular.
    
	colores[0] = Tupla4f(1.0,1.0,1.0, 1.0);
	colores[1] = Tupla4f(1.0,1.0,1.0, 1.0);
	colores[2] = Tupla4f(1.0,1.0,1.0, 1.0);
}
