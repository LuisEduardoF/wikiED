#ifndef LIST
#define LIST
typedef struct list *tList;

tList inicializaLista();
void append(void*, tList);
void* removeLista(char*, char* nome(void*), tList);
void* searchLista(char*, char* nome(void*), tList);
void interact(void(void*), tList);
void imprimeList(tList, void(void*));
void freeLista(tList, void(void*));
#endif