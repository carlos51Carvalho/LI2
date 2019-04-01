#include <stdio.h>
#include "estado.h"
#include <ctype.h>

ESTADO joga (ESTADO e, int x, int y) {
        do {gets(linha);
            switch(toupper(linha[0]) {
                case 'N': {
                    scanf(linha, "%c %c", &c1 & c2)
                    if (c2 == 'x') {
                        e = inc(e, VALOR_X);
                        e = inc(e, VALOR_O);
                    } else break;
                }
                case 'J': {
                    scanf(linha, "%c %d %d", &c1, &x, &y);
                    e = jogar(e, x, y);
                    break;
                }
                case 'O':
                    break;

                default: {
                    printf("comando invalido \n");
                    break;
                }
            }
        } while (toupper(linha[0])!='Q')
}


void jogar (ESTADO e,int x, int y){

    }

}
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

