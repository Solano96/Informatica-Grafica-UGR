#include <functional> // incluye std::function

#include "matrices-tr.hpp"

// tipo para las funciones que calculan una Matriz4f a partir de un float
typedef std::function< Matriz4f(float)> TFuncionCMF;


class Parametro{
	private:
		std::string 
			descripcion; //descripción del grado de libertad (para seguimiento)
		bool 
			acotado; // true si el valor oscila entre dos valores, false si no
		TFuncionCMF 
			fun_calculo_matriz; // función que produce una nueva matriz a partir de un valor flotante
		float 
			c, // valor inicial (y también central para grados acotados)
			s, // semiamplitud (si acotado), o factor de escala (si no acotado)
			f; // si acotado: frecuencia (ciclos por unidad del valor normalizado)
		Matriz4f *  
			ptr_mat; // puntero a la matriz dentro del modelo
		float 
			valor_norm, // valor actual, normalizado, no acotado (crece desde 0)
			velocidad;  // velocidad actual (se suma al valor_norm)

		public: 
			// crear grado de libertad no acotado
			Parametro(const std::string & p_descripcion, Matriz4f * p_ptr_mat, TFuncionCMF p_fcm, 
					  const bool p_acotado, float p_c, float p_s, float p_f);
			Parametro();

			void siguiente_cuadro(); 		// actualizar valor y matriz al siguiente frame
			void reset();			 		// vuelve al estado inicial
			void incrementar();		 		// incrementar el valor 
			void decrementar();		 		// decrementar el valor
			void acelerar();		 		// acelerar (aumentar la velocidad)
			void decelerar();		 		// decelerar (disminuir la velocidad)
			float leer_valor_actual();  	// devuelve el valor actual (valor de q)
			float leer_velocidad_actual(); 	// devuelve velocidad actual
			std::string leer_descripcion();	// devuelve descripción
};







