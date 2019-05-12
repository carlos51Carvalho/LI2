#include "estado.h"

#ifndef PROJETO_BOT_H
#define PROJETO_BOT_H
typedef struct par {
    int l;
    int c;
}PAR;


typedef struct lista {
    int sp;
    PAR valores[64];
}LISTA;




ESTADO bot_1 (ESTADO e) ;
ESTADO bot2 (ESTADO e);
ESTADO bot3 (ESTADO e);
void numposicoesval (ESTADO e, LISTA *p);


#endif //PROJETO_BOT_H
