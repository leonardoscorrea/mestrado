typedef struct ponto Ponto;

Ponto* cria (float x, float y);

void libera (Ponto* p);

void acessa (Ponto* p, float* x, float* y);

void atribui (Ponto* p, float x, float y);

float distancia (Ponto* p1, Ponto* p2);

/*NOVOS METODOS*/
float rho(Ponto* p); //distância entre ponto 00 e p

float theta(Ponto* p); //ângulo da reta formada entre origem e o ponto e a abscissa(eixo x)

void translate (Ponto* a, Ponto* b); //move ponto a para ponto b

Ponto* scale (float factor); //o que seria escalonar um ponto?

Ponto* rotate(float angle); // o que seria rotacionar um ponto?
