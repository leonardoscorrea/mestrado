typedef struct clientList ClientList;

void addClient(ClientList **clientes, Client *c);
void addClientAtFirst(ClientList **clientes, Client *c);
void removeClient(ClientList **clientes, Client *c);
int countSalaryAboveSalaryAverage(ClientList *clientes);
int countClientsBetweenYear(ClientList *clientes, int startYearOfBirth, int endYearOfBirth);
int countClients(ClientList *clientes);
void showClients(ClientList *clientes);
void showClientsInverse(ClientList *clientes);
int compareClients(Client *c1, Client *c2);
int compareClientLists(ClientList *clientes1, ClientList *clientes2);
