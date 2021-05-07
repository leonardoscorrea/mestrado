#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "client.h"

struct client{int id; char *name; int yearOfBirth; float salary;};

//CRUD
Client* createClient (int id, char *name, int yearOfBirth, float salary){
    Client* c = (Client*) malloc(sizeof(Client));
    c->id           = id;
    c->name         = name;
    c->yearOfBirth  = yearOfBirth;
    c->salary       = salary;
    return c;
}
void readClient (Client* c, int* id, char* *name, int* yearOfBirth, float* salary){
    *id          = c->id;
    *name        = c->name;
    *yearOfBirth = c->yearOfBirth;
    *salary      = c->salary;
}

void updateClient (Client* c,int id, char *name, int yearOfBirth, float salary){
    c->id           = id;
    c->name         = name;
    c->yearOfBirth  = yearOfBirth;
    c->salary       = salary;
}
void deleteClient (Client* c){
    free(c);
}
