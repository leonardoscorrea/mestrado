#include <stdlib.h>
#include <stdio.h>
#include "listaInteiros.h"

int main()
{
    Lista *l;
    inicializarLista(&l);
    inserirInicio(&l,10);
    imprimeLista(l);
    inserirInicio(&l,15);
    inserirInicio(&l,32);
    inserirInicio(&l,45);
    imprimeLista(l);
    //exercício 2
    printf("posição do valor buscado é %d\n",buscarValor(l,32));
    //exercício 3
    inserirAposValor(&l,15,66);
    imprimeLista(l);
    return 0;
}
