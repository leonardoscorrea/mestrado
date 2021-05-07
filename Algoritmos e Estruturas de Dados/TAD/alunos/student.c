#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "student.h"

struct student{int id; char *name; int birth; int registration;};

//CRUD
Student* createStudent (int id, char *name, int birth, int registration){
    Student* c = (Student*) malloc(sizeof(Student));
    c->id           = id;
    c->name         = name;
    c->birth        = birth;
    c->registration = registration;
    return c;
}
void readStudent (Student* c, int* id, char* *name, int* birth, int* registration){
    *id          = c->id;
    *name        = c->name;
    *birth       = c->birth;
    *registration= c->registration;
}

void updateStudent (Student** c, int id, char *name, int birth, int registration){
    (*c)->id           = id;
    (*c)->name         = name;
    (*c)->birth        = birth;
    (*c)->registration = registration;
}

void deleteStudent (Student* c){
    free(c);
}

void showStudent(Student* c){
    int id, birth, registration;
    char *name;
    readStudent(c, &id,&name,&birth,&registration);
    printf("id = %d | name = %s | birth = %d | registration = %d\n",id,name,birth,registration);
}
