#include <string>
#include "MallaPLY.hpp"

using namespace std;

MallaPLY::MallaPLY(const string & nombre_arch){
	vector<float> vert;
	vector<int> faces;

	ply::read(nombre_arch.c_str(), vert, faces);

	num_vert = vert.size()/3;

	for(int i = 0; i < num_vert; i++){
		vertices.push_back(Tupla3f(vert[3*i], vert[3*i+1], vert[3*i+2]));
	}

	num_caras = faces.size()/3;

	for(int i = 0; i < num_caras; i++){
		caras.push_back(Tupla3i(faces[3*i], faces[3*i+1], faces[3*i+2]));
	}

	CrearParesImpares();
} 


