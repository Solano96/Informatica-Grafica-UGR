// declarar parámetro uniform tipo matriz 4x4

/*uniform mat4 matrizModelado;

void main(){
	gl_FrontColor = gl_Color;
	gl_Position = gl_ModelViewProjectionMatrix * matrizModelado * gl_Vertex;
}*/





// Vertex Shaders

// directiva que indica que el código corresponde a GLSL ver 1.3
#version 130

// parámetros de entrada uniform(constantes en casa primitiva)
uniform mat4 matrizModelado; 	// matriz de modelado actual
uniform mat4 matrizVista;	 	// matriz de vista (mundo -> camara)
uniform mat4 matrizProyeccion;  // matriz projection
uniform int tipoGCT;			// tipo gen.cc.tt.(0=desact., 1=obj., 2=cám.)

// parámetros de entradas predefinidos en GLSL (solo disponibles hasta GLSL 1.30)
// vec4 gl_Vertex coordenadas del vértice en el m.c. de objeto
// vec3 gl_Normal normal del vértice en el m.c. de objeto
// vec3 gl_TexCoord[0] coordenadas de textura (unidad 0)


// valores calculados como salida (todas en coordenadas de cámara, EC)
out vec3 normalPunto;	// normal del vértice (w=0)
out vec4 posPunto;		// posición del vértice
out vec3 vecObservador;	// vector del vért. hacia el observador
out vec2 coordsText;	// coordenadas de textura vért.


void main(){

	// calcular la matriz modelview
	/*mat4 matrizModelView = matrizVista * matrizModelado;

	// calcular normal, posiión y vector al obs. (en el m.c. de cámara)
	// son variables de salida (out) que se interpolan durante rasterización
	normalPunto 	= (matrizModelView * vec4(gl_Normal,0.0)).xyz;
	posPunto 		= matrizModelView * gl_Vertex;
	vecObservador 	= -posPunto.xyz;

	// calcular coordenadas de textura del vértice (tamb. se interpolan)
	if(tipoGCT == 0)		coordsText = gl_TexCoord[0].st;
	else if(tipoGCT == 1) 	coordsText = gl_Vertex.xy;
	else					coordsText = posPunto.xy;*/

	// calcular posición de vértice, en coords
gl_FrontColor = gl_Color;
	gl_Position = (gl_ModelViewProjectionMatrix * matrizModelado) * gl_Vertex;
}

