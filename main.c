
#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"
#include "bot.h"



int main() {
    char linha[256];
    char c;
    char s[256];
    STACK st;
    ESTADO e = {0};
    do {
        printf("Escolha um comando!\n"
               "Reversi> ");
        fgets(linha, 256, stdin);
        switch (toupper(linha[0])) {
            case 'N': {
                e = reset(e, linha);
                printf("\n");
                printa(e);
                printf("\n");
                iniciarStack(e, &st);
                break;
            }
            case 'A': {
                e = automatico(e, linha);
                printf("\n");
                printa(e);
                printf("\n");
                iniciarStack(e, &st);
                break;
            }
            case 'J': {
                int c1, c2;
                sscanf(linha, "%c %d %d", &c, &c1, &c2);
                e = jogar_geral(e, c1, c2);
                printf("\n");
                printa(e);
                printf("\n");
                alterarStack(e, &st);
                break;
            }
            case 'S': {
                posvalidas(e);
                break;
            }
            case 'H': {
                sugestao(e);
                break;
            }
            case 'U': {
                e = undo(e, &st);
                break;
            }
            case 'L': {
                sscanf(linha, "%c %s", &c, s);
                e = ler(e, s);
                iniciarStack(e, &st);
                printa(e);
                printf("\n");
                break;
            }
            case 'E': {
                sscanf(linha, "%c %s", &c, s);
                escrever(e, s);
                break;
            }
            case 'Q':
                exit(0);

            default: {
                printf("Comando Invalido \n");
                break;
            }
        }
    } while (toupper(linha[0]) != 'Q');
    return 0;
}

