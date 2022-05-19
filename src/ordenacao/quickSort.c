#include <stdio.h>
#include <stdlib.h>

void printV(int* v, int tamanho);
int particiona(int* v, int ini, int fim);
void troca(int* v, int i, int j);
void quickSort(int* v, int ini, int fim);

int main() {
    int array[] = {3, 6, 2, 5, 4, 3, 7, 1};
    int tamanho = 8;
    printf("Array original: ");
    printV(array, tamanho);
    printf("\n");

    quickSort(array, array[0], array[tamanho - 1]);

    printf("Array ordenado: ");
    printV(array, tamanho);
    printf("\n");

    return 0;
}

void troca(int* v, int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int particiona(int* v, int ini, int fim) {
    int pIndex = ini;
    int pivo = v[fim];
    for (int i = ini; i < fim; i++) {
        if (v[i] <= pivo) {
            troca(v, i, pIndex);
            pIndex++;
        }
    }
    troca(v, pIndex, fim);
    return pIndex;
}

void quickSort(int* v, int ini, int fim) {
    if (fim>ini) {
        int indexPivo = particiona(v, ini, fim);
        quickSort(v, ini, indexPivo - 1);
        quickSort(v, indexPivo + 1, fim);   //indexPivo j� est� no seu local
    }
}

void printV(int* v, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]", v[tamanho - 1]);
}