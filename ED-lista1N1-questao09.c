/*
**    Função : Exibir números perfeitos entre 1 e 100000
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 01/04/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>

int eh_numero_perfeito(int n) {
    int soma_divisores = 0;
    
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            soma_divisores += i;
        }
    }
    
    return (soma_divisores == n);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Números perfeitos entre 1 e 100000:\n");
    
    for (int i = 1; i <= 100000; ++i) {
        if (eh_numero_perfeito(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
