#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    lista->qtdade = 0;
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* node = (struct no*)malloc(sizeof(struct no));
    node->val = valor;
    node->prox = NULL;
    return node;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    struct no* tmp = alocarNovoNo(valor);
    struct no* aux = lista->cabeca;
    if (lista->qtdade == 0) {
        lista->cabeca = tmp;
    } else if (lista->qtdade > 0) {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = tmp;
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    struct no* tmp = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
        lista->cabeca = tmp->prox;
    } else {
        tmp->prox = lista->cabeca;
        lista->cabeca = tmp;
    }
    
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    struct no* tmp = alocarNovoNo(valor);
    struct no* aux = lista->cabeca;
    for (int i = 0; i < posicao - 2; i++) {
        aux = aux->prox;
    }
    tmp->prox = aux->prox;
    aux->prox = tmp;
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    struct no* aux = lista->cabeca;
    for (int i = 0; i < posicao - 2; i++) {
        aux = aux->prox;
    }
    return aux->val;
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //TODO
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
        //navega partindo da cabe�a at� chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista est� vazia!");
    }
}