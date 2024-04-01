/*
**    Função : Exibir tabela de números fatoriais e seus tipos
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 30/03/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>

int fatorial_duplo(int n) {
    int resultado = 1;
    
    int num = (n % 2 == 0) ? 2 : 1;
    
    for (int i = num; i <= n; i += 2) {
        resultado *= i;
    }
    
    return resultado;
}

int fatorial_normal(int n) {
    int resultado = 1;
    
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    
    return resultado;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int fatorial_duplo_array[19]; 
    int fatorial_normal_array[19]; 

    for (int i = 2; i <= 20; i++) {
        fatorial_duplo_array[i-2] = fatorial_duplo(i);
        fatorial_normal_array[i-2] = fatorial_normal(i);
    }

    printf("Tabela de Fatoriais:\n\n");
    printf("| Número | Fatorial Duplo | Fatorial Normal | Diferença |\n");
    printf("|--------|----------------|------------------|-----------|\n");
    for (int i = 0; i < 19; i++) {
        int diferenca = fatorial_normal_array[i] - fatorial_duplo_array[i];
        printf("|   %2d   |      %8d     |      %10d    |   %6d  |\n", i + 2, fatorial_duplo_array[i], fatorial_normal_array[i], diferenca);
    }

    FILE *arquivo = fopen("resultados02.txt", "w");

    fprintf(arquivo, "Tabela de Fatoriais:\n\n");
    fprintf(arquivo, "| Número | Fatorial Duplo | Fatorial Normal | Diferença |\n");
    fprintf(arquivo, "|--------|----------------|------------------|-----------|\n");
    for (int i = 0; i < 19; i++) {
        int diferenca = fatorial_normal_array[i] - fatorial_duplo_array[i];
        fprintf(arquivo, "|   %2d   |      %8d     |      %10d    |   %6d  |\n", i + 2, fatorial_duplo_array[i], fatorial_normal_array[i], diferenca);
    }

    fclose(arquivo);

    return 0;
}