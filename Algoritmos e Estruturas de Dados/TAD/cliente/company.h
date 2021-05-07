typedef struct clientList ClientList;

void addClient (ClientList **clientes,Client *c);
void removeClient (ClientList **clientes, Client* c);
int countSalaryAboveSalaryAverage (ClientList *clientes);
int countClientsBetweenYear (ClientList *clientes,int startYearOfBirth,int endYearOfBirth);
void showClients(ClientList *clientes);
