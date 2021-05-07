typedef struct client Client;
//CRUD
Client* createClient (int id, char *name, int yearOfBirth, float salary);
void readClient (Client* c, int* id, char* *name, int* yearOfBirth, float* salary);
void updateClient (Client* c, int id, char *name, int yearOfBirth, float salary);
void deleteClient (Client* c);
