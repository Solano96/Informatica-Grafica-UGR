
#include "MallaRevol.hpp"
#include "NodoGrafoEscena.hpp"
#include "NodoGrafoEscenaParam.hpp"
#include "shaders.hpp"


class PeonMadera : public NodoGrafoEscena{
public:
    PeonMadera();
};

class PeonBlanco : public NodoGrafoEscena{
public:
    PeonBlanco();
};


class PeonNegro : public NodoGrafoEscena{
public:
    PeonNegro();
};


class Lata : public NodoGrafoEscena{
public:
    Lata();
};


class Escena : public NodoGrafoEscena{
    
public:
    Escena();
};


class Base : public MallaInd{
	public:
		Base();
};

class Techo : public MallaInd{
	public:
		Techo();
};

class Armazon : public NodoGrafoEscena{
	protected:
		Matriz4f * ruedasDelanteras, * ruedasTraseras;

	public:
		Armazon();

		Matriz4f * delanteras(){
			return ruedasDelanteras;
		}

		Matriz4f * traseras(){
			return ruedasTraseras;
		}
};

class Esfera : public MallaRevol{
	public:
		Esfera();
};

class Rueda : public MallaRevol{
	public: 
		Rueda();
};


class RuedaEnderezada : public NodoGrafoEscena{
	public:
		RuedaEnderezada();
};

class ParRuedas : public NodoGrafoEscena{
	public:
		ParRuedas();

		Matriz4f * GirarRueda(){
			return obtenerPunteroMatriz(0);
		}
};

class Ruedas : public NodoGrafoEscena{

	protected:
		Matriz4f * ruedasDelanteras, * ruedasTraseras;

	public:
		Ruedas();

		Matriz4f * delanteras(){
			return ruedasDelanteras;
		}

		Matriz4f * traseras(){
			return ruedasTraseras;
		}
};

class Soporte : public NodoGrafoEscena{
	public:
		Soporte();
};

class Cilindro : public MallaRevol{
	public:
		Cilindro();
};

class Torreta : public NodoGrafoEscenaParam{
	public:
	  Torreta();

	  Matriz4f * MoverCanion(){
	  	return obtenerPunteroMatriz(5);
	  }

	  Matriz4f * GirarTorreta(){
	  	return obtenerPunteroMatriz(0);
	  }
};

class Tanque : public NodoGrafoEscenaParam{

	float angulo, cx, cy;

	public:
		Tanque();
};