#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"
#include "Colab.h"
#include "List.h"

struct pagina{
    char *name, *file;
    tList Colab, Links;
};
tPagina inicializePagina(char* name, char* file){
    tPagina new = malloc(sizeof(tPagina));
    new->Colab = inicializaLista();
    //new->Links = inicializaLista();
    new->name = strdup(name);
    new->file = strdup(file);

    return new;
}
void addContribuicao(void* edit, char* file, tPagina p){
    tColab contribuicao = createColab(edit, file);
    append(contribuicao, p->Colab);
}
void removeContribuicao(char* edtName, char* file, tPagina p){
    tColab atualColab = searchLista(file, colabName, p->Colab);
    if(atualColab != NULL){
        if(strcmp(edtName, autor(atualColab)) == 0)
        retiraColab(atualColab);
    }
}
void addLinks(void* link, tPagina p){
    append(link, p->Links);
}
void printPagina(void* pg){
    tPagina p = pg;
    printf("%s\n", p->name);
    imprimeList(p->Colab, printColab);
}
void freePagina(void* pg){
    tPagina p = pg;
    free(p->name);
    free(p->file);
    freeLista(p->Colab, freeColab);
    free(p);
}
char* pagName(void* pg){
    tPagina p = pg;
    return p->name;
}