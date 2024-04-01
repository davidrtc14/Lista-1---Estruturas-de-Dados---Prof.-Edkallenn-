/*
**    Função : Exibir tabela das potências fatoriais e seus tipos.
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 30/03/2024
**    Observações:
*/

#include <stdio.h>
#include <locale.h>

int potencia_fatorial_crescente(int x, int n) {
    int fatorial = 1;
    for (int i = 1; i <= n; ++i) {
        fatorial *= i;
    }

    int resultado = 1;
    for (int i = x; i < x + n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int potencia_fatorial_decrescente(int x, int n) {
    int resultado = 1;
    for (int i = x; i > x - n; --i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int x, n;
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo = fopen("resultados.txt", "w");

    printf("Tabela de Potências Fatoriais:\n\n");
    printf("|   x   |   n   | Crescente | Decrescente |\n");
    printf("|-------|-------|-----------|-------------|\n");

    for (n = 2; n <= 10; ++n) {
        x = 2; 
        int crescente = potencia_fatorial_crescente(x, n);
        int decrescente = potencia_fatorial_decrescente(x, n);

        printf("|   %2d  |   %2d  |  %9d |  %10d |\n", x, n, crescente, decrescente);

        fprintf(arquivo, "x=%d, n=%d, crescente=%d, decrescente=%d\n", x, n, crescente, decrescente);
    }

    printf("\n");

    for (x = 2; x <= 10; ++x) {
        n = x; 
        int crescente = potencia_fatorial_crescente(x, n);
        int decrescente = potencia_fatorial_decrescente(x, n);

        printf("|   %2d  |   %2d  |  %9d |  %10d |\n", x, n, crescente, decrescente);

        fprintf(arquivo, "x=%d, n=%d, crescente=%d, decrescente=%d\n", x, n, crescente, decrescente);
    }

    fclose(arquivo);

    return 0;
}
