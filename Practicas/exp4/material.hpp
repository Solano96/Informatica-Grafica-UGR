
#ifndef IG_MATERIAL_HPP
#define IG_MATERIAL_HPP


#include "textura.hpp"
#include "tuplasg.hpp"
#include "aux.hpp"

class Material{
	public:
		virtual void activar() = 0;
};


class MaterialEstandar : public Material{
	public:
		Textura * textura; // punt. a textura (NULL si no hay)
		Tupla4f color[4]; // 0 = M_e, 1 = M_a, 2 = M_d, 3 = M_s
		float exponente; // exponente (e)

		virtual void activar(); // activa material
};

class MaterialBarra : public MaterialEstandar{
	public:
	    MaterialBarra() ;
};

class MaterialMoneda : public MaterialEstandar{
	public:
	    MaterialMoneda() ;
};

class MaterialLata : public MaterialEstandar{
	public:
    	MaterialLata() ;
};

class MaterialTapasLata : public MaterialEstandar{
	public:
	    MaterialTapasLata() ;
};

class MaterialPeonMadera : public MaterialEstandar{
	public:
	    MaterialPeonMadera() ;
};

class MaterialPeonBlanco : public MaterialEstandar{
	public:
	    MaterialPeonBlanco() ;
};

class MaterialPeonNegro : public MaterialEstandar{
	public:
	    MaterialPeonNegro() ;
};

class MaterialTanque : public MaterialEstandar{
	public:
		MaterialTanque(int m = 0);
};

class MaterialRuedas : public MaterialEstandar{
	public:
		MaterialRuedas(int m = 0);
};

class MaterialInventado : public MaterialEstandar{
	public:
	    MaterialInventado() ;
};

#endif