#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    printf("        ### BATALHA NAVAL ###\n\n");

    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAM][TAM] = {0};

    // Tamanho dos navios
    int tamanho_navio = 3;

    // Coordenadas do navio horizontal (linha, coluna inicial)
    int linha_h;
    int coluna_h;

    printf("\t\tO seu primeiro navio é HORIZONTAL!\n\nEscolha em qual linha você quer colocar:\nObs: Escolha um número de 0 a 9\n");
    scanf("%d", &linha_h);
    printf("\nAgora escolha a coluna:\nObs: Escolha um número de 0 a 9\n");
    scanf("%d", &coluna_h);

    // Coordenadas do navio vertical (linha inicial, coluna)
    int linha_v;
    int coluna_v;

    printf("\t\tO seu segundo navio é VERTICAL!\n\nEscolha em qual linha você quer colocar:\nObs: Escolha um número de 0 a 9\n");
    scanf("%d", &linha_v);
    printf("\nAgora escolha a coluna:\nObs: Escolha um número de 0 a 9\n");
    scanf("%d", &coluna_v);

    // Verificar se o navio horizontal cabe no tabuleiro
    if (coluna_h + tamanho_navio <= TAM) {
        // Verificar se não há sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            // Posicionar navio horizontal
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_h][coluna_h + i] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio horizontal!\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites!\n");
    }

    // Verificar se o navio vertical cabe no tabuleiro
    if (linha_v + tamanho_navio <= TAM) {
        // Verificar se não há sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            // Posicionar navio vertical
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio vertical!\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites!\n");
    }

    // Exibir o tabuleiro
    printf("\n    ");                               //exibir o numero das colunas
    for (int col = 0; col < TAM; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i);                         //exibir o numero das linhas
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
