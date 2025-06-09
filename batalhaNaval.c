#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 10
#define TAMANHO_NAVIO 3

// Função para verificar sobreposição para qualquer direção
int verificar_sobreposicao(int tabuleiro[TAM][TAM], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0)
            return 1; // sobreposição ou fora dos limites
    }
    return 0; // sem sobreposição
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * d_linha][coluna + i * d_coluna] = 3;
    }
}

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

    // Navio 1 - Horizontal
    int linha_h, coluna_h;
    printf("Navio 1 (HORIZONTAL):\nLinha (0 a 9): ");
    scanf("%d", &linha_h);
    printf("Coluna inicial (0 a 9): ");
    scanf("%d", &coluna_h);

    if (coluna_h + TAMANHO_NAVIO <= TAM &&
        !verificar_sobreposicao(tabuleiro, linha_h, coluna_h, 0, 1)) {
        posicionar_navio(tabuleiro, linha_h, coluna_h, 0, 1);
    } else {
        printf("Erro: posição inválida ou sobreposição no navio horizontal.\n");
    }

    // Navio 2 - Vertical
    int linha_v, coluna_v;
    printf("\nNavio 2 (VERTICAL):\nLinha inicial (0 a 9): ");
    scanf("%d", &linha_v);
    printf("Coluna (0 a 9): ");
    scanf("%d", &coluna_v);

    if (linha_v + TAMANHO_NAVIO <= TAM &&
        !verificar_sobreposicao(tabuleiro, linha_v, coluna_v, 1, 0)) {
        posicionar_navio(tabuleiro, linha_v, coluna_v, 1, 0);
    } else {
        printf("Erro: posição inválida ou sobreposição no navio vertical.\n");
    }

    // Navio 3 - Diagonal principal (↘)
    int linha_d1, coluna_d1;
    printf("\nNavio 3 (DIAGONAL ↘):\nLinha inicial (0 a 9): ");
    scanf("%d", &linha_d1);
    printf("Coluna inicial (0 a 9): ");
    scanf("%d", &coluna_d1);

    if (linha_d1 + TAMANHO_NAVIO <= TAM && coluna_d1 + TAMANHO_NAVIO <= TAM &&
        !verificar_sobreposicao(tabuleiro, linha_d1, coluna_d1, 1, 1)) {
        posicionar_navio(tabuleiro, linha_d1, coluna_d1, 1, 1);
    } else {
        printf("Erro: posição inválida ou sobreposição no navio diagonal ↘.\n");
    }

    // Navio 4 - Diagonal secundária (↙)
    int linha_d2, coluna_d2;
    printf("\nNavio 4 (DIAGONAL ↙):\nLinha inicial (0 a 9): ");
    scanf("%d", &linha_d2);
    printf("Coluna inicial (0 a 9): ");
    scanf("%d", &coluna_d2);

    if (linha_d2 + TAMANHO_NAVIO <= TAM && coluna_d2 - (TAMANHO_NAVIO - 1) >= 0 &&
        !verificar_sobreposicao(tabuleiro, linha_d2, coluna_d2, 1, -1)) {
        posicionar_navio(tabuleiro, linha_d2, coluna_d2, 1, -1);
    } else {
        printf("Erro: posição inválida ou sobreposição no navio diagonal ↙.\n");
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
