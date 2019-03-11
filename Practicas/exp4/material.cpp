#include "material.hpp"
#include <iostream>

using namespace std;

void MaterialEstandar::activar(){
    glEnable( GL_NORMALIZE );
    glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR ) ;

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]);   
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]);
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente) ;
    
    if(textura != NULL){
        textura->activar();        
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        glDisable(GL_TEXTURE_2D);
        glDisable( GL_TEXTURE_GEN_S );
        glDisable( GL_TEXTURE_GEN_T ); 
    }
}

MaterialBarra::MaterialBarra(){
    textura = new Textura("barras.jpg");
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.6, 1.0 );
    color[2] = Tupla4f( 0.2, 0.2, 0.2, 1.0 );
    color[3] = Tupla4f(0.9, 0.9, 0.9, 1.0);
    exponente = 90;
}

MaterialMoneda::MaterialMoneda(){
    textura = new Textura("moneda-anv.jpg");
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.6, 1.0 );
    color[2] = Tupla4f( 0.2, 0.2, 0.2, 1.0 );
    color[3] = Tupla4f(0.9, 0.9, 0.9, 1.0);
    exponente = 90;
}

MaterialLata::MaterialLata(){
    textura = new Textura("../imgs/lata-coke.jpg");
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.6, 1.0 );
    color[2] = Tupla4f( 0.2, 0.2, 0.2, 1.0 );
    color[3] = Tupla4f(0.9, 0.9, 0.9, 1.0);
    exponente = 90;
}

MaterialTapasLata::MaterialTapasLata(){
    textura = NULL;
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.8, 0.8, 0.8, 1.0);
    color[3] = Tupla4f( 0.3, 0.3, 0.3, 1.0 );
    exponente = 90;
}

MaterialPeonBlanco::MaterialPeonBlanco(){
    textura = NULL;
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0);
    color[3] = Tupla4f( 0, 0, 0, 1.0 );
    exponente = 90;
}

MaterialPeonNegro::MaterialPeonNegro(){
    textura = NULL;
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[2] = Tupla4f( 0.1, 0.1, 0.1, 1.0 );
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 50;
}

MaterialPeonMadera::MaterialPeonMadera(){
    textura = new Textura("../imgs/text-madera.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 70;
}

MaterialTanque::MaterialTanque(int m){
    textura = new Textura("camuflaje.jpg", m);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 70;
}

MaterialRuedas::MaterialRuedas(int m){
    textura = new Textura("ruedas.jpg", m);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 70;
}

MaterialInventado::MaterialInventado(){
    textura = NULL;
    color[0] = Tupla4f( 0.1, 0.3, 0.0, 1.0 );
    color[1] = Tupla4f( 0.4, 0.3, 0.3, 1.0 );
    color[2] = Tupla4f( 0.4, 0.8, 0.3, 1.0 );
    color[3] = Tupla4f( 0, 0, 0, 1.0 );
    exponente = 50;
}
