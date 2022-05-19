#include <stdio.h>
#include <stdlib.h>

void printV(int* v, int tamanho);
void bubbleSortV3(int* v, int tamanho);

int main() {
    int array[] = {3, 6, 2, 5, 4, 3, 7, 1};
    int tamanho = 8;
    printf("Array original: ");
    printV(array, tamanho);
    printf("\n");

    bubbleSortV3(array, tamanho);

    printf("Array ordenado: ");
    printV(array, tamanho);
    printf("\n");

    return 0;
}

void bubbleSortV3(int* v, int n) {
    for (int varredura = 0; varredura < n - 1; varredura++) {
        for (int i = 0; i < n - varredura - 1; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}

void printV(int* v, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho - 1; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d]", v[tamanho - 1]);
}