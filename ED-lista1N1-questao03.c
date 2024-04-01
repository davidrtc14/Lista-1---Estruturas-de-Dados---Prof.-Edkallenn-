/*
**    Função : Exibir pares de números amigavéis
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 30/03/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>

int soma_divisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

void verificar_amigaveis(int a, int b) {
    int soma_a = soma_divisores(a);
    int soma_b = soma_divisores(b);

    printf("Divisores próprios de %d: ", a);
    for (int i = 1; i <= a/2; i++) {
        if (a % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\nSoma dos divisores próprios de %d: %d\n", a, soma_a);

    printf("Divisores próprios de %d: ", b);
    for (int i = 1; i <= b/2; i++) {
        if (b % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\nSoma dos divisores próprios de %d: %d\n", b, soma_b);

    if (soma_a == b && soma_b == a) {
        printf("%d e %d são números amigáveis.\n", a, b);
    } else {
        printf("%d e %d não são números amigáveis.\n", a, b);
    }
}

void encontrar_amigaveis_ate(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (soma_divisores(i) == j && soma_divisores(j) == i) {
                printf("%d e %d são números amigáveis.\n", i, j);
            }
        }
    }
}

int main() {
    
    int num1, num2;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite dois números inteiros positivos separados por espaço: ");
    scanf("%d %d", &num1, &num2);

    printf("\nVerificando se %d e %d são números amigáveis:\n", num1, num2);
    verificar_amigaveis(num1, num2);

    printf("\nEncontrando pares de números amigáveis até o valor n.\n");
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("\nPares de números amigáveis até %d:\n", n);
    encontrar_amigaveis_ate(n);

    return 0;
}
