#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"


const VALOR inv[] = {VAZIA,VALOR_O,VALOR_X};

int main() {
    char linha[256];
    char c;
    int i;
    char s[256];
    ESTADO e = {0};
    do {
        printf("Reversi> ");
        fgets(linha, 256, stdin);
        switch (toupper(linha[0])) {
            case 'N': {
                e = reset(e, linha);
                printf("\n");
                printa(e);
                printf("\n");
                break;
            }
            case 'J': {
                e = jogada(e, &linha[2]);
                printf("\n");
                printa(e);
                printf("\n");

                break;
            }
            case 'L':{
                sscanf(linha,"%c %s", &c, s);
                e = ler(e,s);
                printa(e);
            }
            case 'E':{
                sscanf(linha,"%c %s", &c, s);
                e = escrever(e,s);
                printa(e);
            }
            case 'S':{
                e = posvalidas(e);
                printa(e);
            }
            case 'Q':
                exit(0);

            default: {
                printf("comando invalido \n");
                break;
            }
        }
    }
        while (toupper(linha[0]) != 'Q');
        return 0;
}

