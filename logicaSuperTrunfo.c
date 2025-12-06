#include <stdio.h>
#include <string.h>

// Estrutura para armazenar dados da carta
typedef struct {
    char Estado;
    char CodigoDaCarta[10];
    char NomeDaCidade[40];
    int Populacao;
    float Area;
    float PIB;
    int NumeroDePontosTuristicos;
    float DensidadePopulacional;
    float PiBPerCapita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n========== CADASTRO DA CARTA %d ==========\n", numero);
    
    printf("Digite a letra do estado: ");
    scanf(" %c", &carta->Estado);
    
    printf("Digite o codigo da carta: ");
    scanf("%9s", carta->CodigoDaCarta);
    
    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta->NomeDaCidade, sizeof(carta->NomeDaCidade), stdin);
    carta->NomeDaCidade[strcspn(carta->NomeDaCidade, "\n")] = 0;
    
    printf("Digite o numero da população: ");
    scanf("%d", &carta->Populacao);
    
    printf("Digite a area da cidade (em km²): ");
    scanf("%f", &carta->Area);
    
    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->PIB);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->NumeroDePontosTuristicos);
    
    // Cálculos dos atributos derivados
    carta->DensidadePopulacional = (float)carta->Populacao / carta->Area;
    carta->PiBPerCapita = (carta->PIB * 1000000000) / (float)carta->Populacao;
}

// Função para exibir dados da carta
void exibirCarta(Carta *carta, int numero) {
    printf("\n========== CARTA %d ==========\n", numero);
    printf("Estado: %c\n", carta->Estado);
    printf("Codigo: %s\n", carta->CodigoDaCarta);
    printf("Cidade: %s\n", carta->NomeDaCidade);
    printf("População: %d habitantes\n", carta->Populacao);
    printf("Area: %.2f km²\n", carta->Area);
    printf("PIB: %.2f bilhões de reais\n", carta->PIB);
    printf("Pontos Turisticos: %d\n", carta->NumeroDePontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->DensidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta->PiBPerCapita);
}

// Função para exibir menu de atributos
void exibirMenuAtributos() {
    printf("\n========== MENU DE ATRIBUTOS ==========\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("0 - Sair\n");
    printf("=====================================\n");
}

// Função para comparar um atributo específico (Nível Aventureiro)
void compararAtributo(Carta *carta1, Carta *carta2, int atributo) {
    char *nomeAtributo;
    char *vencedor;
    
    switch(atributo) {
        case 1: // População
            nomeAtributo = "População";
            vencedor = (carta1->Populacao > carta2->Populacao) ? carta1->NomeDaCidade :
                      (carta2->Populacao > carta1->Populacao) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%d)\n", carta1->NomeDaCidade, carta1->Populacao);
            printf("Cidade 2: %s (%d)\n", carta2->NomeDaCidade, carta2->Populacao);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 2: // Área
            nomeAtributo = "Área";
            vencedor = (carta1->Area > carta2->Area) ? carta1->NomeDaCidade :
                      (carta2->Area > carta1->Area) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f km²)\n", carta1->NomeDaCidade, carta1->Area);
            printf("Cidade 2: %s (%.2f km²)\n", carta2->NomeDaCidade, carta2->Area);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 3: // PIB
            nomeAtributo = "PIB";
            vencedor = (carta1->PIB > carta2->PIB) ? carta1->NomeDaCidade :
                      (carta2->PIB > carta1->PIB) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f bilhões)\n", carta1->NomeDaCidade, carta1->PIB);
            printf("Cidade 2: %s (%.2f bilhões)\n", carta2->NomeDaCidade, carta2->PIB);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 4: // Pontos Turísticos
            nomeAtributo = "Pontos Turísticos";
            vencedor = (carta1->NumeroDePontosTuristicos > carta2->NumeroDePontosTuristicos) ? carta1->NomeDaCidade :
                      (carta2->NumeroDePontosTuristicos > carta1->NumeroDePontosTuristicos) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%d)\n", carta1->NomeDaCidade, carta1->NumeroDePontosTuristicos);
            printf("Cidade 2: %s (%d)\n", carta2->NomeDaCidade, carta2->NumeroDePontosTuristicos);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 5: // Densidade Populacional (menor vence)
            nomeAtributo = "Densidade Populacional";
            vencedor = (carta1->DensidadePopulacional < carta2->DensidadePopulacional) ? carta1->NomeDaCidade :
                      (carta2->DensidadePopulacional < carta1->DensidadePopulacional) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f hab/km²)\n", carta1->NomeDaCidade, carta1->DensidadePopulacional);
            printf("Cidade 2: %s (%.2f hab/km²)\n", carta2->NomeDaCidade, carta2->DensidadePopulacional);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 6: // PIB per Capita
            nomeAtributo = "PIB per Capita";
            vencedor = (carta1->PiBPerCapita > carta2->PiBPerCapita) ? carta1->NomeDaCidade :
                      (carta2->PiBPerCapita > carta1->PiBPerCapita) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f reais)\n", carta1->NomeDaCidade, carta1->PiBPerCapita);
            printf("Cidade 2: %s (%.2f reais)\n", carta2->NomeDaCidade, carta2->PiBPerCapita);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        default:
            printf("Opção inválida!\n");
    }
}

// Função para comparar dois atributos (Nível Mestre)
void compararDoisAtributos(Carta *carta1, Carta *carta2, int atributo1, int atributo2) {
    int pontosCarta1 = 0, pontosCarta2 = 0;
    char *nomeAtributo1, *nomeAtributo2;
    
    // Comparação do primeiro atributo
    switch(atributo1) {
        case 1: nomeAtributo1 = "População"; 
                pontosCarta1 += (carta1->Populacao > carta2->Populacao) ? 1 : 0;
                pontosCarta2 += (carta2->Populacao > carta1->Populacao) ? 1 : 0; break;
        case 2: nomeAtributo1 = "Área"; 
                pontosCarta1 += (carta1->Area > carta2->Area) ? 1 : 0;
                pontosCarta2 += (carta2->Area > carta1->Area) ? 1 : 0; break;
        case 3: nomeAtributo1 = "PIB"; 
                pontosCarta1 += (carta1->PIB > carta2->PIB) ? 1 : 0;
                pontosCarta2 += (carta2->PIB > carta1->PIB) ? 1 : 0; break;
        case 4: nomeAtributo1 = "Pontos Turísticos"; 
                pontosCarta1 += (carta1->NumeroDePontosTuristicos > carta2->NumeroDePontosTuristicos) ? 1 : 0;
                pontosCarta2 += (carta2->NumeroDePontosTuristicos > carta1->NumeroDePontosTuristicos) ? 1 : 0; break;
        case 5: nomeAtributo1 = "Densidade Populacional"; 
                pontosCarta1 += (carta1->DensidadePopulacional < carta2->DensidadePopulacional) ? 1 : 0;
                pontosCarta2 += (carta2->DensidadePopulacional < carta1->DensidadePopulacional) ? 1 : 0; break;
        case 6: nomeAtributo1 = "PIB per Capita"; 
                pontosCarta1 += (carta1->PiBPerCapita > carta2->PiBPerCapita) ? 1 : 0;
                pontosCarta2 += (carta2->PiBPerCapita > carta1->PiBPerCapita) ? 1 : 0; break;
        default: nomeAtributo1 = "Inválido"; break;
    }
    
    // Comparação do segundo atributo
    switch(atributo2) {
        case 1: nomeAtributo2 = "População"; 
                pontosCarta1 += (carta1->Populacao > carta2->Populacao) ? 1 : 0;
                pontosCarta2 += (carta2->Populacao > carta1->Populacao) ? 1 : 0; break;
        case 2: nomeAtributo2 = "Área"; 
                pontosCarta1 += (carta1->Area > carta2->Area) ? 1 : 0;
                pontosCarta2 += (carta2->Area > carta1->Area) ? 1 : 0; break;
        case 3: nomeAtributo2 = "PIB"; 
                pontosCarta1 += (carta1->PIB > carta2->PIB) ? 1 : 0;
                pontosCarta2 += (carta2->PIB > carta1->PIB) ? 1 : 0; break;
        case 4: nomeAtributo2 = "Pontos Turísticos"; 
                pontosCarta1 += (carta1->NumeroDePontosTuristicos > carta2->NumeroDePontosTuristicos) ? 1 : 0;
                pontosCarta2 += (carta2->NumeroDePontosTuristicos > carta1->NumeroDePontosTuristicos) ? 1 : 0; break;
        case 5: nomeAtributo2 = "Densidade Populacional"; 
                pontosCarta1 += (carta1->DensidadePopulacional < carta2->DensidadePopulacional) ? 1 : 0;
                pontosCarta2 += (carta2->DensidadePopulacional < carta1->DensidadePopulacional) ? 1 : 0; break;
        case 6: nomeAtributo2 = "PIB per Capita"; 
                pontosCarta1 += (carta1->PiBPerCapita > carta2->PiBPerCapita) ? 1 : 0;
                pontosCarta2 += (carta2->PiBPerCapita > carta1->PiBPerCapita) ? 1 : 0; break;
        default: nomeAtributo2 = "Inválido"; break;
    }
    
    printf("\n========== COMPARAÇÃO DE DOIS ATRIBUTOS ==========\n");
    printf("Primeiro Atributo: %s\n", nomeAtributo1);
    printf("Segundo Atributo: %s\n\n", nomeAtributo2);
    printf("Pontos %s: %d\n", carta1->NomeDaCidade, pontosCarta1);
    printf("Pontos %s: %d\n\n", carta2->NomeDaCidade, pontosCarta2);
    
    if (pontosCarta1 > pontosCarta2)
        printf("🏆 Vencedor: %s!\n", carta1->NomeDaCidade);
    else if (pontosCarta2 > pontosCarta1)
        printf("🏆 Vencedor: %s!\n", carta2->NomeDaCidade);
    else
        printf("⚖️ EMPATE!\n");
}

// Função para o menu principal
void exibirMenuPrincipal() {
    printf("\n========== SUPER TRUNFO - PAÍSES ==========\n");
    printf("1 - Nível Aventureiro (Menu com Comparação de Um Atributo)\n");
    printf("2 - Nível Mestre (Comparação de Dois Atributos)\n");
    printf("0 - Sair\n");
    printf("==========================================\n");
}

int main() {
    Carta carta1, carta2;
    int nivelEscolhido, atributo, atributo1, atributo2, opcao;
    
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   BEM-VINDO AO DESAFIO SUPER TRUNFO      ║\n");
    printf("║   Comparação de Cartas de Cidades        ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição das cartas cadastradas
    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);
    
    // Menu principal
    do {
        exibirMenuPrincipal();
        printf("Escolha uma opção: ");
        scanf("%d", &nivelEscolhido);
        
        switch(nivelEscolhido) {
            case 1: // Nível Aventureiro
                do {
                    exibirMenuAtributos();
                    printf("Escolha um atributo para comparação: ");
                    scanf("%d", &atributo);
                    
                    if (atributo == 0) {
                        printf("Voltando ao menu principal...\n");
                        break;
                    } else if (atributo >= 1 && atributo <= 6) {
                        compararAtributo(&carta1, &carta2, atributo);
                    } else {
                        printf("Opção inválida! Tente novamente.\n");
                    }
                } while(1);
                break;
                
            case 2: // Nível Mestre
                do {
                    printf("\n========== NÍVEL MESTRE ==========\n");
                    exibirMenuAtributos();
                    printf("Escolha o PRIMEIRO atributo: ");
                    scanf("%d", &atributo1);
                    
                    if (atributo1 == 0) {
                        printf("Voltando ao menu principal...\n");
                        break;
                    }
                    
                    if (atributo1 < 1 || atributo1 > 6) {
                        printf("Opção inválida! Tente novamente.\n");
                        continue;
                    }
                    
                    exibirMenuAtributos();
                    printf("Escolha o SEGUNDO atributo: ");
                    scanf("%d", &atributo2);
                    
                    if (atributo2 == 0) {
                        printf("Voltando ao menu principal...\n");
                        break;
                    }
                    
                    if (atributo2 < 1 || atributo2 > 6) {
                        printf("Opção inválida! Tente novamente.\n");
                        continue;
                    }
                    
                    compararDoisAtributos(&carta1, &carta2, atributo1, atributo2);
                } while(1);
                break;
                
            case 0:
                printf("\nObrigado por jogar! Até logo!\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(nivelEscolhido != 0);
    
    return 0;
}

// Estrutura para armazenar dados da carta
typedef struct {
    char Estado;
    char CodigoDaCarta[10];
    char NomeDaCidade[40];
    int Populacao;
    float Area;
    float PIB;
    int NumeroDePontosTuristicos;
    float DensidadePopulacional;
    float PiBPerCapita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\n========== CADASTRO DA CARTA %d ==========\n", numero);
    
    printf("Digite a letra do estado: ");
    scanf(" %c", &carta->Estado);
    
    printf("Digite o codigo da carta: ");
    scanf("%9s", carta->CodigoDaCarta);
    
    printf("Digite o nome da cidade: ");
    getchar(); // Limpa o buffer
    fgets(carta->NomeDaCidade, sizeof(carta->NomeDaCidade), stdin);
    carta->NomeDaCidade[strcspn(carta->NomeDaCidade, "\n")] = 0;
    
    printf("Digite o numero da população: ");
    scanf("%d", &carta->Populacao);
    
    printf("Digite a area da cidade (em km²): ");
    scanf("%f", &carta->Area);
    
    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->PIB);
    
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->NumeroDePontosTuristicos);
    
    // Cálculos dos atributos derivados
    carta->DensidadePopulacional = (float)carta->Populacao / carta->Area;
    carta->PiBPerCapita = (carta->PIB * 1000000000) / (float)carta->Populacao;
}

// Função para exibir dados da carta
void exibirCarta(Carta *carta, int numero) {
    printf("\n========== CARTA %d ==========\n", numero);
    printf("Estado: %c\n", carta->Estado);
    printf("Codigo: %s\n", carta->CodigoDaCarta);
    printf("Cidade: %s\n", carta->NomeDaCidade);
    printf("População: %d habitantes\n", carta->Populacao);
    printf("Area: %.2f km²\n", carta->Area);
    printf("PIB: %.2f bilhões de reais\n", carta->PIB);
    printf("Pontos Turisticos: %d\n", carta->NumeroDePontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->DensidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta->PiBPerCapita);
}

// Função para exibir menu de atributos
void exibirMenuAtributos() {
    printf("\n========== MENU DE ATRIBUTOS ==========\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("0 - Sair\n");
    printf("=====================================\n");
}

// Função para comparar um atributo específico (Nível Aventureiro)
void compararAtributo(Carta *carta1, Carta *carta2, int atributo) {
    char *nomeAtributo;
    char *vencedor;
    
    switch(atributo) {
        case 1: // População
            nomeAtributo = "População";
            vencedor = (carta1->Populacao > carta2->Populacao) ? carta1->NomeDaCidade :
                      (carta2->Populacao > carta1->Populacao) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%d)\n", carta1->NomeDaCidade, carta1->Populacao);
            printf("Cidade 2: %s (%d)\n", carta2->NomeDaCidade, carta2->Populacao);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 2: // Área
            nomeAtributo = "Área";
            vencedor = (carta1->Area > carta2->Area) ? carta1->NomeDaCidade :
                      (carta2->Area > carta1->Area) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f km²)\n", carta1->NomeDaCidade, carta1->Area);
            printf("Cidade 2: %s (%.2f km²)\n", carta2->NomeDaCidade, carta2->Area);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 3: // PIB
            nomeAtributo = "PIB";
            vencedor = (carta1->PIB > carta2->PIB) ? carta1->NomeDaCidade :
                      (carta2->PIB > carta1->PIB) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f bilhões)\n", carta1->NomeDaCidade, carta1->PIB);
            printf("Cidade 2: %s (%.2f bilhões)\n", carta2->NomeDaCidade, carta2->PIB);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 4: // Pontos Turísticos
            nomeAtributo = "Pontos Turísticos";
            vencedor = (carta1->NumeroDePontosTuristicos > carta2->NumeroDePontosTuristicos) ? carta1->NomeDaCidade :
                      (carta2->NumeroDePontosTuristicos > carta1->NumeroDePontosTuristicos) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%d)\n", carta1->NomeDaCidade, carta1->NumeroDePontosTuristicos);
            printf("Cidade 2: %s (%d)\n", carta2->NomeDaCidade, carta2->NumeroDePontosTuristicos);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 5: // Densidade Populacional (menor vence)
            nomeAtributo = "Densidade Populacional";
            vencedor = (carta1->DensidadePopulacional < carta2->DensidadePopulacional) ? carta1->NomeDaCidade :
                      (carta2->DensidadePopulacional < carta1->DensidadePopulacional) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f hab/km²)\n", carta1->NomeDaCidade, carta1->DensidadePopulacional);
            printf("Cidade 2: %s (%.2f hab/km²)\n", carta2->NomeDaCidade, carta2->DensidadePopulacional);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        case 6: // PIB per Capita
            nomeAtributo = "PIB per Capita";
            vencedor = (carta1->PiBPerCapita > carta2->PiBPerCapita) ? carta1->NomeDaCidade :
                      (carta2->PiBPerCapita > carta1->PiBPerCapita) ? carta2->NomeDaCidade : "Empate";
            printf("\n--- Comparação de %s ---\n", nomeAtributo);
            printf("Cidade 1: %s (%.2f reais)\n", carta1->NomeDaCidade, carta1->PiBPerCapita);
            printf("Cidade 2: %s (%.2f reais)\n", carta2->NomeDaCidade, carta2->PiBPerCapita);
            if (strcmp(vencedor, "Empate") == 0)
                printf("Resultado: EMPATE!\n");
            else
                printf("Vencedor: %s\n", vencedor);
            break;
            
        default:
            printf("Opção inválida!\n");
    }
}

// Função para comparar dois atributos (Nível Mestre)
void compararDoisAtributos(Carta *carta1, Carta *carta2, int atributo1, int atributo2) {
    int pontosCarta1 = 0, pontosCarta2 = 0;
    char *nomeAtributo1, *nomeAtributo2;
    
    // Comparação do primeiro atributo
    switch(atributo1) {
        case 1: nomeAtributo1 = "População"; 
                pontosCarta1 += (carta1->Populacao > carta2->Populacao) ? 1 : 0;
                pontosCarta2 += (carta2->Populacao > carta1->Populacao) ? 1 : 0; break;
        case 2: nomeAtributo1 = "Área"; 
                pontosCarta1 += (carta1->Area > carta2->Area) ? 1 : 0;
                pontosCarta2 += (carta2->Area > carta1->Area) ? 1 : 0; break;
        case 3: nomeAtributo1 = "PIB"; 
                pontosCarta1 += (carta1->PIB > carta2->PIB) ? 1 : 0;
                pontosCarta2 += (carta2->PIB > carta1->PIB) ? 1 : 0; break;
        case 4: nomeAtributo1 = "Pontos Turísticos"; 
                pontosCarta1 += (carta1->NumeroDePontosTuristicos > carta2->NumeroDePontosTuristicos) ? 1 : 0;
                pontosCarta2 += (carta2->NumeroDePontosTuristicos > carta1->NumeroDePontosTuristicos) ? 1 : 0; break;
        case 5: nomeAtributo1 = "Densidade Populacional"; 
                pontosCarta1 += (carta1->DensidadePopulacional < carta2->DensidadePopulacional) ? 1 : 0;
                pontosCarta2 += (carta2->DensidadePopulacional < carta1->DensidadePopulacional) ? 1 : 0; break;
        case 6: nomeAtributo1 = "PIB per Capita"; 
                pontosCarta1 += (carta1->PiBPerCapita > carta2->PiBPerCapita) ? 1 : 0;
                pontosCarta2 += (carta2->PiBPerCapita > carta1->PiBPerCapita) ? 1 : 0; break;
        default: nomeAtributo1 = "Inválido"; break;
    }
    
    // Comparação do segundo atributo
    switch(atributo2) {
        case 1: nomeAtributo2 = "População"; 
                pontosCarta1 += (carta1->Populacao > carta2->Populacao) ? 1 : 0;
                pontosCarta2 += (carta2->Populacao > carta1->Populacao) ? 1 : 0; break;
        case 2: nomeAtributo2 = "Área"; 
                pontosCarta1 += (carta1->Area > carta2->Area) ? 1 : 0;
                pontosCarta2 += (carta2->Area > carta1->Area) ? 1 : 0; break;
        case 3: nomeAtributo2 = "PIB"; 
                pontosCarta1 += (carta1->PIB > carta2->PIB) ? 1 : 0;
                pontosCarta2 += (carta2->PIB > carta1->PIB) ? 1 : 0; break;
        case 4: nomeAtributo2 = "Pontos Turísticos"; 
                pontosCarta1 += (carta1->NumeroDePontosTuristicos > carta2->NumeroDePontosTuristicos) ? 1 : 0;
                pontosCarta2 += (carta2->NumeroDePontosTuristicos > carta1->NumeroDePontosTuristicos) ? 1 : 0; break;
        case 5: nomeAtributo2 = "Densidade Populacional"; 
                pontosCarta1 += (carta1->DensidadePopulacional < carta2->DensidadePopulacional) ? 1 : 0;
                pontosCarta2 += (carta2->DensidadePopulacional < carta1->DensidadePopulacional) ? 1 : 0; break;
        case 6: nomeAtributo2 = "PIB per Capita"; 
                pontosCarta1 += (carta1->PiBPerCapita > carta2->PiBPerCapita) ? 1 : 0;
                pontosCarta2 += (carta2->PiBPerCapita > carta1->PiBPerCapita) ? 1 : 0; break;
        default: nomeAtributo2 = "Inválido"; break;
    }
    
    printf("\n========== COMPARAÇÃO DE DOIS ATRIBUTOS ==========\n");
    printf("Primeiro Atributo: %s\n", nomeAtributo1);
    printf("Segundo Atributo: %s\n\n", nomeAtributo2);
    printf("Pontos %s: %d\n", carta1->NomeDaCidade, pontosCarta1);
    printf("Pontos %s: %d\n\n", carta2->NomeDaCidade, pontosCarta2);
    
    if (pontosCarta1 > pontosCarta2)
        printf("🏆 Vencedor: %s!\n", carta1->NomeDaCidade);
    else if (pontosCarta2 > pontosCarta1)
        printf("🏆 Vencedor: %s!\n", carta2->NomeDaCidade);
    else
        printf("⚖️ EMPATE!\n");
}

// Função para o menu principal
void exibirMenuPrincipal() {
    printf("\n========== SUPER TRUNFO - PAÍSES ==========\n");
    printf("1 - Nível Aventureiro (Menu com Comparação de Um Atributo)\n");
    printf("2 - Nível Mestre (Comparação de Dois Atributos)\n");
    printf("0 - Sair\n");
    printf("==========================================\n");
}

int main() {
    Carta carta1, carta2;
    int nivelEscolhido, atributo, atributo1, atributo2, opcao;
    
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   BEM-VINDO AO DESAFIO SUPER TRUNFO      ║\n");
    printf("║   Comparação de Cartas de Cidades        ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição das cartas cadastradas
    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);
    
    // Menu principal
    do {
        exibirMenuPrincipal();
        printf("Escolha uma opção: ");
        scanf("%d", &nivelEscolhido);
        
        switch(nivelEscolhido) {
            case 1: // Nível Aventureiro
                do {
                    exibirMenuAtributos();
                    printf("Escolha um atributo para comparação: ");
                    scanf("%d", &atributo);
                    
                    if (atributo == 0) {
                        printf("Voltando ao menu principal...\n");
                        break;
                    } else if (atributo >= 1 && atributo <= 6) {
                        compararAtributo(&carta1, &carta2, atributo);
                    } else {
                        printf("Opção inválida! Tente novamente.\n");
                    }
                } while(1);
                break;
                
            case 2: // Nível Mestre
                do {
                    printf("\n========== NÍVEL MESTRE ==========\n");
                    exibirMenuAtributos();
                    printf("Escolha o PRIMEIRO atributo: ");
                    scanf("%d", &atributo1);
                    
                    if (atributo1 == 0) {
                        printf("Voltando ao menu principal...\n");
                        break;
                    }
                    
                    if (atributo1 < 1 || atributo1 > 6) {
                        printf("Opção inválida! Tente novamente.\n");
                        continue;
                    }
                    
                    exibirMenuAtributos();
                    printf("Escolha o SEGUNDO atributo: ");
                    scanf("%d", &atributo2);
                    
                    if (atributo2 == 0) {
                        printf("Voltando ao menu principal...\n");
                        break;
                    }
                    
                    if (atributo2 < 1 || atributo2 > 6) {
                        printf("Opção inválida! Tente novamente.\n");
                        continue;
                    }
                    
                    compararDoisAtributos(&carta1, &carta2, atributo1, atributo2);
                } while(1);
                break;
                
            case 0:
                printf("\nObrigado por jogar! Até logo!\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(nivelEscolhido != 0);
    
    return 0;
}