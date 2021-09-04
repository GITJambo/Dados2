#include <iostream>

using namespace std;
struct Arvore {
	char info;
	Arvore* d;
	Arvore* e;
};

Arvore* cria_arv_vazia() {
	return NULL;
}

Arvore* constroi_arv(char c, Arvore* e, Arvore* d) {
	if (c != NULL) {
		Arvore* a = (Arvore*)malloc(sizeof(Arvore));
		a->info = c;
		a->d = d;
		a->e = e;
		return a;
	}
	return 0;
}

int verifica_arv_vazia(Arvore* a) {
	return (a == NULL);
}

void arv_libera(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_libera(a->d);
		arv_libera(a->e);
		free(a);
	}
}
//////////////////////// 

void imprimirPre(Arvore* a) {
	if (a != NULL) {
		printf("%c ", a->info);
		imprimirPre(a->e);
		imprimirPre(a->d);
	}
}

void imprimirIn(Arvore* a) {
	if (a != NULL) {
		imprimirIn(a->e);
		printf("%c ", a->info);
		imprimirIn(a->d);
	}
}

void imprimirPos(Arvore* a) {
	if (a != NULL) {
		imprimirPos(a->e);
		imprimirPos(a->d);
		printf("%c ", a->info);
	}
}

//
void imprime_arv_marcadores(Arvore* a) {
	if (a != NULL) {
		printf("%c <", a->info);
		imprime_arv_marcadores(a->e);
		imprime_arv_marcadores(a->d);
		printf(">");
	}
	else (printf("<>"));
}

//



int pertence_arv(Arvore* a, char c) {
	if (a == NULL) return 0;
	if (a->info == c) return 1;
	else {
		return (0 + pertence_arv(a->e, c) + pertence_arv(a->d, c));
	}
}
//

int conta_nos(Arvore* a) {
	if (a == NULL) return 0;
	else {
		return (1 + conta_nos(a->e) + conta_nos(a->d));
	}
}

//

int calcula_altura_arvore(Arvore* a) {
	int alturaE = 0;
	int alturaD = 0;
	if (a == NULL) return 0;
	else {
		alturaE = calcula_altura_arvore(a->e);
		alturaD = calcula_altura_arvore(a->d);
		if (alturaE >= alturaD) return alturaE + 1;
		else return alturaD + 1;
	}
}

//

char encontrar_maior_no(Arvore* a) {
	if (a == NULL) return 0;
	else{
		char infoMaior = a->info;
		char infoE = encontrar_maior_no(a->e);
		char infoD = encontrar_maior_no(a->d);

		if (infoE > infoMaior) infoMaior = infoE;
		if (infoD > infoMaior) infoMaior = infoD;
		return infoMaior;
	}
}


int main() {
	Arvore* a = constroi_arv('a',
		constroi_arv('b',
			cria_arv_vazia(),
			constroi_arv('d', cria_arv_vazia(), cria_arv_vazia())
		),
		constroi_arv('g',
			constroi_arv('e', cria_arv_vazia(), cria_arv_vazia()),
			constroi_arv('f',cria_arv_vazia(), cria_arv_vazia()

			)
		)
	);


	//ex 1
	cout << "ex 1" << endl;
	imprimirPre(a);
	printf("\n");
	imprimirIn(a);
	printf("\n");
	imprimirPos(a);
	printf("\n");
	
	//ex 2
	cout << "\nex 2" << endl;
	imprime_arv_marcadores(a);
	
	//ex 3
	cout << "\nex 3" << endl;
	cout << pertence_arv(a, 'g');
	
	//ex 4 
	cout << "\nex 4" << endl;
	cout << conta_nos(a);

	//ex 5 
	cout << "\nex 5" << endl;
	cout << calcula_altura_arvore(a);

	//ex 6 - Encontre o n� de maior valor na �rvore
	cout << "\nex 6" << endl;
	cout << encontrar_maior_no(a);

	cout << "\nfim" << endl;
	arv_libera(a);

	return 0;
}