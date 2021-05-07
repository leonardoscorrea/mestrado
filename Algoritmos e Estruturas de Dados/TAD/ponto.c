#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "ponto.h"

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) __HadError=true;goto ExitJmp;

#define PI 3.14159265358979323846264338327950288

struct ponto{
    float x;
    float y;
};

void atribui (Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

Ponto* cria (float x, float y){
    try
    {
        Ponto* p = (Ponto*) malloc(sizeof(Ponto));
        atribui(p,x,y);
        return p;
    }
    catch(...)
    {
        printf("Error ao criar ponto\n");
        return NULL;
    }
}

void libera (Ponto* p){
    free(p);
}

void acessa (Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

float distancia (Ponto* p1, Ponto* p2){
    float distanciaX = p2->x - p1->x;
    float distanciaY = p2->y - p1->y;
    return sqrt((distanciaX*distanciaX) + (distanciaY * distanciaY));
}

/*NOVOS METODOS*/
//distância entre ponto 00 e p
//NORMA(DISTANCIA ENTRE UM PONTO E A ORIGEM)
float rho(Ponto* p){
    Ponto* pOrigem = (Ponto*) malloc(sizeof(Ponto));
    atribui(pOrigem,0.0,0.0);
    float retorno = distancia(pOrigem,p);
    return retorno;
}

float produtoInterno(Ponto* p1, Ponto* p2){
    return p1->x*p2->x + p1->y*p2->y;
}

//ângulo da reta formada entre origem e o ponto e a abscissa(eixo x)
float theta(Ponto* p){
    Ponto* pAbscissa = (Ponto*) malloc(sizeof(Ponto));
    atribui(pAbscissa,p->x,0.0);
    float normaAbscissa = rho(pAbscissa);
    float normaPonto = rho(p);
    float pInterno = produtoInterno(pAbscissa, p);
    float resultado = pInterno/(normaAbscissa*normaPonto);
    //printf("angulo = %.3f\n", resultado);
    return 0.0;
}

//move ponto a para ponto b
void translate (Ponto* a, Ponto* b){
    atribui(a,b->x,b->y);
}

//o que seria escalonar um ponto?
Ponto* scale (float factor){
    return NULL;
}

// o que seria rotacionar um ponto?
Ponto* rotate(float angle){
    return NULL;
}
