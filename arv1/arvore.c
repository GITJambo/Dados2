#include "arvore.h"

int buscar (Arvore *a, int v) {
  if (a == NULL) {
    return 0;
  }
  else if (v < a->info) {
    return buscar (a->esq, v);
  }
  else if (v > a->info) {
    return buscar (a->dir, v);
  }
  else {
    return 1;
  }
}
/*
Arvore* Balancear(Arvore* t) {
    if (t->altura == 2 ) {
      if (t->esq->altura > 0) {
        printf("\nRotação para direita.\n"); 
        //t = doRightRotation( t );
      }
      else{
        printf("\nRotação dupla para direita.");
        //t = doDoubleRightRotation( t );
      }
    }
    else if ( t->altura == -2 ) {
            if ( t->dir->altura < 0 ){
              printf("\nRotação para esquerda.");
              //t = doLeftRotation( t );
            }
            else{
              printf("\nRotação dupla para esquerda.");
              //t = doDoubleLeftRotation( t );
            }
    }
    t->altura = t->dir->altura - t->esq->altura + 1;
    return t;
}
*/
Arvore* inserir (Arvore *a, char v) {
  if (a == NULL) {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
  }
  else if (v < a->info) {
    a->esq = inserir (a->esq, v);
  }
  else {
    a->dir = inserir (a->dir, v);
  }
  return a;
}

Arvore* remover (Arvore *a, int v) {
  if (a == NULL) { return NULL; }
  else {
    if (a->info > v)
       a->esq = remover (a->esq, v);
    else if (a->info < v)
       a->dir = remover (a->dir, v);
    else {
       if ((a->esq == NULL) && (a->dir == NULL)) {
          free(a);
          a = NULL;
       }
       else if (a->dir == NULL) {
          Arvore *tmp = a;
          a = a->esq;
          free (tmp); 
       }
       else if (a->esq == NULL) {
          Arvore *tmp = a;
          a = a->dir;
          free (tmp);  
       }
       else {
          Arvore *tmp = a->esq;
          while (tmp->dir != NULL)
            tmp = tmp->dir;
          a->info = tmp->info;
          tmp->info = v;
          a->esq = remover (a->esq, v);
       }
    }
    return a;
  }
}

int verifica_arv_vazia(Arvore* a) {
	return (a == NULL);
}

void arv_libera(Arvore* a) {
	if (verifica_arv_vazia(a)) {
		arv_libera(a->dir);
		arv_libera(a->esq);
		free(a);
	}
}

int pertence_arv(Arvore* a, int  c) {
	if (a == NULL) return 0;
	if (a->info == c) return 1;
	else {
		return (0 + pertence_arv(a->esq, c) + pertence_arv(a->dir, c));
	}
}
int Min(Arvore *a){
  if (a->esq == NULL) return a->info;
  else return (Min(a->esq));
}
int Max(Arvore *a){
  if (a->dir == NULL) return a->info;
  else return (Max(a->dir));
}

void imprime_decrescente(Arvore* a) {
	if (a != NULL) {
		imprime_decrescente(a->dir);
		printf("\n%d", a->info);
		imprime_decrescente(a->esq);
	}
}

//ex5
int numeroNos(Arvore* a){
  if (a != NULL) return (1 + numeroNos(a->dir) + numeroNos(a->esq));
  else return 0;
}
void atribuiVetor(Arvore* a,int* v, int* pos){
  if (a != NULL){
    atribuiVetor(a->esq,v,pos);
    v[*pos] = a->info;
    (*pos)++;
    atribuiVetor(a->dir,v,pos);
  }
}
int* geraVetor(Arvore* a) {
  int tamanho = numeroNos(a);
  int* vetor = (int)malloc(sizeof(int)*tamanho);
  for (int i = 0; i < tamanho; i++){
    vetor[i] = 10;
  }
  int cont = 0;

  atribuiVetor(a,vetor,&cont);
  printf("\nvetor ordenado crescente:\n");
  for (int i = 0; i < tamanho; i++){
    printf("%d ",vetor[i]);
  }
}