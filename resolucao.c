#include <stdio.h>
#include <stdlib.h> // alocacao de memoria 

// Variáveis globais
char tabuleiro[3][3];
int jogador;
int jogadas = 0; 

// Função para iniciar o tabuleiro
void iniciar_tabuleiro()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' '; // preenche todas as posições do tabuleiro com espaços vazios
        }
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro()
{
    printf("\n\n\t 0   1   2\n\n"); // numerar as colunas
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                printf("\t"); // 't' possui a funcao da tecla tab

            printf(" %c ", tabuleiro[i][j]); // espacamento entre '%c' serve para as colunas não ficarem mt juntas

            if (j < 2)
                printf("|");

            if (j == 2)
                printf("  %d", i); // numerar linha ( 0 1 2) apenas quando tiver impresso o caracter '2' da coluna 
        }
        printf("\n");

        if (i < 2) // necessario outro 'íf' para nao imprimir tracejado apos a linha '2'
            printf("\t-----------\n");
    }
}

// Função para realizar uma jogada
int realizar_jogada()
{
    int linha, coluna;

    printf("Jogador %d, digite a linha e a coluna que deseja jogar:\n", jogador);
    scanf("%d %d", &linha, &coluna);

    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ')
    {
        printf("Valores inválidos!\n");
        return 0;
    }

    if (jogador == 1)
        tabuleiro[linha][coluna] = 'X';
    else
        tabuleiro[linha][coluna] = 'O';

    jogadas++; // incrementa o numero de jogadas
    return 1;
}

// Função para verificar o tabuleiro e determinar se há um vencedor ou empate
int verificar_tabuleiro()
{
    // Verificar linhas
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
        {
            printf("Jogador %d venceu!\n", jogador);
            return 1;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++)
    {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' ')
        {
            printf("Jogador %d venceu!\n", jogador);
            return 1;
        }
    }

    // Verificar diagonais
    if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') ||
        (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' '))
    {
        printf("Jogador %d venceu!\n", jogador);
        return 1;
    }

    // Verificar empate
    if (jogadas == 9)
    {
        printf("Empate!\n");
        return 1;
    }

    return 0;
}

int main()
{
    int jogar_novamente = 1;

    while (jogar_novamente)
    {
        // Iniciar o jogo
        iniciar_tabuleiro();
        jogador = 1;
        jogadas = 0;

        while (1)
        {
            imprimir_tabuleiro();

            if (!realizar_jogada()) // o uso de '!' na frente da funcao verifica se a função realizar_jogada() retornou falso (se a jogada não foi realizada com sucesso)
                continue;

            if (verificar_tabuleiro())
                break;

            // Alternar jogador
            if (jogador == 1)
                jogador = 2;
            else
                jogador = 1;
        }

        printf("Deseja jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &jogar_novamente);
    }

    return 0;
}
