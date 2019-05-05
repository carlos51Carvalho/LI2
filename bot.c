

#include "bot.h"
#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"



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
            e.modo=1;
        }else if (linha[i] == '2'){
            e.modo =2;
        }else e.modo = 3;
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

/*
ESTADO bot_1 (ESTADO e) {
    int i,j,r = 0;
    printf("  0 1 2 3 4 5 6 7\n");
    i = 0;
    while(i<8 && r == 0)
    {
        j = 0;
        while(j<8 && r == 0)
        {


            if (e.grelha[i][j] == VAZIA && valida(e,i,j))
                r = 1;
            printf("%d %d\n", i, j);
            j++;
        }
        i++;

    }

    if(r == 1)
        e = jogar(e,i,j);
    else
        printf("jogador %c passa \n",(e.peca == VALOR_X  ? 'X' : 'O'));

    return e;
}

*/

ESTADO bot_1 (ESTADO e) {
    int i,j,r = 0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (valida(e,i,j) && r == 0){
                e = jogar(e,i,j);
                r++;
            }
        }
        }
    return e;
}
