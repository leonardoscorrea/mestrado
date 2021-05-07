typedef struct student Student;
//CRUD
Student* createStudent (int id, char *name, int birth, int registration);
void readStudent (Student* c, int* id, char* *name, int* birth, int* registration);
void updateStudent (Student** c, int id, char *name, int birth, int registration);
void deleteStudent (Student* c);
void showStudent(Student* c);
