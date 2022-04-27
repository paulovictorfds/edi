#include <stdlib.h>
#include <stdio.h>

struct no{
    struct no *ant;
    int val;
    struct no *prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializar() {
   struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
   lista->qtdade = 0;
   lista->cauda = NULL;
   lista->cabeca = NULL;
   return lista;   
}

struct no* alocarNovoNo(int valor){
    struct no* node = (struct no*)malloc(sizeof(no));
    node->val = valor;
    node->ant = NULL;
    node->prox = NULL;
    return node;
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor){
    struct no* tmp = lista->cabeca;
    struct no* node = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
       lista->cabeca = node;
       lista->cauda = node;
    } else {
        node->prox = tmp;
        tmp->ant = node;
        lista->cabeca = node;
    }
    lista->qtdade++;
}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor){
    struct no* tmp = lista->cauda;
    struct no* node = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
       lista->cabeca = node;
       lista->cauda = node;
    } else {
        node->ant = tmp;
        lista->cauda = node;
        tmp->prox = node;        
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao){
    struct no* node = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
        lista->cabeca = node;
        lista->cauda = node;
        lista->qtdade++;
    } else {
        if (posicao == 0) {
            inserirElementoNoInicio(lista, valor);
        } else if (posicao == lista->qtdade -  1) {
            inserirElementoNoFim(lista, valor);
        } else {
            if (posicao > lista->qtdade / 2) {
                struct no* tmp = lista->cauda;                
                for (int i = lista->qtdade - 1; i > posicao; i--) {
                    tmp = tmp->ant;
                }
                struct no* aux = tmp->ant;                
                tmp->ant = node;
                node->prox = tmp;
                aux->prox = node;
                node->ant = aux;
            } else {
                struct no* tmp = lista->cabeca;
                for (int i = 0; i < posicao; i++) {
                    tmp = tmp->prox;
                }
                struct no* aux = tmp->prox; 
                node->prox = tmp->prox;
                aux->ant = node;
                node->ant = tmp;
                tmp->prox = node;
            }
            lista->qtdade++;
        }
    }    
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    if (posicao > lista->qtdade / 2) {
        struct no* tmp = lista->cauda;
        for (int i = lista->qtdade - 1; i > posicao; i--) {
            tmp = tmp->ant;
        }
        return tmp->val;
    } else {
        struct no* tmp = lista->cabeca;
        for (int i = 0; i < posicao; i++) {
            tmp = tmp->prox;
        }
        return tmp->val;
    }
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    //TODO
}

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabeça até chegar NULL
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
        printf("A lista está vazia!");
    }
}