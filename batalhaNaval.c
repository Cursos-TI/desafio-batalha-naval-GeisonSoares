#include <stdio.h>


int main() 
{
    // Criamos o tabuleiro de 10x10. Começamos tudo com água (valor 0).
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com água
    for (int linha = 0; linha < 10; linha++) 
    {
        for (int coluna = 0; coluna < 10; coluna++) 
        {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Agora criamos os navios como vetores. Cada posição vale 3.
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais para os navios (definidas diretamente no código)
    int linhaHorizontal = 9, colunaHorizontal = 7;  // Horizontal
    int linhaVertical = 3, colunaVertical = 4;  // Vertical

    // Primeiro vamos posicionar o navio HORIZONTAL (linha fixa, coluna varia)
    if (colunaHorizontal + 3 <= 10) 
    {
        int contraTorpedo = 1;
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0)
            {
                contraTorpedo = 0;
                break;
            }
        }

        if (contraTorpedo)
        {
            for (int i = 0; i < 3; i++)
            {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }
        }
    }

    // Agora o navio VERTICAL (coluna fixa, linha varia)
    if (linhaVertical + 3 <= 10) 
    {
        int SubmarinoNuc = 1;
        for (int i = 0; i < 3; i++) 
        {
            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) 
            {
                SubmarinoNuc = 0;
                break;
            }
        }

        if (SubmarinoNuc) 
        {
            for (int i = 0; i < 3; i++) 
            {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }
        }
    }

    // Agora vamos imprimir o tabuleiro com os navios posicionados
    printf("Tabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int linha = 0; linha < 10; linha++) 
    {
        for (int coluna = 0; coluna < 10; coluna++) 
        {

            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}