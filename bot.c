
#include "bot.h"
#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"



/**
 * @brief , função do nosso primeiro bot, cuja estratégia é o mesmo jogar a primeira jogada válida que encontrar.
 * @param e , recebe o estado atual do jogo.
 * @return  , retornará o estado após o bot ter jogado.
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


/**
 * Função que memoriza as posiçoes validas possiveis
 * @param e recebe o estado atual do jogo.
 * @param p lista de todas as posiçoes onde o bot pode jogar
 */

void numposicoesval (ESTADO e, LISTA *p){
    p->sp=0;
    int i,j;
    for(i=0; i<8 ;i++) {
        for (j = 0; j < 8; j++) {
            if (valida(e, i+1, j+1)) {
                p->valores[p->sp].l = i + 1;
                p->valores[p->sp].c = j + 1;
                p->sp++;
            }
        }
    }
}



/**
 * Função que atribui valores as varias posiçoes do tabuleiro dde modo a que este possa ser avaliado pelo minmax.
 * @param e estado atual do jogo.
 * @return matriz de inteiros com as varias cotaçoes por posição.
 */

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
            else if (e.grelha[i][j] != VAZIA) p-= matriz[i][j];
    return p;


}


/**
 * Função que avalia a qualidade de cada jogada, fazendo uma especie dum esquema em piramide avaliando conforme a profundidade, tendo em conta a melhor jogada possivel a realizar
 * pelo jogador e assumindo que o adversário fará sempre a melhor para ele proprio.
 * @param e estado atual do jogo.
 * @param profundidade nivel a onde realizar o minmax em teste.
 * @param original primeiro nivel de profundidade inserido.
 * @param bot valor da peça do bot.
 * @param p lista de todas as posiçoes onde o bot pode jogar
 * @param final posiçao onde o bot vai jogar no fim:
 * @return
 */
int minimax (ESTADO e, int profundidade, int original, VALOR bot, LISTA *p, PAR *final){
    int i,eval;
    LISTA s;
    if (profundidade == 0){
        eval = tabuleiro(e);
        return eval;
    }
    if(e.peca==bot){
        int max = -100000;
        ESTADO tmp = e;
        for(i=0; i< p->sp ; i++){
            e = tmp;
            e = jogar(e, p->valores[i].l,p->valores[i].c);
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
        return max;
    }
    if(e.peca!=bot){
        int min = +100000;
        ESTADO tmp = e;
        for(i=0; i< p->sp ; i++){
            e = tmp;
            e = jogar(e,p->valores[i].l, p->valores[i].c);
            numposicoesval(e,&s);
            eval = minimax(e,profundidade-1,original,bot,&s,final);
            if(eval<min) {
                min = eval;
            }
        }
        return min;
    }
}

/**
 * Função que irá decidir a jogada que o bot irá fazer e realizá-la, escolherá preferencialmente os cantos ou se não for possível, a posicção que o permite comer mais peças do adversário.
 * @param e , estado atual do jogo
 * @return , estado com a jogada do bot realizada.
 */

ESTADO bot2 (ESTADO e) {
    int i,j,resx=0,resy=0;
    for(i=0; i<8 ; i++){
        for(j=0 ; j<8 ; j++){
            if (valida(e, 0, 0)){
                resx = 0;
                resy = 0;
            }
            else if (valida(e, 7, 7)){
                resx = 7;
                resy = 7;
            }
            else if (valida(e, 0, 7)){
                resx = 0;
                resy = 7;
            }
            else if (valida(e, 7, 0)){
                resx = 7;
                resy = 0;
            }
            else if(quantas(e,i,j) > quantas(e,resx,resy)) {
                resx=i;
                resy=j;
            }
        }
    }
    int r=0;
    for(i=0; i<8 ; i++) {
        for (j = 0; j < 8; j++) {
            if (i == resx && j == resy && r == 0) {
                e=jogar(e,i,j);
                r++;
            }
        }
    }
    return e;
}


/**
 * Função que vai decidir a jogada contra o utilizador de profundidade mais alta.
 * @param e estado atual do jogo
 * @return estado com a jogada do bot realizada.
 */

ESTADO bot3 (ESTADO e) {
    int l,c;
    VALOR h;
    LISTA s;
    PAR final;
    numposicoesval(e,&s);
    h = e.peca;
    minimax(e,7,7,h,&s,&final);
    e = jogar(e, (final).l,(final).c);
    return e;

}

