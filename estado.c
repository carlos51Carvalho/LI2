#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"
#include <stdio.h>
#include "bot.h"


/**
 * @brief, para além do estado, o nosso ecrã de jogo também terá o modo em que nos encontramos, o numero de peças de cada jogador e a vez do jogador a jogar.
 * @param e , a função recebe o estado atual, que será printado.
 */
void printa(ESTADO e) {
    char c = ' ';
    if (e.modo == '0') printf("Manual\n");
    else if (e.modo =='1' ) printf("Automatico 1 \n\n");
    else if (e.modo =='2' ) printf("Automatico 2 \n\n");
    else printf("Automatico 3 \n\n");

    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0) printf("%d ",i);
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }
    printf("X = %d  O = %d \n \n ", numPecas_X(e), numPecas_O(e));

    if (e.peca== VALOR_X) printf("Vez do jogador X\n");
    else printf("Vez do jogador O \n");
}


/**
 * @brief , esta função irá dar reset ao nosso estado atual e criará um novo estado, que é o estado inicial de um possível novo jogo.
 * @param e , recebe o estado atual
 * @param linha , procurará a indicação do jogador que começará a jogar.
 * @return , a função retornará o estado inicial do jogo.
 */
ESTADO reset (ESTADO e,char linha[]) {
    int i=1, j;
    e.modo = '0';
    while (linha[i]==' ') {
        i++;
        if (toupper(linha[i]) == 'X') e.peca = VALOR_X;
        else e.peca = VALOR_O;
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            e.grelha[i][j] = VAZIA;
        }
    }

    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    return e;
}

/**
 * @brief , esta função irá dar reset ao nosso estado atual e criará um novo estado, que é o estado inicial de um possível novo jogo, onde o jogador terá como oponente um determinado bot.
 * @param e , recebe o estado atual
 * @param linha , procurará a indicação do jogador que começará a jogar e a dificuldade do jogador adversário (bot) .
 * @return , a função retornará o estado inicial do jogo.
 */

ESTADO automatico (ESTADO e,char linha[]) {
    int i = 1, j;
    while (linha[i] == ' '){
        i++;
        if (toupper(linha[i]) == 'X') e.peca = VALOR_X;
        else e.peca = VALOR_O;
    }
    i++;
    while (linha[i] == ' '){
        i++;
        if (linha[i] == '1'){
            e.modo = '1';
        }else if (linha[i] == '2'){
            e.modo = '2';
        }else e.modo = '3';
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            e.grelha[i][j] = VAZIA;
        }
    }

    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    return e;
}




/**
 * @brief , a função percorre a matriz toda através de dois ciclos "for" e irá dar print do estado, com "." nas jogadas válidas.
 * @param e , a função recebe um estado para através dele encontrar as posições válidas para o jogador a jogar.
 */
void posvalidas (ESTADO e){
    int l,c;
    printf("  0 1 2 3 4 5 6 7\n");
    for(l=0; l<8 ; l++){
        for(c=0; c<8; c++){
            if(c==0) printf("%d ",l);
            if (e.grelha[l][c]==VALOR_X) printf("X ");
            else if(e.grelha[l][c]==VALOR_O) printf("O ");
            else if(valida(e,l,c)==1) printf(". ");
            else printf("- ");
        }
        printf("\n");
    }
}




/**
 * @brief , esta função irá printar um "?" na posição que será a sugestão, essa sugestão será preferencialmente um dos quatro cantos.
 * Sendo que se não for possivel jogar nos cantos esta função encontrará a posição em que é possivel comer mais peças do adversário. Através de percorrer matriz por dois ciclos for.
 * @param e , recebe o estado atual do jogo.
 */
void sugestao (ESTADO e){
    int i,j,resx=0,resy=0;
    for(i=0; i<8 ; i++){
        for(j=0 ; j<8 ; j++){
            if (valida(e, 0, 0)){
                resx = 0;
                resy = 0;
            }
            else if (valida(e, 7, 7)){
                resx = 7;
                resy = 7;
            }
            else if (valida(e, 0, 7)){
                resx = 0;
                resy = 7;
            }
            else if (valida(e, 7, 0)){
                resx = 7;
                resy = 0;
            }
            else if(quantas(e,i,j) > quantas(e,resx,resy)) {
                resx=i;
                resy=j;
            }
        }
    }
    int r=0;
    printf("  0 1 2 3 4 5 6 7\n");
    for(i=0; i<8 ; i++) {
        for (j = 0; j < 8; j++) {
            if (j == 0) printf("%d ", i);
            if (i == resx && j == resy && r == 0) {
                printf("? ");
                r++;
            }
            else if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else printf("- ");
        }
        printf("\n");
    }
}






/**
 * @brief Esta função irá jogar e fazer o jogo avançar, se nos encontrarmos no e.modo 0, o estado irá avançar conforme o jogador X ou O jogue.
          Caso o e.modo seja diferente de 0, primeiro o jogador joga na posição que pretender (l,c) e seguidamente jogará o bot, e o jogo avançará dessa forma.
 * @param e , a função recebe o estado atual.
 * @param l , recebe uma linha, da posição onde se pretende jogar.
 * @param c , recebe uma coluna, da posição onde se pretende jogar.
 * @return  , retorna o estado após se ter jogado na posição dada.
 */

ESTADO jogar_geral (ESTADO e, int l, int c) {
    if (e.modo == '0') {
        e = jogar(e, l, c);
        printf("\n");
        printa(e);
        printf("\n");
    } else if(e.modo == '1') {
        if(valida(e,l,c)!=0){
            e = jogar(e, l, c);
            printf("\n");
            printa(e);
            printf("\n");
            e = bot_1(e);
        }
    }
    else if (e.modo == '2') {
        if (valida(e, l, c) != 0) {
            e = jogar(e, l, c);
            printf("\n");
            printa(e);
            printf("\n");
            e = bot2(e);
        }
    }
    else if (e.modo == '3'){
        if(valida(e,l,c)!=0){
            e = jogar(e, l, c);
            printf("\n");
            printa(e);
            printf("\n");
            e = bot3(e);
        }

    }
    return e;

}




/**
 * função que lê um jogo guardado anteriormente no formato txt.
 * @param e estado corrente do jogo.
 * @param s ficheiro texto de onde se vai extrair a informação para transformar num estado
 * @return estado do jogo lido, podendo continuar um jogo pausado.
 */

ESTADO ler(ESTADO e, char s[]) {
    char s1,s2;
    FILE *reversi = fopen(s, "r");

    fscanf(reversi,"%c %c ", &s1,&s2 );

    if (toupper(s1) == 'A') e.modo='1';
    else e.modo='0';

    if(toupper(s2) == 'X') e.peca = VALOR_X;
    else e.peca = VALOR_O;

    for (int i = 0; i <8 ; i++)
    {
        for (int j = 0; j < 8 ; ++j)
        {
            fscanf(reversi, "%c ",&s1);
            if (s1 == 'X')
                e.grelha[i][j]=VALOR_X;
            else
            if (s1 == 'O')
                e.grelha[i][j]=VALOR_O;
            else
                e.grelha[i][j]=VAZIA;

        }
    }

    fclose(reversi);

    return e;

}


/**
 * Função que imprime dum estado um ficheiro texto.
 * @param e recebe o estado a guardar ( o estado corrente do jogo).
 * @param s recebe o nome do ficheiro onde guardar o estado (termiando em txt).
 */

void escrever(ESTADO e, char s[]) {
    char s1,s2,s3;

    FILE *reversi = fopen(s, "w");

    if (e.modo=='1') {
        s1 = 'A';
        s3 = '1'-48;
    }
    else if (e.modo=='2') {
        s1 = 'A';
        s3 = '2'-48;
    }
    else if (e.modo=='3') {
        s1 = 'A';
        s3 = '3'-48;
    }
    else {s1 = 'M';}

    if (e.peca == VALOR_X) s2 = 'X';
    else s2 = 'O';

    if(e.modo == '0')
        fprintf(reversi,"%c %c \n", s1,s2 );
    else
        fprintf(reversi,"%c %c %d\n", s1,s2,s3 );

    for (int i = 0; i <8 ; i++)
    {
        for (int j = 0; j < 8 ; ++j)
        {
            if (e.grelha[i][j]==VALOR_X) s1 = 'X';
            else if (e.grelha[i][j]==VALOR_O) s1 = 'O';
            else s1 = '-';
            fprintf(reversi,"%c ", s1);

        }
        fprintf(reversi,"\n");
    }
    fclose(reversi);
}

