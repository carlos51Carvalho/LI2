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
    for (i = 0; toupper(linha[i])!='J' && linha[i]!= ' '; i++) {
        l = linha[i]-48;
        c = linha[i+2]-48;
    }
    if (e.peca==VALOR_O){
        e.grelha[l-1][c-1]=VALOR_O;
    }else {
        e.grelha[l-1][c-1]=VALOR_X;
    }
    printf("\n");
    printa(e);
    printf("\n");
    return e;
    }



int valida (ESTADO e, int l, int c) {
    int r=0;
    int i=l, j=c;
    while (i>=0 && e.grelha[i][j]==inv[e.peca]){i--;} //NORTE
        if (e.grelha[i][j]==e.peca) r=1;
        else {
            i = l;
            while (i < 8 && e.grelha[i][j] == inv[e.peca]) { i++; } //SUL
            if (e.grelha[i][j] == e.peca) r = 1;
            else {
                i = l;
                while (j >= 0 && e.grelha[i][j] == inv[e.peca]) { j--; } //OESTE
                if (e.grelha[i][j] == e.peca) r = 1;
                else {
                    j = c;
                    while (j < 8 && e.grelha[i][j] == inv[e.peca]) { j++; } //ESTE
                    if (e.grelha[i][j] == e.peca) r = 1;
                    else {
                        j = c;
                        while (i >= 0 && j >= 0 && e.grelha[i][j] == inv[e.peca]) {
                            i--;
                            j--;
                        } //NOROESTE
                        if (e.grelha[i][j] == e.peca) r = 1;
                        else {
                            i = l;
                            j = c;
                            while (i >= 0 && j < 8 && e.grelha[i][j] == inv[e.peca]) {
                                i--;
                                j++;
                            } //NORDESTE
                            if (e.grelha[i][j] == e.peca) r = 1;
                            else {
                                j = c;
                                while (i < 8 && j >= 0 && e.grelha[i][j] == inv[e.peca]) {
                                    i++;
                                    j--;
                                } //SUDOESTE
                                if (e.grelha[i][j] == e.peca) r = 1;
                                else {
                                    j = c;
                                    while (i < 8 && j < 8 && e.grelha[i][j] == inv[e.peca]) {
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
