#include <stdio.h>
#include <string.h>

int main() {
    char nome1[50], nome2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    // Entrada dos dados da Carta 1
    printf("== Carta 1 ==\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em trilhões): ");
    scanf("%f", &pib1);
    printf("Nº de pontos turísticos: ");
    scanf("%d", &pontos1);

    // Entrada dos dados da Carta 2
    printf("\n== Carta 2 ==\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em trilhões): ");
    scanf("%f", &pib2);
    printf("Nº de pontos turísticos: ");
    scanf("%d", &pontos2);

    // Cálculo dos atributos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000000) / populacao2;

    int escolha1, escolha2;
    float valor1A = 0, valor2A = 0, valor1B = 0, valor2B = 0;

    // Menu para escolher o primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha1);

    // Menu dinâmico para o segundo atributo (sem repetir o primeiro)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    printf("Digite a opção: ");
    scanf("%d", &escolha2);

    // Função para pegar o valor de um atributo
    switch (escolha1) {
        case 1: valor1A = populacao1; valor2A = populacao2; break;
        case 2: valor1A = area1; valor2A = area2; break;
        case 3: valor1A = pib1; valor2A = pib2; break;
        case 4: valor1A = pontos1; valor2A = pontos2; break;
        case 5: valor1A = densidade1; valor2A = densidade2; break;
        case 6: valor1A = pibPerCapita1; valor2A = pibPerCapita2; break;
        default: printf("Opção inválida!\n"); return 1;
    }

    switch (escolha2) {
        case 1: valor1B = populacao1; valor2B = populacao2; break;
        case 2: valor1B = area1; valor2B = area2; break;
        case 3: valor1B = pib1; valor2B = pib2; break;
        case 4: valor1B = pontos1; valor2B = pontos2; break;
        case 5: valor1B = densidade1; valor2B = densidade2; break;
        case 6: valor1B = pibPerCapita1; valor2B = pibPerCapita2; break;
        default: printf("Opção inválida!\n"); return 1;
    }

    // Comparação com regra da densidade
    int vencedor1 = (escolha1 == 5) ? (valor1A < valor2A ? 1 : (valor1A > valor2A ? 2 : 0))
                                    : (valor1A > valor2A ? 1 : (valor1A < valor2A ? 2 : 0));
    int vencedor2 = (escolha2 == 5) ? (valor1B < valor2B ? 1 : (valor1B > valor2B ? 2 : 0))
                                    : (valor1B > valor2B ? 1 : (valor1B < valor2B ? 2 : 0));

    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // Exibição dos resultados
    printf("\n--- Resultado ---\n");
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", nome1, valor1A, valor1B, soma1);
    printf("%s - Atributo 1: %.2f | Atributo 2: %.2f | Soma: %.2f\n", nome2, valor2A, valor2B, soma2);

    if (soma1 > soma2) {
        printf("\nVencedor: %s\n", nome1);
    } else if (soma2 > soma1) {
        printf("\nVencedor: %s\n", nome2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
