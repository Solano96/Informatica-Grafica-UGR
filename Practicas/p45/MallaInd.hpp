#ifndef MALLAIND_HPP
#define MALLAIND_HPP

#include <vector>

#include "Objeto3D.hpp"
#include "shaders.hpp"

using namespace std;

class MallaInd : public Objeto3D{
	protected:
		int num_vert;
		int num_caras;
		int tam_ver, tam_faces, tam_pares, tam_impares;
		vector<Tupla3f> vertices;
		vector<Tupla3i> caras;
		vector<Tupla3i> pares, impares;
		bool VBOs_creados;

		vector<Tupla3f> nor_tri;
		vector<Tupla3f> nor_ver;
		vector<Tupla2f> coords_text;

		vector<Tupla3f> baricentros;
		vector<Tupla3f> bar_normales;

		GLuint id_vbo_ver;
		GLuint id_vbo_faces;
		GLuint id_vbo_pares;
		GLuint id_vbo_impares;
		//GLuint idProg;

	public:
		MallaInd(){
			VBOs_creados = false;			
			//idProg = CrearPrograma("fragment-shader.glsl","vertex-shader.glsl");
		}

		virtual void visualizarGL(ContextoVis & cv, bool color = true);
		void CrearParesImpares();
		void crearVBOs();
		void visualizarInmediato(ContextoVis & cv, bool color);
		void visualizarDiferido(ContextoVis & cv, bool color);
		GLuint VBO_Crear(GLuint tipo, GLuint tamanio, GLvoid * puntero);

		void calcularNormales();
		void obtenerNormalesCaras();
		void obtenerNormalesVertices();

		void calcularBaricentros();
};

#endif
