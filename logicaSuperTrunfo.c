#include <stdio.h>
#include <string.h>

int main() {
    // Cadastro da Carta 1
    printf("Carta 1\n");
    char CodigoDaCarta1[10], NomeDaCidade1[40];
    int Populacao1, NumeroDePontosTuristicos1;
    float Area1, PIB1, DensidadePopulacional1, PiBPerCapita1;

    printf("Digite o codigo da carta: ");
    scanf("%9s", CodigoDaCarta1);

    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(NomeDaCidade1, sizeof(NomeDaCidade1), stdin);
    NomeDaCidade1[strcspn(NomeDaCidade1, "\n")] = 0;

    printf("Digite o numero da população: ");
    scanf("%d", &Populacao1);

    printf("Digite a area da cidade: ");
    scanf("%f", &Area1);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &PIB1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &NumeroDePontosTuristicos1);

    DensidadePopulacional1 = Populacao1 / Area1;
    PiBPerCapita1 = (PIB1 * 1000000000) / Populacao1; // PIB em reais

    // Cadastro da Carta 2
    printf("\nCarta 2\n");
    char CodigoDaCarta2[10], NomeDaCidade2[40];
    int Populacao2, NumeroDePontosTuristicos2;
    float Area2, PIB2, DensidadePopulacional2, PiBPerCapita2;

    printf("Digite o codigo da carta: ");
    scanf("%9s", CodigoDaCarta2);

    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(NomeDaCidade2, sizeof(NomeDaCidade2), stdin);
    NomeDaCidade2[strcspn(NomeDaCidade2, "\n")] = 0;

    printf("Digite o numero da população: ");
    scanf("%d", &Populacao2);

    printf("Digite a area da cidade: ");
    scanf("%f", &Area2);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &PIB2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &NumeroDePontosTuristicos2);

    DensidadePopulacional2 = Populacao2 / Area2;
    PiBPerCapita2 = (PIB2 * 1000000000) / Populacao2; // PIB em reais

    // Comparação das Cartas
    printf("\n--- Comparação das Cartas ---\n");

    // População
    if (Populacao1 > Populacao2)
        printf("População: %s venceu!\n", NomeDaCidade1);
    else if (Populacao2 > Populacao1)
        printf("População: %s venceu!\n", NomeDaCidade2);
    else
        printf("População: Empate!\n");

    // Área
    if (Area1 > Area2)
        printf("Área: %s venceu!\n", NomeDaCidade1);
    else if (Area2 > Area1)
        printf("Área: %s venceu!\n", NomeDaCidade2);
    else
        printf("Área: Empate!\n");

    // PIB
    if (PIB1 > PIB2)
        printf("PIB: %s venceu!\n", NomeDaCidade1);
    else if (PIB2 > PIB1)
        printf("PIB: %s venceu!\n", NomeDaCidade2);
    else
        printf("PIB: Empate!\n");

    // Pontos Turísticos
    if (NumeroDePontosTuristicos1 > NumeroDePontosTuristicos2)
        printf("Pontos Turísticos: %s venceu!\n", NomeDaCidade1);
    else if (NumeroDePontosTuristicos2 > NumeroDePontosTuristicos1)
        printf("Pontos Turísticos: %s venceu!\n", NomeDaCidade2);
    else
        printf("Pontos Turísticos: Empate!\n");

    // Densidade Populacional (menor vence)
    if (DensidadePopulacional1 < DensidadePopulacional2)
        printf("Densidade Populacional: %s venceu!\n", NomeDaCidade1);
    else if (DensidadePopulacional2 < DensidadePopulacional1)
        printf("Densidade Populacional: %s venceu!\n", NomeDaCidade2);
    else
        printf("Densidade Populacional: Empate!\n");

    // PIB per capita
    if (PiBPerCapita1 > PiBPerCapita2)
        printf("PIB per capita: %s venceu!\n", NomeDaCidade1);
    else if (PiBPerCapita2 > PiBPerCapita1)
        printf("PIB per capita: %s venceu!\n", NomeDaCidade2);
    else
        printf("PIB per capita: Empate!\n");

    printf("\nFim do Programa\n");
    return 0;
}