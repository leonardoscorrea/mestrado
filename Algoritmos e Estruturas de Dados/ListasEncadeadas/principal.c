#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "company.h"

int main()
{
    int id;
    char *name;
    int yearOfBirth;
    float salary;
    ClientList *clients = NULL, *clients2 = NULL;

    printf("cadastrando clientes\n");
    Client *c1 = createClient(1, "Leonardo Correa", 1985, 1500.0);
    Client *c2 = createClient(2, "Teste", 1977, 1100.0);
    Client *c3 = createClient(3, "Fran", 1996, 1230.0);
    Client *c4 = createClient(4, "Jose", 1999, 1650.0);
    Client *c5 = createClient(5, "Maria", 1999, 1880.0);
    addClient(&clients, c1);
    addClient(&clients, c2);
    addClient(&clients, c3);
    addClient(&clients, c4);
    addClient(&clients2, c1);
    addClient(&clients2, c2);
    addClient(&clients2, c3);
    addClient(&clients2, c5);
    showClients(clients);
    countSalaryAboveSalaryAverage(clients);
    countClientsBetweenYear(clients, 1980, 2000);
    countClients(clients);
    showClientsInverse(clients);
    if (compareClientLists(clients, clients2))
    {
        printf("Listas Iguais\n");
    }
    else
    {
        printf("Listas Diferentes\n");
    }

    return 0;
}
