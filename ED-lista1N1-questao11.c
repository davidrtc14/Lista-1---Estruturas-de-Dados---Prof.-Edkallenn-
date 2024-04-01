/*
**    Função : Verificar se os Arrays são os não permutações circulares
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 01/04/2024
**    Observações:
*/ 
#include <stdio.h>
#include <locale.h>

int permutacao_circular(int* array1, int* array2, int tamanho) {
    if (array1 == NULL || array2 == NULL) {
        return 0;
    }

    int* temp_array = (int*)malloc(tamanho * sizeof(int));
    if (temp_array == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            temp_array[j] = array1[(i + j) % tamanho];
        }

        int igual = 1;
        for (int j = 0; j < tamanho; j++) {
            if (temp_array[j] != array2[j]) {
                igual = 0;
                break;
            }
        }

        if (igual) {
            free(temp_array);
            return 1;
        }
    }

    free(temp_array);
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int tamanho;
    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int *array1 = (int *)malloc(tamanho * sizeof(int));
    int *array2 = (int *)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do primeiro array: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Digite os elementos do segundo array: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array2[i]);
    }

    if (permutacao_circular(array1, array2, tamanho)) {
        printf("Os arrays são permutações circulares.\n");
    } else {
        printf("Os arrays não são permutações circulares.\n");
    }

    free(array1);
    free(array2);

    return 0;
}
