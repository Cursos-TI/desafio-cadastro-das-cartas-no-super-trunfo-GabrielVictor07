#include <stdio.h>

int main() {
    // === Dados da Carta 1 ===
    char estado1, codigo1[4], nomeCidade1[100];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;

    // === Dados da Carta 2 ===
    char estado2, codigo2[4], nomeCidade2[100];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;

    // === Variáveis para cálculos ===
    float densidade1, pibPerCapita1;
    float densidade2, pibPerCapita2;

    // Entrada dos dados da Carta 1
    printf("=== Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta: ");
    scanf(" %s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada dos dados da Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta: ");
    scanf(" %s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    // Cálculo do PIB per capita
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // === COMPARAÇÃO POR UM ÚNICO ATRIBUTO ===
    // Atributo escolhido: População
    printf("\n=== Comparação de Cartas (Atributo: População) ===\n");
    printf("Carta 1 - %s (%c): %lu\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%c): %lu\n", nomeCidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
