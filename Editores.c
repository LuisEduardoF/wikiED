#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editores.h"
#include "Colab.h"
#include "List.h"

struct editores{
    char* name;
    tList Colab;
};
tEditores inicializeEditor(char* name){
    tEditores new = malloc(sizeof(tEditores));
    new->name = strdup(name);
    new->Colab = inicializaLista();

    return new;
}
void printEditor(void* edt){
    tEditores e = edt;
    printf("%s\n", e->name);
    printf("Colaborações\n");
    imprimeList(e->Colab, printColab);
}
char* edtName(void* edt){
    tEditores e = edt;
    return e->name;
}
void addContribuicaoEditor(void* colab, tEditores edt){
    append(colab, edt->Colab);
}
void excluiContribuicaoEditor(void* colab, tEditores edt){
    tColab atualColab = searchLista(colabName(colabName), colabName, edt->Colab);
    excluiColab(atualColab);
}
void freeEditor(void* edt){
    tEditores e = edt;
    free(e->name);
    freeLista(e->Colab, excluiColab);
    free(e);
}