#include "bot.h"
#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"




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




void numposicoesval (ESTADO e, LISTA *p){
    (*p).sp=0;
    int i,j;
    for(i=0; i<8 ;i++) {
        for (j = 0; j < 8; j++) {
            if (valida(e, i, j)) {
                (*p).valores[(*p).sp].l = i + 1;
                (*p).valores[(*p).sp].c = j + 1;
                (*p).sp++;
            }
        }
    }
}

int tabuleiro(ESTADO e){
    int matriz[8][8] = {{100,-20,10,5,5,10,-20,100},
                      {-20,-50,-2,-2,-2,-2,-50,-20},
                      {10,-2,-1,-1,-1,-1,-2,10},
                      {5,-2,-1,-1,-1,-1,-2,5},
                      {5,-2,-1,-1,-1,-1,-2,5},
                      {10,-2,-1,-1,-1,-1,-2,10},
                      {-20,-50,-2,-2,-2,-2,-50,-20},
                      {100,-20,10,5,5,10,-20,100}};
    int p = 0;
    for(int i=0; i<8 ;i++)
        for (int j = 0; j < 8; j++)
            if (e.grelha[i][j] == e.peca) p+= matriz[i][j];
    return p;


}
int minimax (ESTADO e, int profundidade, int original, VALOR bot, LISTA *p, PAR *final){
    int i,eval;
    LISTA s;
    if (profundidade == 0){
        eval = tabuleiro(e);
    }
    if(e.peca==bot){
        int max = -100000;
        ESTADO tmp = e;
        for(i=0; i<(*p).sp ; (*p).sp++){
                 e = tmp;
                 e = jogar(e,(*p).valores[(*p).sp].l,(*p).valores[(*p).sp].c);
                 numposicoesval(e,&s);
                 eval = minimax(e,profundidade-1,original,bot,&s,final);
                 if(eval>max) {
                     max = eval;
                     if (profundidade == original) {
                         final->l = p->valores[i].l;
                         final->c = p->valores[i].c;
                     }
                 }
        }
    }
    if(e.peca!=bot){
        int min = +100000;
        ESTADO tmp = e;
        for(i=0; i<(*p).sp ; (*p).sp++){
            e = tmp;
            e = jogar(e,(*p).valores[(*p).sp].l, (*p).valores[(*p).sp].c);
            numposicoesval(e,&s);
            eval = minimax(e,profundidade-1,original,bot,&s,final);
            if(eval<min) {
                min = eval;
                final->l = p->valores[i].l;
                final->c = p->valores[i].c;
            }
        }
    }
    return eval;
}


ESTADO bot2 (ESTADO e) {
        int l,c;
        int max = 0, p = 0;
        for(l=0; l<8 ; l++){
            for(c=0; c<8; c++){
                if(valida(e,l,c)==1) {
                    p = minimax(jogar(e,l,c),)
                            if (p > max) max = p;

            }
        }
    }

}

