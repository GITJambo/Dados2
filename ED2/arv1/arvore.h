#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct arvore {
  char info;
  int altura;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

int buscar (Arvore *a, int v);

Arvore* inserir (Arvore *a, int v);

Arvore* remover (Arvore *a, int v);

int Min(Arvore *a);
int Max(Arvore *a);

void imprime_decrescente(Arvore *a);

int* geraVetor(Arvore* a);
