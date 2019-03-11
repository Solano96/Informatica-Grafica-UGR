// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************

#ifndef IG_PRACTICAS_HPP
#define IG_PRACTICAS_HPP

#include "PilaLIFOMatrices.hpp"
#include "material.hpp"

// ---------------------------------------------------------------------
// tipo de datos enumerado para los modos de visualización:

typedef enum
{
   modoPuntos,
   modoAlambre,
   modoSolido,
   modoAjedrez,
   modoColor,
   modoSombreadoPlano,
   modoSombreadoSuave
}
   ModosVisu;

const int numModosVisu = 4 ; // numero de modos distintos

// --------------------------------------------------------------------

class PilaMateriales{
private:
   Material * actual; // material actualmente activado (NULL al inicio)
   std::vector<Material *> pila; // materiales activados antes

public:
   PilaMateriales(){
      actual = NULL;
   }

   void push(){
      pila.push_back(actual);
   }

   void pop(){
      actual = pila[pila.size()-1];
      pila.pop_back();

      if(actual != NULL)
         actual->activar();
   }

   void activarMaterial(Material * material){
      actual = material;

      if(actual != NULL)
         actual->activar();
   }
};


// --------------------------------------------------------------------

class ContextoVis
{
   public:
      ModosVisu modoVisu ; // modo de visualización actual
      PilaLIFOMatrices pilaModelview;
      PilaMateriales pilaMateriales;
		bool modoDiferido ;  
      ContextoVis() { 
			modoVisu = modoAlambre ; // poner alambre por defecto
			modoDiferido = false;
		} 
};

#endif
