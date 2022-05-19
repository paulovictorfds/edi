#include <stdio.h>
#include <stdlib.h>

void printV(int* v, int tamanho);
void selectionSortIP(int* v, int tamanho);
void troca(int* v, int i, int j);

int main() {
    int array[] = {3, 6, 2, 5, 4, 3, 7, 1};
    int tamanho = 8;
    printf("Array original: ");
    printV(array, tamanho);
    printf("\n");

    selectionSortIP(array, tamanho);
    return 0;
}

void selectionSortIP(int* v, int tamanho) {
    for (int i = 0; i < (tamanho - 1); i++) {
        //tamanho - 1 pois qdo ordenamos n-1 elementos, 
        //o ultimo elemento ja estara na posicao correta

        int iMenor = i;     //procuraremos o menor elemento a partir do indice i                    
        for (int j = i+1; j < tamanho; j++) {
            //j = i + 1, pois nao precisamos comparar 
            //o valor no indice i com ele mesmo

            //nesse for vamos ate a ultima posicao, 
            //pois o menor elemento pode estar la 

            if (v[j] < v[iMenor]) {
                iMenor = j;
            }
        }

        //ao fim do for, o elemento em iMenor deve ser 
        //trocado com o elemento da posicao i
        troca(v, i, iMenor);
    }
    printf("Array ordenado: ");
    printV(v, 8);
    printf("\n");
}

void troca(int* v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void printV(int* v, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]", v[tamanho - 1]);
}