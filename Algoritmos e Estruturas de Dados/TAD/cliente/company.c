#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "client.h"
#include "company.h"

struct clientList{
    Client *c;
    struct clientList *next;
};

void addClient (ClientList **clientes,Client *c){
    ClientList *pNode1 = NULL;
    ClientList *pNode2 = NULL;
    ClientList *pNode3 = NULL;
    int id;
    char *name;
    int yearOfBirth;
    float salary;

    pNode1 = (ClientList*) malloc(sizeof(ClientList*));
    pNode1->c = c;
    pNode1->next = *clientes;
   *clientes = pNode1;


}

void removeClient (ClientList **clientes, Client* c){
    char *name;
    int yearOfBirth, id, idRemove, first = 1;
    float salary;
    ClientList *clientesNew;
    readClient(c, &idRemove,&name,&yearOfBirth,&salary);

    printf(" Removendo Cliente:\n");
    while(*clientes){
        readClient((*clientes)->c, &id,&name,&yearOfBirth,&salary);
        if(id != idRemove) {
            if(first){
                clientesNew = *clientes;
                first = 0;
            } else {
                clientesNew->next = *clientes;
            }

        }
        *clientes=(*clientes)->next;
    }
    *clientes = clientesNew;
}

float salaryAverage(ClientList *clientes){
    float totalSalary = 0.0;
    char *name;
    int yearOfBirth, id, counter = 0;
    float salary;

    while(clientes){
        readClient(clientes->c, &id,&name,&yearOfBirth,&salary);
        totalSalary += salary;
        counter++;
        clientes=clientes->next;
    }
    return (totalSalary/(float)counter);
}

int countSalaryAboveSalaryAverage (ClientList *clientes){
    char *name;
    int yearOfBirth, id, counter = 0;
    float salary, salaryAvg = 0.0;
    salaryAvg = salaryAverage(clientes);
    while(clientes){
        readClient(clientes->c, &id,&name,&yearOfBirth,&salary);
        if(salary > salaryAvg)
            counter++;

        clientes=clientes->next;
    }
    printf("Clientes com média salarial acima da média(%.2f): %d\n",salaryAvg,counter);
    return counter;
}

int countClientsBetweenYear (ClientList *clientes,int startYearOfBirth,int endYearOfBirth){
    char *name;
    int yearOfBirth, id, counter = 0;
    float salary;
    while(clientes){
        readClient(clientes->c, &id,&name,&yearOfBirth,&salary);
        if(yearOfBirth >=startYearOfBirth && yearOfBirth<=endYearOfBirth)
            counter++;

        clientes=clientes->next;
    }
    printf("Clientes com data de nascimento entre %d e %d: %d\n",startYearOfBirth,endYearOfBirth,counter);
    return counter;
}

void showClients(ClientList *clientes){
    char *name;
    int yearOfBirth, id;
    float salary;
    while(clientes){
        readClient(clientes->c, &id,&name,&yearOfBirth,&salary);
        printf("id=%d | nome= %s | ano de nascimento=%d | y= %.2f\n", id, name,yearOfBirth,salary);
        clientes=clientes->next;
    }
}
