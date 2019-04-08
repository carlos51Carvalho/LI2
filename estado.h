#ifndef PROJ_ESTADO_H
#define PROJ_ESTADO_H



/**
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/**
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
} ESTADO;


ESTADO joga (ESTADO e);

void printa(ESTADO);

//ESTADO jogada (ESTADO e, char linha[])

ESTADO reset(ESTADO e,char linha[]);
ESTADO jogada(ESTADO e, char linha[]);
ESTADO ler(ESTADO e, char s[]);
ESTADO escrever(ESTADO e, char s[]);

//ESTADO joga (ESTADO, int x, int y)


#endif //PROJ_ESTADO_H
