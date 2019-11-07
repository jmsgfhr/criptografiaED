#include <stdio.h>
#include <stdlib.h>

#ifndef TARV_H  //Header Guard: evita que o compilador interprete 2 importações de Tarv.h como cópias. 
#define TARV_H

typedef struct ArvB{
  int nchaves, folha;
  int vogal, maiuscula;
  char *chave;
  struct ArvB **filho;
} TAB;

TAB *inicializa();
TAB *cria(int t);
void imprime(TAB *a, int andar);
TAB *libera(TAB *a);
TAB *busca(TAB* x, int ch);
TAB *insere(TAB *a, char k, int t);
TAB* remover(TAB* arv, char ch, int t);
TAB* insereAlfabeto(TAB* a, int t);
TAB* criaAlfabeto(char *nome_arquivo, int t);

#endif