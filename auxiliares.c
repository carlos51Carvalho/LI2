#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"
#include "estado.h"


//AUXILIARES VALIDA E JOGAR

int validaNorte (ESTADO e, int l, int c){
    int r=0,i=l-1,j=c;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else if(e.grelha[i][j]==e.peca)r=0;
    else {
        if (l >= 2){
            while (i > 0 && e.grelha[i][j]==h){i--;}
            if (e.grelha[i][j]==e.peca) r=1;
            }
        }
    return r;
}
int validaSul (ESTADO e, int l, int c){
    int r=0,i=l+1,j=c;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else if(e.grelha[i][j]==e.peca)r=0;
    else {
        if(l <= 5){
            while (i < 7 && e.grelha[i][j]==h){i++;}
            if (e.grelha[i][j]==e.peca) r=1;
            }
        }
    return r;
}
int validaOeste (ESTADO e, int l, int c){
    int r=0,i=l,j=c-1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else if(e.grelha[i][j]==e.peca)r=0;
    else{
        if(c >= 2){
            while (j>0 && e.grelha[i][j]==h){j--;}
            if (e.grelha[i][j]==e.peca) r=1;}
        }
    return r;
}
int validaEste (ESTADO e, int l, int c){
    int r=0,i=l,j=c+1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else if(e.grelha[i][j]==e.peca)r=0;
    else{
        if(c <= 5){
            while (j<7 && e.grelha[i][j]==h){j++;}
            if (e.grelha[i][j]==e.peca) r=1;}
        }
    return r;
}
int validaNoroeste (ESTADO e, int l, int c){
    int r=0,i=l-1,j=c-1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else {
        if (l >= 2 && c >= 2) {
            if (e.grelha[i][j] == e.peca)r = 0;
            else {
                while (i > 0 && j > 0 && e.grelha[i][j] == h) { i--, j--; }
                if (e.grelha[i][j] == e.peca) r = 1;
            }
        }
    }
    return r;
}
int validaNordeste (ESTADO e, int l, int c){
    int r=0,i=l-1,j=c+1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else {
        if (l >= 2 && c <= 5) {
            if (e.grelha[i][j] == e.peca)r = 0;
            else {
                while (i > 0 && j < 7 && e.grelha[i][j] == h) { i--, j++; }
                if (e.grelha[i][j] == e.peca) r = 1;
            }
        }
    }
    return r;
}
int validaSudoeste (ESTADO e, int l, int c){
    int r=0,i=l+1,j=c-1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else {
        if (l <= 5 && c >= 2) {
            if (e.grelha[i][j] == e.peca)r = 0;
            else {
                while (i < 7 && j > 0 && e.grelha[i][j] == h) { i++, j--; }
                if (e.grelha[i][j] == e.peca) r = 1;
            }
        }
    }
    return r;
}
int validaSudeste (ESTADO e, int l, int c){
    int r=0,i=l+1,j=c+1;
    VALOR h;
    if (e.peca==VALOR_X) h=VALOR_O;
    else if(e.peca==VALOR_O) h=VALOR_X;
    else h=VAZIA;
    if(e.grelha[l][c]!=VAZIA) r=0;
    else {
        if (l < 6 && c < 6) {
            if (e.grelha[i][j] == e.peca)r = 0;
            else {
                while (i < 7 && j < 7 && e.grelha[i][j] == h) { i++, j++;}
                if (e.grelha[i][j] == e.peca) r = 1;
            }
        }
    }
    return r;
}

int valida (ESTADO e, int l, int c) {
    int r;
    if     (validaNorte(e,l,c)==1) r=1;
    else if(validaSul(e,l,c)==1)   r=1;
    else if(validaEste(e,l,c)==1)  r=1;
    else if(validaOeste(e,l,c)==1) r=1;
    else if(validaNoroeste(e,l,c)==1) r=1;
    else if(validaNordeste(e,l,c)==1) r=1;
    else if(validaSudoeste(e,l,c)==1) r=1;
    else if(validaSudeste(e,l,c)==1)  r=1;
    else r=0;
    return r;
}



//AUXILIARES PARA CONTAR NUMERO DE PEÇAS

int numPecas_O (ESTADO e) {
    int i,j,num=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (e.grelha[i][j]==VALOR_O) {
                num++;
            }
        }
    }
    return num;
}

int numPecas_X (ESTADO e) {
    int i,j,num=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (e.grelha[i][j]==VALOR_X) {
                num++;
            }
        }
    }
    return num;
}



//Auxiliares FINALIZAR O JOGO

int nenhumaValida (ESTADO e){
    int i,j,r=1;
    for (i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(valida(e,i,j)==1) r=0;
        }
    }
    return r;
}

int nenhumaVazia (ESTADO e){
    int i,j,r=1;
    for(i=0; i<8 ; i++){
        for(j=0; j<8; j++){
            if(e.grelha[i][i]==VALOR_X) r=0;
            else if(e.grelha[i][i]==VALOR_O) r=0;
        }
    }
    return r;
}

int finaliza (ESTADO e) {
    int r = 0;
    VALOR h;
    if (e.peca == VALOR_X) h = VALOR_O;
    else if(e.peca==VALOR_O) h = VALOR_X;
    else h=VAZIA;
    if (numPecas_O(e) == 0 || numPecas_X(e) == 0) r = 1;

    if (nenhumaValida(e)==1) {
        e.peca=h;
        if(nenhumaValida(e)==1) r=1;
    }

    if (nenhumaVazia(e)==1) r=1;
    return r;
}

void iniciarStack (ESTADO e,STACK *s) {
    s -> sp = 0;
    s -> estados[s->sp] = e;
}

void alterarStack (ESTADO e, STACK *s) {
    s->sp++;
    s->estados[s->sp] = e;
}

ESTADO undo (ESTADO e, STACK *s){
    if (s->sp != 0) {
        s->sp--;
        e = s->estados[s->sp];
        printf("\n");
        printa(e);
        printf("\n");
    }
    return e;
}

