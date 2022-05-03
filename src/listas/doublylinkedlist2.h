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
   struct doublylinkedlist *lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
   lista->cabeca = NULL;
   lista->cauda = NULL;
   lista->qtdade = 0;
   return lista;
}

struct no* alocarNovoNo(int valor){
    struct no* node = (struct no*)malloc(sizeof(struct no));
    node->ant = NULL;
    node->prox = NULL;
    node->val = valor;
    return node;
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor){
    struct no* novoNo = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
        lista->cabeca = novoNo;
        lista->cauda = novoNo;
    } else {
        lista->cabeca->ant = novoNo;
        novoNo->prox = lista->cabeca;
        lista->cabeca = novoNo;
    }    
    lista->qtdade++;
}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor){
    struct no* novoNo = alocarNovoNo(valor);
    if (lista->qtdade == 0) {
        lista->cabeca = novoNo;
        lista->cauda = novoNo;
    } else {
        lista->cauda->prox = novoNo;
        novoNo->ant = lista->cauda;        
        lista->cauda = novoNo;
    }    
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao) {    
    if (lista->qtdade == 0) {
        struct no* novoNo = alocarNovoNo(valor);
        lista->cabeca = novoNo;
        lista->cauda = novoNo;
        lista->qtdade++;
        printf("Inseriu valor %d em posicao %d (qtd=0)\n", valor, posicao);
    } else {
        if (posicao == 0) {
            printf("Inseriu valor %d em posicao %d (comeco)\n", valor, posicao);
            inserirElementoNoInicio(lista, valor);            
        } else if (posicao == lista->qtdade) {
            printf("Inseriu valor %d em posicao %d (fim)\n", valor, posicao);
            inserirElementoNoFim(lista, valor);            
        } 
        else {
            struct no* novoNo = alocarNovoNo(valor);
            if (posicao < lista->qtdade / 2) {
                struct no* tmp = lista->cabeca;
                for (int i = 0; i < posicao - 1; i++) {
                    tmp = tmp->prox;
                }
                novoNo->prox = tmp->prox;
                novoNo->ant = tmp;
                tmp->prox = novoNo;
                printf("Inseriu valor %d em posicao %d (cabeca)\n", valor, posicao);
            } else {
                struct no* tmp = lista->cauda;
                for (int i = lista->qtdade - 1; i > posicao; i--) {
                    tmp = tmp->ant;
                }
                novoNo->prox = tmp->prox;
                novoNo->ant = tmp->ant;
                (tmp->ant)->prox = novoNo;
                printf("Inseriu valor %d em posicao %d (cauda)\n", valor, posicao);
            }
            lista->qtdade++;
        }      
    }
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    if (lista->qtdade <= 0) {
        printf("Lista vazia!\n");
        return -1;
    }
    if (posicao < lista->qtdade / 2) {
        struct no* tmp = lista->cabeca;
        for (int i = 0; i < posicao; i++) {
            tmp = tmp->prox;
        }
        printf("Obteve valor %d em posicao %d (cabeca)\n", tmp->val, posicao);
        return tmp->val;
    } else {
        struct no* tmp = lista->cauda;
        for (int i = lista->qtdade - 1; i > posicao; i--) {
            tmp = tmp->ant;
        }
        printf("Obteve valor %d em posicao %d (cauda)\n", tmp->val, posicao);
        return tmp->val;
    }
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    struct no* tmp = lista->cabeca;
    if (posicao == 0) {
        lista->cabeca = lista->cabeca->prox;
    } else {        
        for (int i = 0; i < posicao - 1; i++) {
            tmp = tmp->prox;
        }
        struct no* aux = tmp->prox;
        tmp->prox = aux->prox;
    }
    lista->qtdade--;
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