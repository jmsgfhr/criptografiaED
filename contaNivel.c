#include <stdio.h>
#include <stdlib.h>
#include "TARVB.h"

int contadorDeNivelAux (TAB *a, char ch, int cont){
    int i = 0;
    while(i < a->nchaves && ch > a->chave[i]) i++; //verifica em qual ponteiro vai 'descer' a busca
    if(i < a->nchaves && ch == a->chave[i]) return cont; //se achou a letra, retorna o contador atual
    if(a->folha) return cont; //se já é folha, nao tem um proximo nivel
    return contadorDeNivelAux(a->filho[i], ch, cont + 1); //vai para o filho e conta o nível
}

int contadorDeNivel(TAB *a, char ch){
    if (!a) return 0;

    int contaNivel = 0;
    return contadorDeNivelAux(a, ch, contaNivel);
}
