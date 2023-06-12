//implementacao do JOGO DA VELHA de tabuleiro parametrizavel
//pode ser uma constante definida no programa
//tabuleiro rudimentar, pode ser feito em N linhas de texto (marcando com um ponto as posicoes livres)
//jogadores identificados pelos simbolos 'O' e 'X'
//posicoes vazias representadas por ' ' (espaco em branco)
//jogadas alternadas, preenchendo um espaco de cada vez
//identificar quando os simbolos completarem uma linha horizontal, vertical ou diagonal se ganhar


#include <stdio.h>
#include <stdlib.h>

// variavies globais
char tabuleiro[3][3];
int i,j; // i = linha, j = coluna


//deve marcar as posicoes da matriz tabuleiro com caractere de espaco
void iniciar_tabuleiro (char tabuleiro[3][3])
{

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        
           tabuleiro[i][j] = ' ';
        
    }
}

//deve apresentar o tabuleiro na tela
void imprimir_tabuleiro (char tabuleiro[3][3])
{
   
    printf("\n\n\t 0   1   2\n\n"); // numerar coluna
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j == 0)
                printf("\t"); // 't' = mesma funcao da tecla tab
            
                printf(" %c ", tabuleiro[i][j]); // espaço antes e depois do '%c' para as linhas/colunas ficarem espaçadas 

            if (j < 2)
                printf("|");

            if (j == 2)
                printf("  %d", i); // numerar linha apenas quando tiver impresso o caracter 2 da coluna
             
        } 
                printf("\n");

            if (i < 2) // necessario outro 'íf' para nao imprimir tracejado apos a linha 2
                printf("\t-----------\n");           
    }
            
}


int realizar_jogada (int jogador, int linha, int coluna, char tabuleiro [3][3])
//recebe um numero para indicar o jogador (1 ou 2) e os valores de linha e coluna escolhidos pelo usuario
//se a posicao estiver dentro dos limites do tabuleiro e nao existir outro simbolo nesta posicao, marcar a posicao com o simbolo correspondente ao jogador

{
    int jogador = 0;

    do
    {   
        printf("JOGADOR %d: qual a linha (0 à 2) e a coluna (0 à 2) que deseja jogar? ", jogador);
        scanf("%d %d", &i, &j);
        
        if (jogador == 1)
        {
            tabuleiro[i][j] = 'O'; // jogador 1 joga
            jogador++; // variavel vai para 2
        } 
        else 
        {
            tabuleiro[i][j] = 'X'; // jogador 2 joga
            jogador = 1; // variavel volta a ser 1 pois a proxima jogada é ele quem faz
        }

        return 1;

    } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ');
    
    return 0;
    
}


int verificar_tabuleiro (char tabuleiro [3][3])
//deve procurar por uma condicao de fim de jogo
//sequencia ou empate, que ocorre quando todos os elementos forem preenchidos e nao houve sequencia
//retornar 1 se for final de jogo e 0 se nao for
{
    //ganhou X por colunas
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro [2][0] == 'X'){
        
        return 1;
    }
     else if(tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X'){
        
        return 1;
     }
     else if(tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X'){
        
        return 1;
    }


     //ganhou x por linhas
     else if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X'){
    
    return 1;
    }
    else if(tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X'){
    
    return 1;
    } 
    else if(tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'){
    
    return 1;
    }
    //ganhou X por diagonal 
    else if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
    
    return 1;
    }
    else if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'){
    
    return 1;
    }
    //ganhou O por coluna
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro [2][0] == 'O'){
    
    return 1;
    }
    else if(tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O'){
    
    return 1;
    }
    else if(tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'){
    
    return 1;
    }

    //ganhou O por linha
    if(tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O'){
    
    return 1;
    }
    else if(tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O'){
    
    return 1;
    }
    else if(tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'){
    
    return 1;
    }

    //ganhou O por diagonal 
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
    
    return 1;
    }
    else if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'){
    
    return 1; 
    }

    return 0;
}



int main()
{
    int jogar_novamente;

    do
    {
         iniciar_tabuleiro();
         imprimir_tabuleiro();
        printf("deseja jogar novamente? /n (1)Sim /n (2)Nao /n");
        scanf("%d", &jogar_novamente);

    } while (jogar_novamente == 1);

        return 0;
        

    //iniciar tabuleiro
    //imprimir tabuleiro
    //ler uma linha e uma coluna do jogador 1
    //realizar uma jogada - se for valida continuar, senao emitir erro e retornar o passo anterior
    //verificar o tabuleiro para condicao de fim de jogo - se for verdadeiro ir para o passo 10, senao continuar
    //imprimir o tabuleiro
    //ler uma linha e uma coluna do jogador 2
    //realizar uma jogada - se for valida continuar, senao emitir erro e retornar ao passo anterior
    //verificar o tabuleiro para condicao de fim de jogo - se for verdadeiro continuar, senao retornar ao passo 2
    //10- apresentar o tabuleiro e o vencedor
}
