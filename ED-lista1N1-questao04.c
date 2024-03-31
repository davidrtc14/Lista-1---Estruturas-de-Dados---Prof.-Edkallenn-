/*
**    Função :
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 31/03/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>

int eh_numero_automorfico(int n) {
    int square = n * n;
    int temp = n;
    while (temp > 0) {
        if (temp % 10 != square % 10)
            return 0;
        temp /= 10;
        square /= 10;
    }
    return 1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Número inválido! Digite um número inteiro positivo maior que 1.\n");
        return 1;
    }

    printf("Números automórficos entre 2 e %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (eh_numero_automorfico(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
