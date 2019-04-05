#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"

ESTADO reset (ESTADO e,char linha[]) {
    int i,j;
    for (i = 0; linha[i] != toupper('x') && linha[i]!= toupper('o');i++)
        if (toupper(linha[i]) == 'X') e.peca = VALOR_X;
        else if (toupper(linha[i]) == 'O') e.peca = VALOR_O;
        else e.peca = VAZIA;
    for (i = 0;i<8;i++)
        for (j = 0;j<8;j++)
            e.grelha[i][j] = VAZIA;
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}

ESTADO joga(ESTADO e,int l,int c){
}
