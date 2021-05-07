#include <stdlib.h>
#include <stdio.h>
#include "student.h"




int main(){
    int id, birth, registration;
    char *name;
    printf("Cadastra Aluno \n");
    Student *c1 = createStudent(1, "Leonardo Correa", 19850730,1234);
    showStudent(c1);
    printf("Altera Cadastro Aluno \n");
    readStudent(c1, &id,&name,&birth,&registration);
    updateStudent (&c1, 1, "Leonardo da Silva", 19850730, 123456);
    showStudent(c1);

    return 0;
}
