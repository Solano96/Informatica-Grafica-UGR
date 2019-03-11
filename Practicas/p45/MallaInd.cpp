#include <vector>
#include "MallaInd.hpp"

#include "aux.hpp"

using namespace std;



void MallaInd::visualizarGL(ContextoVis & cv, bool color){

	//asignarUniform(idProg, "matrizModelado", cv.pilaModelview.actual);

	if(cv.modoDiferido){

		if(!VBOs_creados)
			crearVBOs();

		visualizarDiferido(cv, color);
	}
	else
		visualizarInmediato(cv, color);
}

void MallaInd::visualizarDiferido(ContextoVis & cv, bool color){
	// especificar formato de los vértices en su VbO (y offset)
	glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver); // activar VBO
	glVertexPointer(3, GL_FLOAT, 0, 0);        // formato y offset (=0)
	glBindBuffer(GL_ARRAY_BUFFER, 0);			 // desactivar VBO
	glEnableClientState(GL_VERTEX_ARRAY);		 // activar uso VA

	// visualizar con glDrawElements (puntero a tabla == NULL)
	

	if(cv.modoVisu == modoPuntos){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		if(color)
			glColor3f(0,0,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_faces);	
		glDrawElements(GL_POINTS, 3*num_caras, GL_UNSIGNED_INT, NULL);
	}
	else if(cv.modoVisu == modoAlambre){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		if(color)
			glColor3f(0,0,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_faces);	
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, NULL);
	}
	else if(cv.modoVisu == modoSolido){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		if(color)
			glColor3f(0,0,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_faces);	
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, NULL);
	}
	else if(cv.modoVisu == modoAjedrez){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_pares);
		if(color)	
			glColor3f(0.2,0.2,0.2);
		glDrawElements(GL_TRIANGLES, 3*pares.size(), GL_UNSIGNED_INT, NULL);
		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_impares);	
		if(color)
			glColor3f(0.8,0.8,0.8);
		glDrawElements(GL_TRIANGLES, 3*impares.size(), GL_UNSIGNED_INT, NULL);
	}
	else if(cv.modoVisu == modoColor){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_faces);	
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, NULL);		
	}
	else if(cv.modoVisu == modoSombreadoPlano){
		if(!color)
			glDisable(GL_LIGHTING);
		glShadeModel(GL_FLAT);
		if(nor_tri.size() > 0){
			glEnableClientState(GL_NORMAL_ARRAY);  // habilitar normales
			glNormalPointer(GL_FLOAT, 0, nor_tri.data());
		}

		if(coords_text.size() > 0){
			glEnableClientState( GL_TEXTURE_COORD_ARRAY );
			glTexCoordPointer( 2, GL_FLOAT, 0, coords_text.data());
		}
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_faces);
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, NULL);	

		if(coords_text.size() != 0)
	        glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	    if(nor_tri.size() != 0)
	        glDisableClientState( GL_NORMAL_ARRAY );
	}
	else{
		if(!color)
			glDisable(GL_LIGHTING);
		glShadeModel(GL_SMOOTH);
		if(nor_ver.size() > 0){
			glEnableClientState(GL_NORMAL_ARRAY);  // habilitar normales
			glNormalPointer(GL_FLOAT, 0, nor_ver.data());
		}

		if(coords_text.size() > 0){
			glEnableClientState( GL_TEXTURE_COORD_ARRAY );
			glTexCoordPointer( 2, GL_FLOAT, 0, coords_text.data());
		}
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_faces);
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, NULL);	

		if(coords_text.size() != 0)
	        glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	    if(nor_ver.size() != 0)
	        glDisableClientState( GL_NORMAL_ARRAY );
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// desactivar uso de array de vértices
	glDisableClientState(GL_VERTEX_ARRAY);
}

void MallaInd::visualizarInmediato(ContextoVis & cv, bool color){

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &(vertices[0]));

	/*glColor3f(0,0,0);	
	glBegin(GL_LINES);
		for(int i = 0; i < baricentros.size(); i++){
			glVertex3f(baricentros[i](0),baricentros[i](1),baricentros[i](2));
			glVertex3f(bar_normales[i](0),bar_normales[i](1),bar_normales[i](2));
		}
	glEnd();*/

	if(cv.modoVisu == modoPuntos){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
    	glDisable( GL_COLOR_MATERIAL );	
		if(color)
			glColor3f(0,0,0);
		glDrawElements(GL_POINTS, 3*num_caras, GL_UNSIGNED_INT, caras.data());
	}
	else if(cv.modoVisu == modoAlambre){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);	
		if(color)
			glColor3f(0,0,0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, caras.data());
	}
	else if(cv.modoVisu == modoSolido){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);	
		if(color)
			glColor3f(0,0,0);
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, caras.data());
	}
	else if(cv.modoVisu == modoAjedrez){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);	
		if(color)
			glColor3f(0.2,0.2,0.2);
		glDrawElements(GL_TRIANGLES, 3*pares.size(), GL_UNSIGNED_INT, pares.data());
			
		if(color)
			glColor3f(0.8,0.8,0.8);
		glDrawElements(GL_TRIANGLES, 3*impares.size(), GL_UNSIGNED_INT, impares.data());
	}
	else if(cv.modoVisu == modoColor){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, caras.data());	
	}
	else if(cv.modoVisu == modoSombreadoPlano){
		if(!color)
			glDisable(GL_LIGHTING);

		glShadeModel(GL_FLAT);

		glBegin(GL_TRIANGLES);

            for (int i=0; i < caras.size(); i++){
                if (!nor_tri.empty()){
                    Tupla3f m = nor_tri[i];
                    glNormal3f( m(X), m(Y), m(Z) );
                }
                for (int j=0; j < 3; j++){
                    Tupla3f v = vertices[ caras[i][j] ];

                    if (!coords_text.empty()){
                        Tupla2f t = coords_text[ caras[i][j] ];
                        glTexCoord2f( t(X),t(Y) );
                    }

                    glVertex3f( v(X),v(Y),v(Z) );
                }
            }

            glEnd();
	}
	else{
		if(!color)
			glDisable(GL_LIGHTING);
		glShadeModel(GL_SMOOTH);
		if(nor_ver.size() > 0){
			glEnableClientState(GL_NORMAL_ARRAY);  // habilitar normales
			glNormalPointer(GL_FLOAT, 0, nor_ver.data());
		}

		if(coords_text.size() > 0){
			glEnableClientState( GL_TEXTURE_COORD_ARRAY );
			glTexCoordPointer( 2, GL_FLOAT, 0, coords_text.data());
		}
		glDrawElements(GL_TRIANGLES, 3*num_caras, GL_UNSIGNED_INT, caras.data());	

		if(coords_text.size() != 0)
	        glDisableClientState( GL_TEXTURE_COORD_ARRAY );
	    if(nor_ver.size() != 0)
	        glDisableClientState( GL_NORMAL_ARRAY );
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	//glDisable( GL_TEXTURE_GEN_S );
	//glDisable( GL_TEXTURE_GEN_T ); 

}

void MallaInd::crearVBOs(){

	tam_ver = sizeof(float)*3*num_vert;
	tam_faces = sizeof(unsigned)*3*num_caras;
	tam_pares = sizeof(unsigned)*3*pares.size();
	tam_impares = sizeof(unsigned)*3*impares.size();

	// crear VBO conteniendo la tabla de vértices
	id_vbo_ver = VBO_Crear(GL_ARRAY_BUFFER, tam_ver, vertices.data());

	// crear VBO con la tabla de triángulos (índices de vértices)
	id_vbo_faces = VBO_Crear(GL_ELEMENT_ARRAY_BUFFER, tam_faces, caras.data());

	// crear VBO con la tabla de triángulos pares 
	id_vbo_pares = VBO_Crear(GL_ELEMENT_ARRAY_BUFFER, tam_pares, pares.data());

	// crear VBO con la tabla de triángulos pares 
	id_vbo_impares = VBO_Crear(GL_ELEMENT_ARRAY_BUFFER, tam_impares, impares.data());


	VBOs_creados = true;
}

GLuint MallaInd::VBO_Crear(GLuint tipo, GLuint tamanio, GLvoid * puntero){
	assert(tipo == GL_ARRAY_BUFFER || tipo == GL_ELEMENT_ARRAY_BUFFER);
	GLuint id_vbo;
	glGenBuffers(1, & id_vbo);
	glBindBuffer(tipo, id_vbo);
	glBufferData(tipo, tamanio, puntero, GL_STATIC_DRAW);

	glBindBuffer(tipo, 0);

	return id_vbo;
}


// Para modoAjedrez
void MallaInd::CrearParesImpares(){	
	for(int i = 0; i < caras.size(); i++){
		if(i%2 == 0)
			pares.push_back(caras[i]);
		else
			impares.push_back(caras[i]);
	}		
}

// Obtener los vectores normalizados de cada cara

float norma3(Tupla3f t){
    //norma(t) = ||t|| (euclidea)
    return abs( sqrt( t[0]*t[0] + t[2]*t[2] + t[1]*t[1] ) );
}

void MallaInd::obtenerNormalesCaras(){

	for(int i = 0; i < caras.size(); i++){
		Tupla3f a = (vertices[caras[i](0)]+vertices[caras[i](1)]+vertices[caras[i](2)]);
		a = Tupla3f(a(0)/3.0, a(1)/3.0,a(2)/3.0);
		baricentros.push_back(a);
	}

	for(int i = 0; i < caras.size(); i++){
		Tupla3f a, b, m1, m2;
		a = vertices[caras[i](1)]-vertices[caras[i](0)];
		b = vertices[caras[i](2)]-vertices[caras[i](0)];

		// producto vectorial de a y b
		m1 = a.cross(b);
		m2 = b.cross(a);

		if(m1(0) != 0 || m1(1) != 0 || m1(2) != 0){
			m1 = m1.normalized();
			m2 = m2.normalized();
		}

		if(norma3(baricentros[i]+m2) >= norma3(baricentros[i]+m1))
			nor_tri.push_back(m2);
		else
			nor_tri.push_back(m1);
	}

	for(int i = 0; i < caras.size(); i++){
		Tupla3f b = nor_tri[i];
		b = Tupla3f(b(0)/15.0, b(1)/15.0, b(2)/15.0);
		bar_normales.push_back(baricentros[i]+b);
	}
}

void MallaInd::obtenerNormalesVertices(){
	for(int i = 0; i < vertices.size(); i++){
		nor_ver.push_back(Tupla3f(0,0,0));
	}

	for(int i = 0; i < caras.size(); i++){
		nor_ver[caras[i](0)] = nor_ver[caras[i](0)] + nor_tri[i];
		nor_ver[caras[i](1)] = nor_ver[caras[i](1)] + nor_tri[i];
		nor_ver[caras[i](2)] = nor_ver[caras[i](2)] + nor_tri[i];
	}

	for(int i = 0; i < vertices.size(); i++){
		if(nor_ver[i](0) != 0 && nor_ver[i](1) != 0 && nor_ver[i](2) != 0)
			nor_ver[i] = nor_ver[i].normalized();
	}
}

void MallaInd::calcularNormales(){
	obtenerNormalesCaras();
	obtenerNormalesVertices();
	//calcularBaricentros();
}

void MallaInd::calcularBaricentros(){
	for(int i = 0; i < caras.size(); i++){
		Tupla3f a = (vertices[caras[i](0)]+vertices[caras[i](1)]+vertices[caras[i](2)]);
		a = Tupla3f(a(0)/3.0, a(1)/3.0,a(2)/3.0);
		baricentros.push_back(a);
		Tupla3f b = nor_tri[i];
		b = Tupla3f(b(0)/5.0, b(1)/5.0, b(2)/5.0);
		bar_normales.push_back(a+b);
	}
}