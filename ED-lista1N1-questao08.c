/*
**    Função : Exibir números de Armstrong entre 1 e 100
**    Autor : David Ramalho Teixeira de Carvalho
**    Data  : 01/04/2024
**    Observações:
*/
#include <stdio.h>
#include <locale.h>

int contar_digitos(int n) {
    int contador = 0;
    while (n != 0) {
        n /= 10;
        contador++;
    }
    return contador;
}

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; ++i) {
        resultado *= base;
    }
    return resultado;
}

int eh_numero_armstrong(int n) {
    int num_digitos = contar_digitos(n);
    int soma = 0;
    int original = n;

    while (n != 0) {
        int digito = n % 10;
        soma += potencia(digito, num_digitos);
        n /= 10;
    }

    return (soma == original);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("Números de Armstrong entre 1 e 100:\n");
    for (int i = 1; i <= 100; ++i) {
        if (eh_numero_armstrong(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
