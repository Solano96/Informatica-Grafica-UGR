#include <string>
#include <cmath>
#include "MallaRevol.hpp"

using namespace std;

float norma(Tupla3f t){
    //norma(t) = ||t|| (euclidea)
    return abs( sqrt( t[0]*t[0] + t[2]*t[2] + t[1]*t[1] ) );
}


MallaRevol::MallaRevol(const string & nombre_arch, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla, int ident){
	vector<float> vert;
	vector<Tupla3f> vert3f;	

	ply::read_vertices(nombre_arch.c_str(), vert);

	for(int i = 0; i < vert.size()/3; i++){
		vert3f.push_back(Tupla3f(vert[3*i], vert[3*i+1], vert[3*i+2]));
	}

	ObtenerRevolucion(vert3f, nperfiles, crear_tapas, cerrar_malla);
	identificador = ident;
}


MallaRevol::MallaRevol(vector<Tupla3f> vert, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla, int ident){	
	ObtenerRevolucion(vert, nperfiles, crear_tapas, cerrar_malla);
	identificador = ident;
}

void MallaRevol::ObtenerRevolucion(vector<Tupla3f> vert, const unsigned nperfiles, const bool crear_tapas, const bool cerrar_malla){
	
	int nvertices;
	double pi = 3.141592;
	double angulo = pi*2/nperfiles, angulo_j;
	float x, y, z;
	int cierre = 1;	

	if(cerrar_malla) cierre = 0;

	nvertices = vert.size();

	// Almacenar los vertices por revolución
	for(int j = 0; j < nperfiles + cierre; j++){
		for(int i = 0; i < nvertices; i++){
			angulo_j = angulo*j;
			x = cos(angulo_j)*vert[i](0) + sin(angulo_j)*vert[i](2);
			y = vert[i](1);
			z = cos(angulo_j)*vert[i](2) - sin(angulo_j)*vert[i](0);
			vertices.push_back(Tupla3f(x, y, z));
		}
	}

	int ultimo = vertices.size()/nvertices-1;

	// Almacenar las caras
	for(int i = 0; i < ultimo; i++){
		for(int j = 0; j < nvertices-1; j++){
			caras.push_back(Tupla3i(i*nvertices+j, i*nvertices+j+1, (i+1)*nvertices+j));
			caras.push_back(Tupla3i((i+1)*nvertices+j, (i+1)*nvertices+j+1, i*nvertices+j+1));	
		}
	}

	if(cerrar_malla){
		for(int j = 0; j < nvertices-1; j++){
			caras.push_back(Tupla3i(ultimo*nvertices+j, ultimo*nvertices+j+1, j));
			caras.push_back(Tupla3i(j, j+1, ultimo*nvertices+j+1));	
		}
	}

	if(crear_tapas){
		vertices.push_back(Tupla3f(0,vert[0](1),0));
		vertices.push_back(Tupla3f(0, vert[(nvertices-1)](1), 0));

		// Tapa de abajo
		for(int i = 0; i < ultimo; i++){
			caras.push_back(Tupla3i( i*nvertices, (i+1)*nvertices, vertices.size()-2 ));
		}

		if(cerrar_malla)
			caras.push_back(Tupla3i(ultimo*nvertices, 0, vertices.size()-2 ));
	
		// Tapa de arriba
		for(int i = 0; i < ultimo; i++){
			caras.push_back(Tupla3i( (i+1)*nvertices-1, (i+2)*nvertices-1, vertices.size()-1 ) );
		}

		if(cerrar_malla)
			caras.push_back(Tupla3i( (ultimo+1)*nvertices-1, nvertices-1, vertices.size()-1 ));
	}

	num_vert = vertices.size();
	num_caras = caras.size();

	float s;
    float d[nvertices];
    coords_text.resize(nvertices*(nperfiles+cierre));
    d[0] = 0;
    
    for(int i = 1 ; i < nvertices ; i++ ){
        d[i] = d[i-1]+norma(vertices[i]-vertices[i-1]);
    }
    
    for (int i = 0 ; i < nperfiles + cierre ; i++){
        s = 1.0*i / (nperfiles + cierre );
        for(int j = 0 ; j < nvertices ; j++ )
            coords_text[i*nvertices+j] = Tupla2f(s,1-1.0*d[j]/d[nvertices-1]);        
    }

	CrearParesImpares();
}






