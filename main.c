#include <stdio.h>
#include "wikiED.h"
int main(){
    tWikiED wiked = inicializaWiked();
    inserePagina("Fisica", "fisica.txt", wiked);  inserePagina("Artes", "artes.txt", wiked); inserePagina("UFES", "ufes.txt", wiked);
    retiraPagina("Psicologia", wiked);
    insereEditor("Pedro", wiked);
    insereEditor("Maria", wiked);
    insereEditor("Joao", wiked);
    insereEditor("Ana", wiked);
    insereEditor("Edu", wiked);
    retiraEditor("Edu", wiked);

    insereContribuicao("Fisica", "Pedro", "c1.txt", wiked);
    insereContribuicao("Fisica", "Maria", "c2.txt", wiked);
    insereContribuicao("Fisica", "Pedro", "c3.txt", wiked);
    insereContribuicao("Artes", "Maria", "c4.txt", wiked);
    insereContribuicao("Artes", "Ana", "c5.txt", wiked);
    retiraContribuicao("Artes", "Ana", "c6.txt", wiked);

    imprimeWiki(wiked);
    freeWiki(wiked);
    return 0;
}