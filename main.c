#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"



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
                iniciarStack(e,&st);
                break;
            }
            case 'J': {
                int c1, c2;
                sscanf(linha,"%c %d %d", &c ,&c1, &c2);
                VALOR h;
                if (e.peca==VALOR_X) h = VALOR_O;
                else if(e.peca==VALOR_O) h = VALOR_X;
                else h=VAZIA;
                if (nenhumaValida(e)==1){printf("Nao tem jogadas possiveis. Perdeu a sua vez.\n"); e.peca=h;}
                if (valida(e, c1, c2) == 0) printf("Jogada Invalida. Tente outra jogada. \n");
                else {
                    e = jogar(e, c1, c2);
                    printf("\n");
                    printa(e);
                    printf("\n");
                }
                alterarStack(e,&st);
                if(finaliza(e)==1) { if (numPecas_O(e)>numPecas_X(e)) printf("O JOGADOR O GANHOU");
                    else if(numPecas_X(e)>numPecas_O(e)) printf("O JOGADOR X GANHOU!");
                    else printf("O JOGO EMPATOU");
                }
                break;
            }
            case 'L':{
                sscanf(linha,"%c %s", &c, s);
                e = ler(e,s);
                printa(e);
                printf("\n");
                break;
            }
            case 'E':{
                sscanf(linha,"%c %s", &c, s);
                escrever(e,s);
                printa(e);
                printf("\n");
                break;
            }
            case 'S':{
                posvalidas(e);
                break;
            }
            case 'H':{
                sugestao(e);
                break;
            }
            case 'U': {
                e = undo(e, &st);
                break;
            }
            case 'Q':
                exit(0);

            default: {
                printf("Comando Invalido \n");
                break;
            }
        }
    }
    while (toupper(linha[0]) != 'Q');
    return 0;
}
