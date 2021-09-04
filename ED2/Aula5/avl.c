#include "avl.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore* a) {
   if (a == NULL) return 0;
  else{
    if (a->dir == NULL && a->esq == NULL) {
      a->altura = 0;
    }
    else{
      a->altura = altura(a->dir) - altura(a->esq);
    }
    return a->altura + 1;
  }
}

int atualizar_altura (Arvore *a) {
   if (a == NULL) return 0;
   else{
      if (a->dir == NULL && a->esq == NULL) {
         a->altura = 0;
      }
      else{
         a->altura = atualizar_altura(a->dir) - atualizar_altura(a->esq);
      }
      return a->altura + 1;
   }	
}

/*----------------------*/
int balanceamento (Arvore *a) {
   if (a == NULL) return;
   if (a->altura == -2){
      printf("criacao %c = -2\n", a->info);
      a = rotacao_simples_dir(a);
   }
   if (a->altura == 2){
      printf("criacao %c = 2\n", a->info);
      a = rotacao_simples_esq(a);
   }
   else {
      balanceamento(a->esq);
      balanceamento(a->dir);
   }
   return a;
}

/*----------------------*/
Arvore* rotacao_simples_esq (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_simples_dir (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* atualizar_fb_dir (Arvore *a) {
   /*TERMINAR!!!*/
}

/*----------------------*/
Arvore* atualizar_fb_esq (Arvore *a) {
   /*TERMINAR!!!*/
}

/*----------------------*/
Arvore* inserir (Arvore *a, char chave) {
    if (a == NULL) {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->altura = 0;
    a->esq = NULL;
    a->dir = NULL;
  }
  else if (v < a->info) {
    a->esq = inserir (a->esq, v);
    a->altura--;
  }
  else {
    a->dir = inserir (a->dir, v);
    a->altura++;
  }
  a = balanceia(a);
  return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore* remover (Arvore *a, char chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      if (chave < a->chave) {
         a->esq = remover (a->esq, chave);
         a = atualizar_fb_dir (a);
      }
      else if (chave > a->chave) {
         a->dir = remover (a->dir, chave);
         a = atualizar_fb_esq (a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free (a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No *tmp = a;
            a = a->dir;
            free (tmp);
         }
         else if (a->dir == NULL) {
            No *tmp = a;
            a = a->esq;
            free (tmp);
         }
         else {
            No *tmp = a->esq;
            while (tmp->dir != NULL) {
               tmp = tmp->dir;
            }
            a->chave = tmp->chave; 
            tmp->chave = chave;
            a->esq = remover (a->esq, chave); 
            a = atualizar_fb_dir (a);
         }
      }
      return a; 
   }   
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}

