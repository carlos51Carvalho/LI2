#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H

typedef struct stack {
    int sp;
    ESTADO estados[64];
}STACK;

int valida (ESTADO e, int l, int c);
int validaNorte (ESTADO e, int l, int c);
int validaSul (ESTADO e, int l, int c);
int validaOeste (ESTADO e, int l, int c);
int validaEste (ESTADO e, int l, int c);
int validaNoroeste (ESTADO e, int l, int c);
int validaNordeste (ESTADO e, int l, int c);
int validaSudoeste (ESTADO e, int l, int c);
int validaSudeste (ESTADO e, int l, int c);
void posvalidas (ESTADO e);
int numPecas_O (ESTADO e);
int numPecas_X (ESTADO e);
int nenhumaValida (ESTADO e);
int nenhumaVazia (ESTADO e);
int finaliza (ESTADO e);
void iniciarStack (ESTADO e,STACK *s);
void alterarStack (ESTADO e, STACK *s);
ESTADO undo (ESTADO e, STACK *s);
#endif //PROJ_AUXILIARES_H
