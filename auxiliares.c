#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <ctype.h>
#include "auxiliares.h"
#include "estado.h"


//AUXILIARES VALIDA E JOGAR
/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Norte.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a cima esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Norte.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Norte e 0 se for inválida nessa direção.
 */
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

/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Sul.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a baixo esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Sul.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Sul e 0 se for inválida nessa direção.
 */
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
/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Oeste.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a Oeste esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Oeste.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Oeste e 0 se for inválida nessa direção.
 */
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
/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Este.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a Este esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Este.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Este e 0 se for inválida nessa direção.
 */
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
/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Noroeste.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a Noroeste esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Noroeste.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Noroeste e 0 se for inválida nessa direção.
 */
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
/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Nordeste.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a Nordeste esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Nordeste.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Nordeste e 0 se for inválida nessa direção.
 */
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
/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Sudoeste.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a Sudoeste esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Sudoeste.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Sudoeste e 0 se for inválida nessa direção.
 */
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

/**
 * @brief , esta função irá nos indicar se a jogada é ou não válida na direçáo Sudeste.
 * Caso a posição onde queremos jogar já esteja ocupada, a mesma será inválida.
 * Caso a posição imediatamente a Sudeste esteja ocupada por uma peça igual á e.peca, a jogada será inválida.
 * Caso contrário, iremos percorrer a matriz através do vetor na direção Sudeste.
 * Caso seja encontrado o fim da matriz a jogada é inválida.
 * Se antes do fim da matriz encontrarmos uma posição ocupada por e.peca, a jogada será válida.
 * @param e, a função recebe o estado atual do jogo.
 * @param l, recebe a linha da posição a testar.
 * @param c, recebe a coluna da posição a testar.
 * @return , retornará 1 se a jogada for válida na direção Sudeste e 0 se for inválida nessa direção.
 */
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

/**
 * @brief , a função irá através das funções anteriores verificar se a posição é válida para alguma das possíveis direções.
 * @param e , a função recebe o estado atual do jogo.
 * @param l , recebe a linha da posição a testar.
 * @param c , recebe a coluna da posição a testar.
 * @return , a função retornará 1 se a posição for válida e 0 caso contrário.
 */
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
/**
 * @brief , a função irá percorrer a matriz toda através de dois ciclos e contará o número de peças O.
 * @param e , a função recebe o estado atual do jogo.
 * @return , retornará o número de peças O em jogo.
 */
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

/**
 * @brief , a função irá percorrer a matriz toda através de dois ciclos e contará o número de peças X.
 * @param e , a função recebe o estado atual do jogo.
 * @return , retornará o número de peças X em jogo.
 */
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


/**
 * @brief, a função irá percorrer a matriz toda através de dois ciclos for para verificar se ainda existem jogadas válidas.
 * @param e , recebe o estado atual do jogo.
 * @return , retornará 0 se ainda existir pelo menos uma jogada válida, e retornará 1 caso contrário.
 */
int nenhumaValida (ESTADO e){
    int i,j,r=1;
    for (i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(valida(e,i,j)==1) r=0;
        }
    }
    return r;
}

/**
 * @brief , a função irá jogar na posição dada, se ela fôr válida.
 * Se a jogada fôr inválida , a função retornará o mesmo estado.
 * Caso contrário, a função irá alterar as peças adversárias para peças e.peca nas direções em que fôr válida.
 * @param e , recebe o estado atual do jogo.
 * @param l , recebe a linha da posição onde se pretende jogar.
 * @param c , recebe a coluna da posição onde se pretende jogar.
 * @return , retornará o estado que resulta dessa jogada efetuada.
 */
ESTADO jogar (ESTADO e, int l, int c) {
    int i, j;
    VALOR h;
    if (e.peca == VALOR_X) h = VALOR_O;
    else if (e.peca == VALOR_O) h = VALOR_X;
    else h = VAZIA;
    if (valida(e, l, c) == 0) {
        printf("Jogada Invalida.Tente outra jogada.");
        return e;
    }
    else {
        if (validaNorte(e, l, c)) {
            i = l - 1;
            j = c;
            for (; e.grelha[i][j] == h; i--) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaSul(e, l, c)) {
            i = l + 1;
            j = c;
            for (; e.grelha[i][j] == h; i++) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaOeste(e, l, c)) {
            i = l;
            j = c - 1;
            for (; e.grelha[i][j] == h; j--) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaEste(e, l, c)) {
            i = l;
            j = c + 1;
            for (; e.grelha[i][j] == h; j++) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaNoroeste(e, l, c)) {
            i = l - 1;
            j = c - 1;
            for (; e.grelha[i][j] == h; i--, j--) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaNordeste(e, l, c)) {
            i = l - 1;
            j = c + 1;
            for (; e.grelha[i][j] == h; i--, j++) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaSudoeste(e, l, c)) {
            i = l + 1;
            j = c - 1;
            for (; e.grelha[i][j] == h; i++, j--) {
                e.grelha[i][j] = e.peca;
            }
        }
        if (validaSudeste(e, l, c)) {
            i = l + 1;
            j = c + 1;
            for (; e.grelha[i][j] == h; i++, j++) {
                e.grelha[i][j] = e.peca;
            }
        }
        e.grelha[l][c] = e.peca;
        if (e.peca == VALOR_X) e.peca = VALOR_O;
        else e.peca = VALOR_X;
    }
    if (nenhumaValida(e)==1) {
        if (e.peca == VALOR_X) e.peca = VALOR_O;
        else e.peca = VALOR_X;
    }
    if (finaliza(e) == 1) {
        printa(e);
        if (numPecas_O(e) > numPecas_X(e)) printf("O JOGADOR O GANHOU\n\n");
        else if (numPecas_X(e) > numPecas_O(e)) printf("O JOGADOR X GANHOU!\n\n");
        else printf("O JOGO EMPATOU\n\n");
        exit(0);
    }
    return e;
}

/**
 * @brief , a função percorrerá a matriz toda através de dois ciclos for , para procurar peças Vazias.
 * @param e , recebe o estado atual do jogo.
 * @return  , retornará 1 caso já não hajam posições Vazias em campo, 0 caso contrário.
 */
int nenhumaVazia (ESTADO e){
    int i,j,r=1;
    for(i=0; i<8 ; i++){
        for(j=0; j<8; j++){
            if(e.grelha[i][j]==VAZIA) r=0;
        }
    }
    return r;
}

/**
 * @brief, a função irá testar se o jogo já está finalizado,
 * Primeiro, verificará se algum dos dois jogadores não tem peças em campo.
 * Segundo, verificará se algum dos jogadores tem jogadas válidas.
 * Terceiro irá testar se todas as peças em campo já estão ocupadas.
 * Caso alguma destas condições se verifique, o jogo está finalizado.
 * @param e , recebe o estado atual do jogo.
 * @return  , retornará 1 caso seja para finalizar o jogo, 0 caso ainda não esteja finalizado.
 */
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
/**
 * @brief , função que irá inicializar a stack, onde o primeiro estado de jogo a ser guardado é o ESTADO e, atual.
 * @param e , o estado atual do jogo.
 * @param s , recebe uma stack onde irá guardar os estados do jogo.
 */
void iniciarStack (ESTADO e,STACK *s) {
    s -> sp = 0;
    s -> estados[s->sp] = e;
}

/**
 * @brief , função que irá alterar a stack conforme o jogo avance, incrementando o stackpointer e guardando o estado nessa posição do array.
 * @param e , recebe o estado atual do jogo.
 * @param s , recebe a stack onde serão guardados os estados do jogo.
 */
void alterarStack (ESTADO e, STACK *s) {
    s->sp++;
    s->estados[s->sp] = e;
}

/**
 * @brief , função que irá devolver o estado anterior do jogo.
 * Para isso decrementamos o sp , e vamos a essa posição do array buscar o estado a devolver.
 * @param e , recebe o estado atual do jogo.
 * @param s , recebe a stack onde se encontram os estados de jogo.
 * @return  , retornará o estado anterior ao estado atual.
 */
ESTADO undo (ESTADO e, STACK *s){
    if (s -> sp != 0) {
        s->sp--;
        e = s->estados[s->sp];
        printf("\n");
        printa(e);
        printf("\n");
    }
    return e;
}

/**
 * @brief , esta função tem como objetivo encontrar o número de peças que o jogador ao jogar na posição dada consegue comer.
 * Para tal verificamos a validade da jogada para cada uma das direções e ao longo do vetor de cada direção conta quantas peças come, através da criação de uma variável que será sucessivamente incrementada.
 * @param e , recebe o estado atual do jogo.
 * @param i , recebe uma coordenada de linha.
 * @param j , recebe uma coordenada de coluna.
 * @return , retorna o número de peças que o player consegue comer ao jogar nessa posição.
 */
int quantas (ESTADO e, int i, int j) {
    int temp=0;
    int l,c;
    VALOR h;
    if (e.peca == VALOR_X) h = VALOR_O;
    else if (e.peca == VALOR_O) h = VALOR_X;
    else h = VAZIA;
    if (validaNorte(e, i, j)) {
        l = i-1;
        for (; e.grelha[l][j] == h; l--) {
            temp++;
        }
    }
    if (validaSul(e, i, j)) {
        l = i+1;
        for (; e.grelha[l][j] == h; l++) {
            temp++;
        }
    }
    if (validaOeste(e, i, j)) {
        c = j-1;
        for (; e.grelha[i][c] == h; c--) {
            temp++;
        }
    }
    if (validaEste(e, i, j)) {
        c = j+1;
        for (; e.grelha[i][c] == h; c++) {
            temp++;
        }
    }
    if (validaSudeste(e, i, j)) {
        l = i+1;
        c = j+1;
        for (; e.grelha[l][c] == h; l++,c++) {
            temp++;
        }
    }
    if (validaSudoeste(e, i, j)) {
        l = i+1;
        c = i-1;
        for (; e.grelha[l][c] == h; l++,c--) {
            temp++;
        }
    }
    if (validaNordeste(e, i, j)) {
        l = i-1;
        c = j+1;
        for (; e.grelha[l][c] == h; l--,c++) {
            temp++;
        }
    }
    if (validaNoroeste(e, i, j)) {
        l = i-1;
        c = j-1;
        for (; e.grelha[l][c] == h; l--,c--) {
            temp++;
        }
    }
    return temp;
}

