#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H

ESTADO reset(ESTADO e,char linha[]);
ESTADO jogada(ESTADO e, char linha[]);
int valida (ESTADO e, int l, int c);
ESTADO jogar (ESTADO e, int l, int c);
ESTADO posvalidas (ESTADO e, int l, int c);
#endif //PROJ_AUXILIARES_H

