/*
**    Função : Verificar e exibir números felizes e não felizes
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 01/04/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>


int soma_quadrados_digitos(int n) {
    int soma = 0;
    while (n != 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

int eh_numero_feliz(int n) {
    int visitados[1000] = {0}; 

    while (1) {
        if (n == 1)
            return 1; 
        if (visitados[n])
            return 0; 
        visitados[n] = 1; 
        n = soma_quadrados_digitos(n); 
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese"); 

    int num;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

    if (eh_numero_feliz(num)) {
        printf("%d é um número feliz.\n", num);
    } else {
        printf("%d não é um número feliz.\n", num);
    }

    return 0;
}
