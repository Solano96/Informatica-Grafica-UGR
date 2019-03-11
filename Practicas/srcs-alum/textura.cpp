#include "material.hpp"

// activa textura en el cauce fijo de OpenGL
void Textura::activar(){
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, idText);

	if(mgct == 1){
		GLfloat coefsS[4] = {1,0,0,0},
				coefsT[4] = {1,0,0,0};

		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ) ;
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ) ;
		//glTexGenfv(GL_S, GL_OBJECT_PLANE, coefsS);
		//glTexGenfv(GL_T, GL_OBJECT_PLANE, coefsT);
	}
	else if(mgct == 2){
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR ) ;
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR ) ;
	}
}

// crea un textura a partir de un archivo
Textura::Textura( const std::string & archivoJPG, int m){
    glGenTextures(1,&idText);
	glBindTexture(GL_TEXTURE_2D,idText);	

	img = new jpg::Imagen(archivoJPG.c_str());
	
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img->tamX(), img->tamY(), GL_RGB, GL_UNSIGNED_BYTE, img->leerPixels());
	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	mgct = m;
}