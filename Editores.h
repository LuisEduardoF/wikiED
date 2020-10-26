#ifndef EDITORES
#define EDITORES
typedef struct editores *tEditores;

tEditores inicializeEditor(char* nome);
void printEditor(void*);
void addContribuicaoEditor(void* colab, tEditores);
void excluiContribuicaoEditor(void* colab, tEditores);
char* edtName(void*);
void freeEditor(void*);
#endif