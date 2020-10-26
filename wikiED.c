#include <stdio.h>
#include <stdlib.h>
#include "wikiED.h"
#include "Editores.h"
#include "Pagina.h"
#include "List.h"
struct wikiED{
    tList Pagina, Editores;
};

tWikiED inicializaWiked(){
    tWikiED new = malloc(sizeof(tWikiED));
    
    new->Pagina = inicializaLista();
    new->Editores = inicializaLista();

    return new;
}
void inserePagina(char* nome, char* file, tWikiED w){
    tPagina pag = inicializePagina(nome, file);
    append(pag, w->Pagina);
}
void retiraPagina(char* namePag, tWikiED w){
    tPagina pag = removeLista(namePag, pagName, w->Pagina);
    if(pag != NULL)
        freePagina(pag);
}
void insereEditor(char* nome, tWikiED w){
    tEditores edt = inicializeEditor(nome);
    append(edt, w->Editores);
}
void retiraEditor(char* nameEdt, tWikiED w){
    tEditores edt = removeLista(nameEdt, edtName, w->Editores);
    if(edt != NULL)
        freeEditor(edt);
}
void insereContribuicao(char* namePag, char* nameEdt, char* file, tWikiED w){
    tPagina atualPag = searchLista(namePag, pagName, w->Pagina);
    tEditores atualEdit = searchLista(nameEdt, edtName, w->Editores);
    if(atualPag != NULL && atualEdit != NULL)
        addContribuicao(atualEdit, file, atualPag);
}
void retiraContribuicao(char* namePag, char* nameEdt, char* file, tWikiED w){
    tPagina atualPag = searchLista(namePag, pagName, w->Pagina);
    if(atualPag != NULL)
        removeContribuicao(nameEdt, file, atualPag);
}
void insereLink(char* namePag1, char* namePag2, tWikiED w){
    tPagina PaginaP = searchLista(namePag1, pagName, w->Pagina), PaginaS = searchLista(namePag2, pagName, w->Pagina);
    addLink(PaginaS, PaginaP);
}
void retiraLink(char* namePag1, char* namePag2, tWikiED w);
int caminho(char* namePag1, char* namePag2, tWikiED w);
void imprimePagina(char* namePag1, tWikiED w);
void imprimeWiki(tWikiED w){
    printf("Paginas:\n");
    imprimeList(w->Pagina, printPagina);
}
void freeWiki(tWikiED w){
    freeLista(w->Pagina, freePagina);
    freeLista(w->Editores, freeEditor);
    free(w);
}
