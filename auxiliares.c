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

int validaNorte (ESTADO e, int l, int c){
    int r,i=l-1,j=c;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else {
    while (i>=0 && e.grelha[i][j]==h){i--;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaSul (ESTADO e, int l, int c){
    int r,i=l+1,j=c;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;
    else {
    while (i<8 && e.grelha[i][j]==h){i++;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaOeste (ESTADO e, int l, int c){
    int r,i=l,j=c-1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;
    else{
    while (j>=0 && e.grelha[i][j]==h){j--;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaEste (ESTADO e, int l, int c){
    int r,i=l,j=c+1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;
    else{
    while (j<8 && e.grelha[i][j]==h){j++;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaNoroeste (ESTADO e, int l, int c){
    int r,i=l-1,j=c-1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;
    else{
    while (i>=0 && j>=0 && e.grelha[i][j]==h){i--,j--;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaNordeste (ESTADO e, int l, int c){
    int r,i=l-1,j=c+1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;
    else{
    while (i>=0 && j<8 && e.grelha[i][j]==h){i--,j++;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaSudoeste (ESTADO e, int l, int c){
    int r,i=l+1,j=c-1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;{
    while (i<8 && j>=0 && e.grelha[i][j]==h){i++,j--;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}
int validaSudeste (ESTADO e, int l, int c){
    int r,i=l+1,j=c+1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[i][j]!=VAZIA) r=0;
    else{
    while (i<8 && j<8 && e.grelha[i][j]==h){i++,j++;}
    if (e.grelha[i][j]==e.peca) r=1;
    else r=0;}
    return r;
}

int valida (ESTADO e, int l, int c) {
    int r;
    if     (validaNorte(e,l,c)==1) r=1;
    else if(validaSul(e,l,c)==1) r=1;
    else if(validaEste(e,l,c)==1) r=1;
    else if(validaOeste(e,l,c)==1) r=1;
    else if(validaNoroeste(e,l,c)==1) r=1;
    else if(validaNordeste(e,l,c)==1) r=1;
    else if(validaSudoeste(e,l,c)==1) r=1;
    else if(validaSudeste(e,l,c)==1) r=1;
    else r=0;
    return r;
}

ESTADO jogar (ESTADO e, int l, int c) {
    int i, j;
    VALOR h;
    if (e.peca == VALOR_X) h = VALOR_O;
    else if(e.peca==VALOR_O) h = VALOR_X;
    else h=VAZIA;
    if (valida(e, l, c) == 1) {
        if (validaNorte(e, l, c)) {
            i = l - 1;
            j = c;
            for (i >= 0 && e.grelha[i][j] == h; i--;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaSul(e, l, c)==1) {
            i = l + 1;
            j = c;
            for (i < 8 && e.grelha[i][j] == h; i++;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaOeste(e, l, c)==1) {
            i = l;
            j = c - 1;
            for (j >= 0 && e.grelha[i][j] == h; j--;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaEste(e, l, c)==1) {
            i = l;
            j = c + 1;
            for (j < 8 && e.grelha[i][j] == h; j++;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaNoroeste(e, l, c)==1) {
            i = l - 1;
            j = c - 1;
            for (i >= 0 && j >= 0 && e.grelha[i][j] == h; i--, j--;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaNordeste(e, l, c)==1) {
            i = l - 1;
            j = c + 1;
            for (i >= 0 && j < 8 && e.grelha[i][j] == h; i--, j++;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaSudoeste(e, l, c)==1) {
            i = l + 1;
            j = c - 1;
            for (i < 8 && j >= 0 && e.grelha[i][j] == h; i++, j--;) {
                e.grelha[i][j] = e.peca;
            }
        } else if (validaSudeste(e, l, c)==1){
            i = l + 1;
            j = c + 1;
            for (i >= 0 && j >= 0 && e.grelha[i][j] == h; i++, j++;) {
                e.grelha[i][j] = e.peca;
            }
        }
    } else printf("JOGADA INVALIDA!");
    return e;
}

ESTADO posvalidas (ESTADO e, int l, int c) {
    for(l=0; l<8 ; l++){
        for(c=0; c<8; c++){
            if(valida(e,l,c)==1) {e.grelha[l][c]='.';}
        }
    }
    return e;
}

ESTADO jogada (ESTADO e, char linha[]){
    int i,j,l,c;
    sscanf(linha, "%d %d", &l,&c);

    //if (valida(e,l-1,c-1) == 1){
        if (e.peca==VALOR_O){
            e.grelha[l-1][c-1]=VALOR_O;
        }else {
            e.grelha[l-1][c-1]=VALOR_X;
        }
    //}else printf("A jogada não é valida");


   //jogar(e,l-1,c-1);

    //printf("%d \n", valida(e, l-1,c-1));

    return e;
}
