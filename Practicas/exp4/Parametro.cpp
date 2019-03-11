#include <cmath>
#include "Parametro.hpp"


Parametro::Parametro(const std::string & p_descripcion, Matriz4f * p_ptr_mat, TFuncionCMF p_fcm, 
					  bool p_acotado, float p_c, float p_s, float p_f){

	valor_norm = 0;
	velocidad = 0.001;
	descripcion = p_descripcion;
	ptr_mat = p_ptr_mat;
	fun_calculo_matriz = p_fcm;
	acotado = p_acotado;
	c = p_c;
	s = p_s;
	f = p_f;
}


void Parametro::siguiente_cuadro(){	
	valor_norm += velocidad;
	if(!acotado){
		*ptr_mat = fun_calculo_matriz(c+s*valor_norm);
	}
	else{
		double pi = 3.141592;
		*ptr_mat = fun_calculo_matriz(c+s*sin(f*2*pi*valor_norm));
	}
}	

void Parametro::reset(){
	valor_norm = 0;
	velocidad = 0.001f;
	siguiente_cuadro();
} 	

void Parametro::incrementar(){
	valor_norm += 0.001;

	if(!acotado){
		*ptr_mat = fun_calculo_matriz(c+s*valor_norm);
	}
	else{
		double pi = 3.141592;
		*ptr_mat = fun_calculo_matriz(c+s*sin(f*2*pi*valor_norm));
	}
}

void Parametro::decrementar(){
	valor_norm -= 0.001;
	
	if(!acotado){
		*ptr_mat = fun_calculo_matriz(c+s*valor_norm);
	}
	else{
		double pi = 3.141592;
		*ptr_mat = fun_calculo_matriz(c+s*sin(f*2*pi*valor_norm));
	}
}	

void Parametro::acelerar(){
	velocidad += 0.001;
}	

void Parametro::decelerar(){
	velocidad -= 0.001;

	if(velocidad < 0) 
		velocidad = 0;
}	

float Parametro::leer_valor_actual(){
	if(!acotado){
		return c+s*valor_norm;
	}
	else{
		double pi = 3.141592;
		return c+s*sin(f*2*pi*valor_norm);
	}
}

float Parametro::leer_velocidad_actual(){
	return velocidad;
}

std::string Parametro::leer_descripcion(){
	return descripcion;
}