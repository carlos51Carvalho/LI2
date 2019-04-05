#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"

ESTADO joga (ESTADO e) {
        char linha[256];
        int i;
        fgets(linha,256,stdin);
            switch(toupper(linha[0])) {
                case 'N': {
                    e = reset(e,linha);
                    break;
                }
                case 'J': {
                    e = jogada(e,&linha[2);
                    break;
                }
                case 'Q':
                    exit(0);

                default: {
                    printf("comando invalido \n");
                    break;
                }
            }
        }


/*void jogar (ESTADO e,int x, int y){
}*/

// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e)
{
    char c = ' ';


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
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

}

