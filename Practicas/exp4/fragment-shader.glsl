void main(){
	gl_FragColor = gl_Color;
}

/*
#version 130
const int nf = 2;

// parametros de entrada (uniform)
uniform vec3 vecFue[nf];
uniform vec3 colFue[nf];
uniform vec3 colMat[4];
uniform float expPse;
uniform sampler2D textura;
uniform int usarText;


// parametros de entrada (interpolados), todos en coords de cámara
in vec4 posPunto;
in vec3 normalPunto;
in vec3 vecObservador;
in vec2 coordsText;

// Función FGE

float FGE(float e, vec3 n, vec3 v, vec3 l){
	return pow(max(dot(normalize(v+1),n),0.0),e);
}

vec3 EvaluarMIL(vec3 m[4], vec3 t, float e, vec3 n, vec3 v, vec3 l, vec3 f){
	vec3 cEmis = m[0], cAmb = f*t*m[1], cDif = f*t*m[2], cEsp = f*m[3];

	//calcular color resultado

	vec3 res = cEmis + cAmb;
	float nl = dot(n,l);
	if(0.0 < nl)
		res += cDif*nl + cEsp*FGE(e,n,v,l);
	return res;
}

void main(){
	vec3 
		norm = normalize(normalPunto.xyz),
		vecobs = normalize(vecObservador),
		colRes = vec3(0.0,0.0,0.0),
		colText = vec3(1.0,1.0,1.0);

		// si se debe usar la textura consultarla
		if(usarText != 0)
			colText = texture(textura, coordsText).rgb;

		// para cada fuente de luz, sumar su contrib al MIL
		for(int i = 0; i < nf; i++){
			vec3 vluz = normalize(vecFue[i]);
			colRes += EvaluarMIL(colMat, colText, expPse, norm, vecobs, vluz, colFue[i]);
		}
		// escribir en 'glFragColor' para producir resultado (color del fragmento)
		gl_FragColor = vec4(colRes, 1.0);
}
*/
