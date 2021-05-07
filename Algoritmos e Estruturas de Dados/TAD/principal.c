#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"




int main(){
    float vX, vY;

    printf("Cria ponto qualquer\n");
    Ponto *p1 = cria(7.0, 2.0);
    printf("acessa e printa\n");
    acessa(p1, &vX, &vY);
    printf("x= %.2f | y= %.2f\n", vX, vY);
    printf("calcula angulo\n");
    printf("cosseno do angulo = %.2f\n", theta(p1));
    printf("Verifica distancia para origem\n");
    float dis = rho(p1);
    printf("distancia da origem = %.2f\n", dis);
    printf("Cria outro ponto\n");
    Ponto *p2 = cria(6.0, 3.0);
    acessa(p2, &vX, &vY);
    printf("x= %.2f | y= %.2f\n", vX, vY);
    printf("Translada o segundo ponto para o primeiro\n");
    translate(p2,p1);
    acessa(p2, &vX, &vY);
    printf("x= %.2f | y= %.2f\n", vX, vY);

    return 0;
}
