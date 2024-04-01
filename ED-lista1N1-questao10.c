/*
**    Função : Exibir a sequência de fibonacci até n
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 01/04/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>

int* fibonacci_max(int max) {
    int* fibonacci_array = (int*)malloc(1 * sizeof(int));
    if (fibonacci_array == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    fibonacci_array[0] = 1;
    fibonacci_array[1] = 1;

    int size = 2;
    int next_fibonacci = 2;

    while (next_fibonacci <= max) {
        size++;
        fibonacci_array = (int*)realloc(fibonacci_array, size * sizeof(int));
        if (fibonacci_array == NULL) {
            printf("Erro de realocação de memória!\n");
            exit(1);
        }
        fibonacci_array[size - 1] = next_fibonacci;
        next_fibonacci = fibonacci_array[size - 1] + fibonacci_array[size - 2];
    }

    fibonacci_array = (int*)realloc(fibonacci_array, (size + 1) * sizeof(int));
    if (fibonacci_array == NULL) {
        printf("Erro de realocação de memória!\n");
        exit(1);
    }
    fibonacci_array[size] = -1;

    return fibonacci_array;
}

void exibir_array(int* arr) {
    for (int i = 0; arr[i] != -1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int max;
    printf("Digite o valor máximo para a série de Fibonacci: ");
    scanf("%d", &max);

    int* fibonacci_array = fibonacci_max(max);

    printf("Série de Fibonacci até %d: ", max);
    exibir_array(fibonacci_array);

    free(fibonacci_array);

    return 0;
}
