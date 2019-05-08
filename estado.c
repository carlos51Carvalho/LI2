#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"
#include <stdio.h>
#include "bot.h"

// exemplo de uma função para imprimir o estado (Tabuleiro)




void printa(ESTADO e) {
    char c = ' ';
    if (e.modo == 0) printf("Manual\n");
    else if (e.modo ==1 ) printf("Automatico 1 \n\n");
    else if (e.modo ==2 ) printf("Automatico 2 \n\n");
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

    if (e.peca== VALOR_X) printf("Jogador X\n");
    else printf("Jogador O \n");
}



ESTADO reset (ESTADO e,char linha[]) {
    int i=1, j;
    e.modo = 0;
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



void sugestao (ESTADO e) {
    int i,j,r = 0;
    printf("  0 1 2 3 4 5 6 7\n");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(j==0) printf("%d ",i);
            if (valida(e,i,j) && r == 0){
                printf("? ");
                r++;
            }
            else if (e.grelha[i][j]==VALOR_X) printf("X ");
            else if(e.grelha[i][j]==VALOR_O) printf("O ");
            else printf("- ");
        }
        printf("\n");
    }
}




ESTADO jogar_geral (ESTADO e, int l, int c) {
    VALOR h;
    h = e.peca;
    if (e.modo == 0) {
        e = jogar(e, l, c);
        printf("\n");
        printa(e);
        printf("\n");
    } else {
            e = jogar(e, l, c);
            printf("\n");
            printa(e);
            printf("\n");
            e = bot_1(e);
    }
        return e;

}



ESTADO ler(ESTADO e, char s[]) {
    char s1,s2;
    FILE *reversi = fopen(s, "r");

    fscanf(reversi,"%c %c ", &s1,&s2 );

    if (toupper(s1) == 'A') e.modo=1;
    else e.modo=0;

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

void escrever(ESTADO e, char s[]) {
    char s1,s2;
    FILE *reversi = fopen(s, "w");

    if (e.modo==1) s1 = 'A';
    else s1 = 'M';

    if (e.peca == VALOR_X) s2 = 'X';
    else s2 = 'O';

    fprintf(reversi,"%c %c \n", s1,s2 );

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

