#include <stdio.h>
#include <math.h>

void menu() {
    printf("Calculadora Científica\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Seno\n");
    printf("6. Cosseno\n");
    printf("7. Tangente\n");
    printf("8. Logaritmo\n");
    printf("9. Exponencial\n");
    printf("10. Raiz Quadrada\n");
    printf("11. Raiz Cúbica\n");
    printf("12. Sair\n");
    printf("Escolha uma operação: ");
}

double calcular(double num1, double num2, int operacao) {
    switch (operacao) {
        case 1: return num1 + num2;
        case 2: return num1 - num2;
        case 3: return num1 * num2;
        case 4: return num1 / num2;
        case 5: return sin(num1);
        case 6: return cos(num1);
        case 7: return tan(num1);
        case 8: return log(num1);
        case 9: return exp(num1);
        case 10: return sqrt(num1);
        case 11: return cbrt(num1);
        default: return 0.0;
    }
}

int main() {
    int escolha;
    double num1, num2, resultado;

    while (1) {
        menu();
        scanf("%d", &escolha);

        if (escolha == 12) break;

        if (escolha >= 1 && escolha <= 4) {
            printf("Digite dois números: ");
            scanf("%lf %lf", &num1, &num2);
            if (escolha == 4 && num2 == 0) {
                printf("Erro: Divisão por zero!\n");
                continue;
            }
            resultado = calcular(num1, num2, escolha);
            printf("Resultado: %.2lf\n", resultado);
        } else if (escolha >= 5 && escolha <= 11) {
            printf("Digite um número: ");
            scanf("%lf", &num1);

            if (escolha == 8 && num1 <= 0) {
                printf("Erro: Logaritmo de número não positivo!\n");
                continue;
            } else if (escolha == 10 && num1 < 0) {
                printf("Erro: Raiz quadrada de número negativo!\n");
                continue;
            }

            resultado = calcular(num1, 0, escolha);
            printf("Resultado: %.2lf\n", resultado);
        } else {
            printf("Escolha inválida!\n");
        }
    }

    return 0;
}
