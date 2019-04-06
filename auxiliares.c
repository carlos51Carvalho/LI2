#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"
#include "estado.h"

ESTADO reset (ESTADO e,char linha[]) {
    int i, j;
    for (i = 0; linha[i] != toupper('x') && linha[i] != toupper('o'); i++) {
        if (toupper(linha[i]) == 'X') e.peca = VALOR_X;
        else if (toupper(linha[i]) == 'O') e.peca = VALOR_O;
        else e.peca = VAZIA;
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            e.grelha[i][j] = VAZIA;
        }
    }

            e.grelha[3][4] = VALOR_X;
            e.grelha[4][3] = VALOR_X;
            e.grelha[3][3] = VALOR_O;
            e.grelha[4][4] = VALOR_O;
            printf("\n");
            printa(e);
            printf("\n");
            return e;
}

ESTADO jogada (ESTADO e, char linha[]){
    int i,j,l,c;
    sscanf(linha, "%d %d", &l,&c);

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            e.grelha[i][j] = VAZIA;
        }
    }

    if (e.peca==VALOR_O){
        e.grelha[l-1][c-1]=VALOR_O;
    }else {
        e.grelha[l-1][c-1]=VALOR_X;
    }

    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    printf("\n");
    printa(e);
    printf("\n");
    return e;
}

int valida (ESTADO e, int l, int c) {
    int r=0;
    int i=l, j=c;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else h=VALOR_X;
     while (i>=0 && e.grelha[i][j]==h){i--;} //NORTE
        if (e.grelha[i][j]==e.peca) r=1;
        else {
            i = l;
            while (i < 8 && e.grelha[i][j] == h) { i++; } //SUL
            if (e.grelha[i][j] == e.peca) r = 1;
            else {
                i = l;
                while (j >= 0 && e.grelha[i][j] == h) { j--; } //OESTE
                if (e.grelha[i][j] == e.peca) r = 1;
                else {
                    j = c;
                    while (j < 8 && e.grelha[i][j] == h) { j++; } //ESTE
                    if (e.grelha[i][j] == e.peca) r = 1;
                    else {
                        j = c;
                        while (i >= 0 && j >= 0 && e.grelha[i][j] == h) {
                            i--;
                            j--;
                        } //NOROESTE
                        if (e.grelha[i][j] == e.peca) r = 1;
                        else {
                            i = l;
                            j = c;
                            while (i >= 0 && j < 8 && e.grelha[i][j] == h) {
                                i--;
                                j++;
                            } //NORDESTE
                            if (e.grelha[i][j] == e.peca) r = 1;
                            else {
                                j = c;
                                while (i < 8 && j >= 0 && e.grelha[i][j] == h) {
                                    i++;
                                    j--;
                                } //SUDOESTE
                                if (e.grelha[i][j] == e.peca) r = 1;
                                else {
                                    j = c;
                                    while (i < 8 && j < 8 && e.grelha[i][j] == h) {
                                        i++;
                                        j++;
                                    } //SUDESTE
                                    if (e.grelha[i][j] == e.peca) r = 1;
                                    else {r=0;}
                                }
                            }
                        }

                    }
                }
            }
        }
    return r;
}

ESTADO jogar (ESTADO e, int l, int c) {
    int i, j;
    VALOR h;
    if (e.peca == VALOR_X) h = VALOR_O;
    else h = VALOR_X;
    if (valida(e, l, c) == 1) {
        for (i = l && j = c; i >= 0 && e.grelha[i][j] == h; i--) {
            if (e.grelha[i][j] == e.peca) {
                for (i = l && j = c; i >= 0 && e.grelha[i][j] == h; i--) {
                    e.grelha[i][j] = e.peca;
                }
            } else {
                for (i = l && j = c; i < 8 && e.grelha[i][j] == h; i++) {
                    if (e.grelha[i][j] == e.peca) {
                        for (i = l && j = l; i < 8 && e.grelha[i][j] == h; i++) {
                            e.grelha[i][j] = e.peca;
                        }
                    } else {
                        for (i = l && j = c; j >= 0 && e.grelha[i][j] == h; j--) {
                            if (e.grelha[i][j] == e.peca) {
                                for (i = l && j = c; j >= 0 && e.grelha[i][j] == h; j--) {
                                    e.grelha[i][j] = e.peca;
                                }
                            } else {
                                for (i = l && j = c; j < 8 && e.grelha[i][j] == h; j++) {
                                    if (e.grelha[i][j] == e.peca) {
                                        for (i = l && j = c; j < 8 && e.grelha[i][j] == h; j++) {
                                            e.grelha[i][j] = e.peca;
                                        }
                                    } else {
                                        for (i = l && j = c; i >= 0 && j >= 0 && e.grelha[i][j] == h; i--, j--) {
                                            if (e.grelha[i][j] == e.peca) {
                                                for (i = l && j = c;
                                                     i >= 0 && j >= 0 && e.grelha[i][j] == h; i--, j--) {
                                                    e.grelha[i][j] = e.peca;
                                                }
                                            } else {
                                                for (i = l && j = c;
                                                     i >= 0 && j < 8 && e.grelha[i][j] == h; i--, j++) {
                                                    if (e.grelha[i][j] == e.peca) {
                                                        for (i = l && j = c;
                                                             i >= 0 && j < 8 && e.grelha[i][j] == h; i--, j++) {
                                                            e.grelha[i][j] = e.peca;
                                                        }
                                                    } else {
                                                        for (i = l && j = c;
                                                             i < 8 && j >= 0 && e.grelha[i][j] == h; i++, j--) {
                                                            if (e.grelha[i][j] == e.peca) {
                                                                for (i = l && j = c;
                                                                     i < 8 && j >= 0 &&
                                                                     e.grelha[i][j] == h; i++, j--) {
                                                                    e.grelha[i][j] = e.peca;
                                                                }
                                                            } else {
                                                                for (i = l && j = c;
                                                                     i < 8 && j < 8 &&
                                                                     e.grelha[i][j] == h; i++, j++) {
                                                                    if (e.grelha[i][j] == e.peca) {
                                                                        for (i = l && j = c; i >= 0 && j >= 0 &&
                                                                                             e.grelha[i][j] ==
                                                                                             h; i++, j++) {
                                                                            e.grelha[i][j] = e.peca;
                                                                        }
                                                                    }

                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else printf("JOGADA INVALIDA!");
}
