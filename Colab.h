#ifndef COLAB
#define COLAB
typedef struct colab *tColab;

tColab createColab(void* editor, char* file);
void printColab(void*);
void retiraColab(void*);
void excluiColab(void*);
char* colabName(void*);
char* autor(void*);
void freeColab(void*);
#endif