#ifndef PAGINA
#define PAGINA
typedef struct pagina *tPagina;

tPagina inicializePagina(char* nome, char* file);
void addContribuicao(void* edt, char* file, tPagina p);
void removeContribuicao(char *edtName, char* file, tPagina p);
void addLink(void* link, tPagina);
void removeLink(void* link, tPagina);
void printPagina(void* pagina);
char* pagName(void* pagina);
void freePagina(void* pagina);
#endif