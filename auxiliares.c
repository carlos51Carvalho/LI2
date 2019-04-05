#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"

ESTADO reset (ESTADO e,char linha[]) {
    int i, j;
    for (i = 0; linha[i] != toupper('x') && linha[i] != toupper('o'); i++) {
        if (toupper(linha[i]) == 'X') e.peca = VALOR_X;
        else if (toupper(linha[i]) == 'O') e.peca = VALOR_O;
        else e.peca = VAZIA;
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
            printf("\n");
            printa(e);
            printf("\n");
            return e;
}

ESTADO jogada (ESTADO e, char linha[]){
    int i,j,l,c;
    for (i = 0; toupper(linha[i])!='J' && linha[i]!= ' '; i++) {
        l = linha[i]-48;
        c = linha[i+2]-48;
    }
    if (e.peca==VALOR_O){
        e.grelha[l-1][c-1]=VALOR_O;
    }else {
        e.grelha[l-1][c-1]=VALOR_X;
    }
    printf("\n");
    printa(e);
    printf("\n");
    return e;
    }



int valida( ESTADO e, int l, int c) {
    int i, j, r = 0;
    if (e.grelha[l - 1][c] != e.peca || e.grelha[l + 1][c] != e.peca || e.grelha[l - 1][c - 1] != e.peca ||
        e.grelha[l - 1][c + 1] != e.peca || e.grelha[l + 1][c - 1] != e.peca || e.grelha[l + 1][c + 1] != e.peca ||
        e.grelha[l - 1][c] != e.peca || e.grelha[l][c - 1] != e.peca || e.grelha[l][c + 1] != e.peca) {
        r = 1;
    }
    if (r = 1) {
        //coluna para cima
        for (i = l; i > 0; --i) {
            if (e.grelha[i - 1][c] == e.peca) {
                r = 1;
            }else r=0;
        }//coluna para baixo
        for (i = l; i < 8; ++i) {
            if (e.grelha[i + 1][c] == e.peca) {
                r = 1;
            }
        }//linha para a esquerda
        for (i = c; i > 0; --i) {
            if (e.grelha[l][c - 1] == e.peca) {
                r = 1;
            }
        }
    }
}
