#include "arvore.c"

//include errado porem funciona no vscode

void imprimir_in_ordem (Arvore *a) {
  if (a != NULL) {
    imprimir_in_ordem (a->esq);
    printf ("%d\n", a->info);
    imprimir_in_ordem (a->dir);
  }
}

int main () {
  Arvore *a = NULL;
  srand(time(NULL));

  //rand so vai ate 32767
  for (int i = 0; i < 100000; i++) {
    a = inserir(a,rand()%100000);
  }


  printf("\n teste \n");
	clock_t begin = clock();
	printf("%d", pertence_arv(a,(int)10000));
  printf("%d", pertence_arv(a,(int)32000));
  printf("%d", pertence_arv(a,(int)36000));
	clock_t end = clock();

	printf("tempo = %lf \n",(double)(end - begin) / CLOCKS_PER_SEC);
  printf("\nmin =  %d",Min(a));
  printf("\nmax =  %d",Max(a));

  //imprime_decrescente(a);
  
  //Ex 5- Escreva uma função que transforme uma árvore de busca em um vetor crescente.
  geraVetor(a);

  printf("\nFIM");
	arv_libera(a);
}

