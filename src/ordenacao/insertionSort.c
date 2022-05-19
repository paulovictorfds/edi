#include <stdio.h>
#include <stdlib.h>

void printV(int* v, int tamanho);
void insertionSortIPV5(int* v, int tamanho);

int main() {
    int array[] = {3, 6, 2, 5, 4, 3, 7, 1};
    int tamanho = 8;
    printf("Array original: ");
    printV(array, tamanho);
    printf("\n");

    insertionSortIPV5(array, tamanho);

    printf("Array ordenado: ");
    printV(array, tamanho);
    printf("\n");

    return 0;
}

void insertionSortIPV5(int* v, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int valor = v[i];
        int j;
        for (j = i; j > 0 && v[j - 1] > valor; j--) {
            v[j] = v[j - 1];
        }
        v[j] = valor;
    }
}

void printV(int* v, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]", v[tamanho - 1]);
}