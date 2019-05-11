
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
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador nivel 1 , 2 -> contra computador nivel 2 ,3 -> contra computador nivel 3

} ESTADO;


ESTADO jogar_geral (ESTADO e, int l, int c) ;
void printa(ESTADO);
ESTADO reset(ESTADO e,char linha[]);
ESTADO automatico (ESTADO e,char linha[]);
void posvalidas (ESTADO e);
void sugestao (ESTADO e);
ESTADO ler(ESTADO e, char s[]);
void escrever(ESTADO e, char s[]);



#endif //PROJ_ESTADO_H
