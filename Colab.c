#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editores.h"
#include "Colab.h"
struct colab{
    tEditores editor;
    int retirado, excluido;
    char* file;
};

tColab createColab(void* editor, char* file){
    tColab new = malloc(sizeof(tColab));
    new->editor = editor;
    
    new->file = strdup(file);
    new->retirado = new->excluido = 0;

    addContribuicaoEditor(new, new->editor);
    return new;
}
void retiraColab(void* clb){
    tColab c = clb;
    c->retirado = 1;
}
void excluiColab(void* clb){
    tColab c = clb;
    c->excluido = 1;
}
void printColab(void* clb){
    tColab c = clb;
    if(c->excluido)
        return;
    printf("%s %s ", edtName(c->editor), c->file);
    if(c->retirado)
        printf("<<retirada>>");
    printf("\n");
}
void freeColab(void* clb){
    tColab c = clb;
    free(c->file);
    free(c);
}
char* colabName(void* clb){
    tColab c = clb;
    return c->file;
}
char* autor(void* clb){
    tColab c = clb;
    return edtName(c->editor);
}