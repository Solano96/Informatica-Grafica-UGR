#include "modelo.hpp"
#include "practica1.hpp"


Lata::Lata(){
    nombre_obj = "Lata";
    identificador = 1;
    centro = Tupla3f(0,0.5,0);
    agregar(new MaterialTapasLata());
    agregar(new MallaRevol("../plys/lata-pinf.ply",100, true, true));
    agregar(new MaterialLata());
    agregar(new MallaRevol("../plys/lata-pcue.ply",100, false, false));
    agregar(new MaterialTapasLata());
    agregar(new MallaRevol("../plys/lata-psup.ply",100, true, true));
}

PeonMadera::PeonMadera(){
    nombre_obj = "Peón de madera";
    identificador = 2;
    centro = Tupla3f(0, 0, 0.6);
    agregar(new MaterialPeonMadera());
    agregar(new MallaRevol("../plys/peon.ply",100, true, true));
}


PeonBlanco::PeonBlanco(){
    nombre_obj = "Peón blanco";
    identificador = 3;
    centro = Tupla3f(0.6, 0, 0.6);
    agregar(new MaterialPeonBlanco());
    agregar(new MallaRevol("../plys/peon.ply",100, true, true));
}


PeonNegro::PeonNegro(){
    nombre_obj = "Peón negro";
    identificador = 4;
    centro = Tupla3f(1.2, 0, 0.6);
    agregar(new MaterialPeonNegro());
    agregar(new MallaRevol("../plys/peon.ply",100, true, true));
}

Escena::Escena(){
        //agregar(MAT_Escalado(5,5,5));
        agregar(new Lata());
        agregar(MAT_Escalado(0.2,0.2,0.2));
        agregar(MAT_Traslacion(0,1.4,3));
        agregar(new PeonMadera());
        agregar(MAT_Traslacion(3,0,0));
        agregar(new PeonBlanco());
        agregar(MAT_Traslacion(3,0,0));
        agregar(new PeonNegro());
    }

Base::Base(){
	vertices.push_back(Tupla3f(3, 0, 2));
	vertices.push_back(Tupla3f(3, 0, -2));
	vertices.push_back(Tupla3f(-3, 0, -2));
	vertices.push_back(Tupla3f(-3, 0, 2));

	vertices.push_back(Tupla3f(4.5, 1, 2));
	vertices.push_back(Tupla3f(4.5, 1, -2));
	vertices.push_back(Tupla3f(-4.5, 1, -2));
	vertices.push_back(Tupla3f(-4.5, 1, 2));

	vertices.push_back(Tupla3f(3, 2, 2));
	vertices.push_back(Tupla3f(3, 2, -2));
	vertices.push_back(Tupla3f(-3.5, 2, -2));
	vertices.push_back(Tupla3f(-3.5, 2, 2));

	caras.push_back(Tupla3i(2,6,10));
	caras.push_back(Tupla3i(10,1,2));
	caras.push_back(Tupla3i(10,9,1));
	caras.push_back(Tupla3i(9,5,1));
	caras.push_back(Tupla3i(1,5,0));
	caras.push_back(Tupla3i(0,5,4));
	caras.push_back(Tupla3i(9,5,4));
	caras.push_back(Tupla3i(4,8,9));
	caras.push_back(Tupla3i(8,4,0));
	caras.push_back(Tupla3i(8,11,0));
	caras.push_back(Tupla3i(11,3,0));
	caras.push_back(Tupla3i(11,7,3));
	caras.push_back(Tupla3i(11,10,7));
	caras.push_back(Tupla3i(7,6,10));
	caras.push_back(Tupla3i(3,6,7));
	caras.push_back(Tupla3i(3,6,2));
	caras.push_back(Tupla3i(11,10,8));
	caras.push_back(Tupla3i(10,9,8));
	caras.push_back(Tupla3i(3,2,1));
	caras.push_back(Tupla3i(3,1,0));


	num_vert = vertices.size();
	num_caras = caras.size();

	nombre_obj = "Base";

	CrearParesImpares();
}

Techo::Techo(){

	vertices.push_back(Tupla3f(3, 0, 2));
	vertices.push_back(Tupla3f(3, 0, -2));
	vertices.push_back(Tupla3f(-3.5, 0, -2));
	vertices.push_back(Tupla3f(-3.5, 0, 2));

	vertices.push_back(Tupla3f(2.5, 0.75, 1.5));
	vertices.push_back(Tupla3f(2.5, 0.75, -1.5));
	vertices.push_back(Tupla3f(-3, 0.75, -1.5));
	vertices.push_back(Tupla3f(-3, 0.75, 1.5));

	caras.push_back(Tupla3i(6,2,1));
	caras.push_back(Tupla3i(6,5,1));
	caras.push_back(Tupla3i(5,1,0));
	caras.push_back(Tupla3i(5,4,0));
	caras.push_back(Tupla3i(4,0,3));
	caras.push_back(Tupla3i(4,7,3));
	caras.push_back(Tupla3i(7,3,2));
	caras.push_back(Tupla3i(7,2,6));
	caras.push_back(Tupla3i(7,4,5));
	caras.push_back(Tupla3i(7,6,5));
	caras.push_back(Tupla3i(3,1,0));
	caras.push_back(Tupla3i(3,1,2));

	num_vert = vertices.size();
	num_caras = caras.size();

	nombre_obj = "Techo";

	CrearParesImpares();
}

Esfera::Esfera(){
	vector<Tupla3f> vert;
	int nperfiles = 40;
	bool cerrar_malla = false;
	bool crear_tapas = true;

	double pi = 3.141592; 

	for(double i = pi/2; i > 0; i-= pi/20){
		vert.push_back(Tupla3f(cos(i), sin(i), 0));
	}

	vert.push_back(Tupla3f(cos(0), sin(0), 0));

	ObtenerRevolucion(vert, nperfiles, crear_tapas, cerrar_malla);	
}

Rueda::Rueda(){
	vector<Tupla3f> vert;
	int nperfiles = 40;
	bool cerrar_malla = false;
	bool crear_tapas = false;

	double pi = 3.141592; 

	vert.push_back(Tupla3f(1,0,0));

	vert.push_back(Tupla3f(1,0.2,0));

	vert.push_back(Tupla3f(0.8,0.201,0));
	vert.push_back(Tupla3f(0.6,0.201,0));
	vert.push_back(Tupla3f(0.4,0.201,0));

	ObtenerRevolucion(vert, nperfiles, crear_tapas, cerrar_malla);		
}

RuedaEnderezada::RuedaEnderezada(){
	agregar(MAT_Traslacion(0,0,2));
	agregar(MAT_Rotacion(90,1,0,0));
	agregar(MAT_Rotacion(0,0,1,0));
	agregar(new Rueda());
}

ParRuedas::ParRuedas(){
	agregar(MAT_Rotacion(0,0,0,1));
	agregar(new RuedaEnderezada());
	agregar(MAT_Escalado(1,1,-1));
	agregar(new RuedaEnderezada());
}

Ruedas::Ruedas(){
	agregar(MAT_Traslacion(0,0.8,0));
	agregar(MAT_Traslacion(-1.5,0,0));
	agregar(new ParRuedas());
	agregar(MAT_Traslacion(3,0,0));
	agregar(new ParRuedas());

	ruedasDelanteras = ((ParRuedas *)entradas[4].objeto)->obtenerPunteroMatriz(0);
	ruedasTraseras = ((ParRuedas *)entradas[2].objeto)->obtenerPunteroMatriz(0);
}

Cilindro::Cilindro(){
	vector<Tupla3f> vert;
	int nperfiles = 8;
	bool cerrar_malla = false;
	bool crear_tapas = false;

	double pi = 3.141592; 

	vert.push_back(Tupla3f(0.2, 0, 0));
	vert.push_back(Tupla3f(0.2, 1, 0));
	vert.push_back(Tupla3f(0.2, 2, 0));
	vert.push_back(Tupla3f(0.2, 3, 0));
	vert.push_back(Tupla3f(0.2, 4, 0));

	ObtenerRevolucion(vert, nperfiles, crear_tapas, cerrar_malla);	
}


Soporte::Soporte(){
	agregar(MAT_Traslacion(0,0.2,0));
	agregar(MAT_Escalado(2.5,0.4,2.5));
	agregar(new Cubo());
}

Torreta::Torreta(){
	agregar(MAT_Rotacion(0, 0, 1.0, 0));
	agregar(new Soporte());
	agregar(MAT_Traslacion(0,0.4,0));
	agregar(new Esfera());
	agregar(MAT_Traslacion(0,0.5,0));
	agregar(MAT_Rotacion(-60, 0, 0, 1));	
	agregar(new Cilindro());
	agregar(MAT_Escalado(0.7,1.5,0.7));
	agregar(new Cilindro());
}

Armazon::Armazon(){	
	agregar(new MaterialTanque(1));
	agregar(new Base());	
	agregar(new MaterialTanque());
	agregar(new Ruedas());
	agregar(MAT_Traslacion(0,2,0));
	agregar(new MaterialTanque(1));
	agregar(new Techo());

	ruedasDelanteras = ((Ruedas *)entradas[3].objeto)->delanteras();
	ruedasTraseras = ((Ruedas *)entradas[3].objeto)->traseras();
}

Tanque::Tanque(){	
	agregar(MAT_Escalado(0.1,0.1,0.1));
	agregar(MAT_Traslacion(0,0,0));
	agregar(new Armazon());
	agregar(MAT_Traslacion(0,2.75,0));	
	agregar(new MaterialTanque());
	agregar(new Torreta());

	angulo = 0;
	cx = 0;
	cy = 0;

	// Girar la torreta 
	Matriz4f * ptr_mat = ((Torreta *)entradas[5].objeto)->obtenerPunteroMatriz(0);
	Parametro param("girar torreta", ptr_mat, [=](float v){return MAT_Rotacion(v,0,1,0);}, true, 0, 90, 2.0);
	parametros.push_back(param);

	// Elevar cañón
	Matriz4f * ptr_mat2 = ((Torreta *)entradas[5].objeto)->obtenerPunteroMatriz(5);
	Parametro param2("elevar cañón", ptr_mat2, [=](float v){return MAT_Rotacion(v,0,0,1);}, true, -60, 30, 4.0);
	parametros.push_back(param2);

	// Mover tanque
	Matriz4f * ptr_mat3 = obtenerPunteroMatriz(1);
	Parametro param3("mover tanque", ptr_mat3, [=](float v){return MAT_Traslacion(v,0,0);}, true, 0, 10, 1);
	parametros.push_back(param3);

	// Girar Ruedas delanteras
	Matriz4f * ptr_mat4 = ((Armazon *)entradas[2].objeto)->delanteras();
	Parametro param4("girar ruedas delanteras", ptr_mat4, [=](float v){return MAT_Rotacion(-v,0,0,1);}, true, 0, 180*5, 1);
	parametros.push_back(param4);

	// Girar Ruedas traseras
	Matriz4f * ptr_mat5 = ((Armazon *)entradas[2].objeto)->traseras();
	Parametro param5("girar ruedas traseras", ptr_mat5, [=](float v){return MAT_Rotacion(-v,0,0,1);}, true, 0, 180*5, 1);
	parametros.push_back(param5);

	// Sacar cañón
	Matriz4f * ptr_mat6 = ((Torreta *)entradas[5].objeto)->obtenerPunteroMatriz(7);
	Parametro param6("sacar cañón", ptr_mat6, [=](float v){return MAT_Escalado(0.7,v,0.7);}, true, 1.5, 0.5, 8.0);
	parametros.push_back(param6);
}


	









