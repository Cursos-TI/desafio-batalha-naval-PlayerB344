#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAMANHO_NAVIO 3
#define TAM_HAB 5 // Tamanho das matrizes de habilidade (5x5)

// Verifica sobreposição
int verificar_sobreposicao(int tabuleiro[TAM][TAM], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0)
            return 1;
    }
    return 0;
}

// Posiciona navio
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * d_linha][coluna + i * d_coluna] = 3;
    }
}

// Aplica matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origem_linha + (i - offset);
            int coluna = origem_coluna + (j - offset);
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && matriz[i][j] == 1) {
                if (tabuleiro[linha][coluna] == 0) // não sobrescreve navios
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

// Cria habilidade CONE
void criar_habilidade_cone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (j >= 2 - i && j <= 2 + i) ? 1 : 0;
        }
    }
}

// Cria habilidade CRUZ
void criar_habilidade_cruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Cria habilidade OCTAEDRO
void criar_habilidade_octaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
        }
    }
}

// Mostra o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n    ");
    for (int col = 0; col < TAM; col++)
        printf("%2d ", col);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~ ");
            else if (tabuleiro[i][j] == 3)
                printf(" N ");
            else if (tabuleiro[i][j] == 5)
                printf(" * ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    printf("                     ### BATALHA NAVAL ###\n\n");

    // Posicionamento dos navios (igual ao seu código)
    int linha, coluna;
    printf("Navio 1 (HORIZONTAL):\nLinha (0-9): "); scanf("%d", &linha);
    printf("Coluna inicial (0-9): "); scanf("%d", &coluna);
    if (coluna + TAMANHO_NAVIO <= TAM && !verificar_sobreposicao(tabuleiro, linha, coluna, 0, 1))
        posicionar_navio(tabuleiro, linha, coluna, 0, 1);

    printf("Navio 2 (VERTICAL):\nLinha inicial (0-9): "); scanf("%d", &linha);
    printf("Coluna (0-9): "); scanf("%d", &coluna);
    if (linha + TAMANHO_NAVIO <= TAM && !verificar_sobreposicao(tabuleiro, linha, coluna, 1, 0))
        posicionar_navio(tabuleiro, linha, coluna, 1, 0);

    printf("Navio 3 (DIAGONAL ↘):\nLinha inicial (0-9): "); scanf("%d", &linha);
    printf("Coluna inicial (0-9): "); scanf("%d", &coluna);
    if (linha + TAMANHO_NAVIO <= TAM && coluna + TAMANHO_NAVIO <= TAM && !verificar_sobreposicao(tabuleiro, linha, coluna, 1, 1))
        posicionar_navio(tabuleiro, linha, coluna, 1, 1);

    printf("Navio 4 (DIAGONAL ↙):\nLinha inicial (0-9): "); scanf("%d", &linha);
    printf("Coluna inicial (0-9): "); scanf("%d", &coluna);
    if (linha + TAMANHO_NAVIO <= TAM && coluna - (TAMANHO_NAVIO - 1) >= 0 && !verificar_sobreposicao(tabuleiro, linha, coluna, 1, -1))
        posicionar_navio(tabuleiro, linha, coluna, 1, -1);

    // Habilidades
    int habilidade[TAM_HAB][TAM_HAB];
    int origem_linha, origem_coluna;

    // Cone
    criar_habilidade_cone(habilidade);
    printf("\nHabilidade CONE - Informe origem (linha e coluna): ");
    scanf("%d %d", &origem_linha, &origem_coluna);
    aplicar_habilidade(tabuleiro, habilidade, origem_linha, origem_coluna);

    // Cruz
    criar_habilidade_cruz(habilidade);
    printf("\nHabilidade CRUZ - Informe origem (linha e coluna): ");
    scanf("%d %d", &origem_linha, &origem_coluna);
    aplicar_habilidade(tabuleiro, habilidade, origem_linha, origem_coluna);

    // Octaedro
    criar_habilidade_octaedro(habilidade);
    printf("\nHabilidade OCTAEDRO - Informe origem (linha e coluna): ");
    scanf("%d %d", &origem_linha, &origem_coluna);
    aplicar_habilidade(tabuleiro, habilidade, origem_linha, origem_coluna);

    // Mostrar resultado
    exibir_tabuleiro(tabuleiro);

    //Exibir Legenda do Tabuleiro
    printf("\n LEGENDA:\n N = Navio\n * = Habilidade\n ~ = Água");

    return 0;
}
