#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "client.h"
#include "company.h"

struct clientList
{
    Client *c;
    struct clientList *next;
};

void addClientAtFirst(ClientList **clientes, Client *c)
{
    ClientList *pNode1 = NULL;
    ClientList *pNode2 = NULL;
    ClientList *pNode3 = NULL;
    int id;
    char *name;
    int yearOfBirth;
    float salary;

    pNode1 = (ClientList *)malloc(sizeof(ClientList *));
    pNode1->c = c;
    pNode1->next = *clientes;
    *clientes = pNode1;
}

void addClient(ClientList **clientes, Client *c)
{
    ClientList *pNode1 = NULL;
    ClientList *pNode2 = NULL;
    ClientList *pNode3 = NULL;
    int id;
    char *name;
    int yearOfBirth;
    float salary;

    pNode2 = (*clientes);

    pNode1 = (ClientList *)malloc(sizeof(ClientList *));
    pNode1->c = c;
    pNode1->next = NULL;
    if ((*clientes) == NULL)
    {
        *clientes = pNode1;
    }
    else
    {
        while (*clientes)
        {
            if ((*clientes)->next == NULL)
            {
                (*clientes)->next = pNode1;
                (*clientes) = pNode2; //seta para o primeiro nó da lista
                break;
            }
            *clientes = (*clientes)->next;
        }
    }
    //pNode1->next = *clientes;
    //*clientes = pNode1;
}

void removeClient(ClientList **clientes, Client *c)
{
    char *name;
    int yearOfBirth, id, idRemove, first = 1;
    float salary;
    ClientList *clientesNew;
    readClient(c, &idRemove, &name, &yearOfBirth, &salary);

    printf(" Removendo Cliente:\n");
    while (*clientes)
    {
        readClient((*clientes)->c, &id, &name, &yearOfBirth, &salary);
        if (id != idRemove)
        {
            if (first)
            {
                clientesNew = *clientes;
                first = 0;
            }
            else
            {
                clientesNew->next = *clientes;
            }
        }
        *clientes = (*clientes)->next;
    }
    *clientes = clientesNew;
}

float salaryAverage(ClientList *clientes)
{
    float totalSalary = 0.0;
    char *name;
    int yearOfBirth, id, counter = 0;
    float salary;

    while (clientes)
    {
        readClient(clientes->c, &id, &name, &yearOfBirth, &salary);
        totalSalary += salary;
        counter++;
        clientes = clientes->next;
    }
    return (totalSalary / (float)counter);
}

int countSalaryAboveSalaryAverage(ClientList *clientes)
{
    char *name;
    int yearOfBirth, id, counter = 0;
    float salary, salaryAvg = 0.0;
    salaryAvg = salaryAverage(clientes);
    while (clientes)
    {
        readClient(clientes->c, &id, &name, &yearOfBirth, &salary);
        if (salary > salaryAvg)
            counter++;

        clientes = clientes->next;
    }
    printf("Clientes com média salarial acima da média(%.2f): %d\n", salaryAvg, counter);
    return counter;
}

int countClientsBetweenYear(ClientList *clientes, int startYearOfBirth, int endYearOfBirth)
{
    char *name;
    int yearOfBirth, id, counter = 0;
    float salary;
    while (clientes)
    {
        readClient(clientes->c, &id, &name, &yearOfBirth, &salary);
        if (yearOfBirth >= startYearOfBirth && yearOfBirth <= endYearOfBirth)
            counter++;

        clientes = clientes->next;
    }
    printf("Clientes com data de nascimento entre %d e %d: %d\n", startYearOfBirth, endYearOfBirth, counter);
    return counter;
}

int countClients(ClientList *clientes)
{
    int counter = 0;
    while (clientes)
    {
        counter++;
        clientes = clientes->next;
    }
    printf("Quantidade Total de Clientes: %d\n", counter);
    return counter;
}

void showClients(ClientList *clientes)
{
    char *name;
    int yearOfBirth, id;
    float salary;
    while (clientes)
    {
        readClient(clientes->c, &id, &name, &yearOfBirth, &salary);
        printf("id=%d | nome= %s | ano de nascimento=%d | y= %.2f\n", id, name, yearOfBirth, salary);
        clientes = clientes->next;
    }
}

void showClientsInverse(ClientList *clientes)
{
    ClientList *pNode = NULL;
    char *name;
    int yearOfBirth, id;
    float salary;
    while (clientes)
    {
        readClient(clientes->c, &id, &name, &yearOfBirth, &salary);
        addClientAtFirst(&pNode, clientes->c);
        clientes = clientes->next;
    }
    showClients(pNode);
}

int compareClientLists(ClientList *clientes1, ClientList *clientes2)
{
    int qty1, qty2;
    qty1 = countClients(clientes1);
    qty2 = countClients(clientes2);
    if (qty1 != qty2)
        return 0;
    else
    {
        while (clientes1 && clientes2)
        {
            if (!compareClients(clientes1->c, clientes2->c))
                return 0;
            clientes1 = clientes1->next;
            clientes2 = clientes2->next;
        }
        return 1;
    }
    return 1;
}

int compareClients(Client *c1, Client *c2)
{
    char *name1, *name2;
    int yearOfBirth1, id1, yearOfBirth2, id2;
    float salary1, salary2;
    readClient(c1, &id1, &name1, &yearOfBirth1, &salary1);
    readClient(c2, &id2, &name2, &yearOfBirth2, &salary2);
    //if ((id1 == id2) && strcmp(name1, name2) && (yearOfBirth1 == yearOfBirth2) && (salary1 == salary2))
    if ((id1 == id2) && (yearOfBirth1 == yearOfBirth2) && (salary1 == salary2) && name1 == name2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}