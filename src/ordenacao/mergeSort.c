#include <stdio.h>
#include <stdlib.h>

void printV(int* v, int tamanho);
void merge(int* v, int tamV, int* e, int tamE, int* d, int tamD);
void mergeSort(int* v, int tamanho);

int main() {
    int array[] = {3, 6, 2, 5, 4, 3, 7, 1};
    int tamanho = 8;
    printf("Array original: ");
    printV(array, tamanho);
    printf("\n");

    mergeSort(array, tamanho);

    printf("Array ordenado: ");
    printV(array, tamanho);
    printf("\n");

    return 0;
}

void merge(int* v, int tamV, int* e, int tamE, int* d, int tamD) {
    int indexV = 0;
    int indexE = 0;
    int indexD = 0;
    while (indexE < tamE && indexD < tamD) {
        if (e[indexE] <= d[indexD]) {
            v[indexV] = e[indexE];
            indexE++;
        }
        else {
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    //ainda poder�amos ter elementos no vetor E que n�o foram copiados para V
    while (indexE < tamE) {
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    //ainda poder�amos ter elementos no vetor D que n�o foram copiados para V
    while (indexD < tamD) {
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void mergeSort(int* v, int tamV) {
    if (tamV > 1) {
        //primeiro quebramos o vetor em 2 vetores menores
        int meio = tamV / 2;

        int tamV1 = meio;
        int* v1 = (int*)malloc(tamV1 * sizeof(int));
        for (int i = 0; i < meio; i++) {
            v1[i] = v[i];
        }

        int tamV2 = tamV - meio;
        int* v2 = (int*)malloc(tamV2 * sizeof(int));
        for (int i = meio; i < tamV; i++) {
            v2[i - meio] = v[i];
        }

        mergeSort(v1, tamV1);
        mergeSort(v2, tamV2);
        merge(v, tamV, v1, tamV1, v2, tamV2);

        free(v1);
        free(v2);
    }
}

void printV(int* v, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]", v[tamanho - 1]);
}