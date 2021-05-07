typedef struct client Client;
//CRUD
Client* createClient (string name, int yearOfBirth, float salary);
void readClient (Client* c, string *name, int* yearOfBirth, float* salary);
update updateClient (Client* c, string name, int yearOfBirth, float salary);
bool deleteClient (Ponto* p);
