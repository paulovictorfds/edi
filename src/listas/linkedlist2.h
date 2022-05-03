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
    lista->cabeca = NULL;
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
    struct no* node = alocarNovoNo(valor);    
    if (lista->qtdade == 0) {
        lista->cabeca = node;
    } else {
        struct no* aux = lista->cabeca;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = node;
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    struct no* node = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
        lista->cabeca = node;
    } else {
        node->prox = lista->cabeca;
        lista->cabeca = node;
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    struct no* novoNo = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
        lista->cabeca = novoNo;
        lista->qtdade++;
    } else {
        if (posicao == 0) {
            inserirElementoNoInicio(lista, valor);
        } else if (posicao == lista->qtdade - 1) {
            inserirElementoNoFim(lista, valor);
        } else {
            struct no* tmp = lista->cabeca;
            for (int i = 0; i < posicao - 1; i++) {
                tmp = tmp->prox;
            }
            novoNo->prox = tmp->prox;
            tmp->prox = novoNo;
            lista->qtdade++;
        }      
    }        
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    struct no* tmp = lista->cabeca;
    for (int i = 0; i < posicao; i++) {
        tmp = tmp->prox;
    }
    return tmp->val;
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    struct no* tmp = lista->cabeca;
    if (posicao == 0) {
        lista->cabeca = tmp->prox;
        free(tmp);
    } else {        
        for (int i = 0; i < posicao - 1; i++) {
            tmp = tmp->prox;
        }
        struct no* aux = tmp->prox;
        tmp->prox = aux->prox;
        free(aux);
    }
    lista->qtdade--;
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