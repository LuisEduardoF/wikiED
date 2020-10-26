#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
typedef struct node{
    void* info;
    struct node *prox;
}*tNode;
tNode inicializeNode(void* info){
    tNode new = malloc(sizeof(tNode));
    new->info = info;
    new->prox = NULL;
    
    return new;
}
struct list{
    tNode fst, end;
};
int isEmpty(tList l){
    return l == NULL;
}
tList inicializaLista(){
    tList new = malloc(sizeof(tList));
    new->fst = new->end = NULL;

    return new;
}
void append(void *info, tList l){
    if(!isEmpty(l)){
        tNode new = inicializeNode(info);
        if(l->fst == NULL && l->end == NULL){
            l->fst = l->end = new;
        }
        else{
            l->end->prox = new;
            l->end = new;
        }
    }
}
void* removeLista(char* name, char* f(void*), tList l){
    if(!isEmpty(l)){
        tNode p = l->fst, ant = NULL;
        void *info;
        for(p = l->fst; p != NULL; p = p->prox){
            if(strcmp(name, f(p->info)) == 0){
                break;
            }
            ant = p;
        }
        if(p == NULL){
            printf("%s não encontrada(o)...\n", name);
            return NULL;
        }
        if(p == l->fst && p == l->end){
            l->fst = l->end = NULL;
        }
        else if(p == l->fst){
            l->fst = p->prox;
        }
        else if(p == l->end){
            l->end = ant;
            l->end->prox = NULL;
        }
        else{
            ant->prox = p->prox;
        }
        info = p->info;
        free(p);
        return info;
    }
    else{
        printf("Deu erro na remove... Lista Vazia\n");
        return NULL;
    }
}
void* searchLista(char* name, char* f(void*), tList l){
    if(!isEmpty(l)){
        tNode p = l->fst;
        for(p = l->fst; p != NULL; p = p->prox){
            if(!strcmp(name, f(p->info)))
                break;
        }
        if(p == NULL){
            return NULL;
        }
        else
            return p->info;
        
    }
    else{
        printf("Deu erro na search... Lista Vazia\n");
        return NULL;
    }
}
void imprimeList(tList l, void f(void*)){
    if(!isEmpty(l) && l->fst != NULL){
        for(tNode p = l->fst; p != NULL; p = p->prox){
            f(p->info);
        }
    }
    else{
        printf("Lista Vazia...\n");
        return;
    }
}
void freeLista(tList l, void f(void*)){
    if(!isEmpty(l)){
        tNode aux = NULL;
        for(tNode p = l->fst; p != NULL; p = aux){
            aux = p->prox;
            f(p->info);
            free(p);
        }
        free(l);
    }
}

