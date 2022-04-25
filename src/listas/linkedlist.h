#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no *prox;
};

void imprimirLista(struct no **cabeca){
	if (*cabeca != NULL) {
		struct no *aux = (*cabeca);
		do {
			printf("%d\n", aux->val);
			aux = aux->prox;
		} while(aux != NULL);
		printf("]");
	} else {
        printf("A lista está vazia.");
    }
}

struct no* alocarNovoNo(int valor){
	//TODO
}

void inserirElementoNoFim(struct no **cabeca, int valor, int* tamanho){
	//TODO
}

void inserirElementoNoInicio(struct no **cabeca, int valor, int* tamanho){
	//TODO
}

void inserirElementoEmPosicao(struct no **cabeca, int valor, int posicao, int* tamanho){
	//TODO
}

int obterElementoEmPosicao(struct no **cabeca, int posicao){
	//TODO
}

void removerElementoEmPosicao(struct no **cabeca, int posicao, int* tamanho){
	//TODO
}
