#include <stdio.h>
#include <stdlib.h>

const int t = 2;

typedef struct ArvB{
  int nchaves, folha;
  char *chave;
  struct ArvB **filho;
}TAB;

TAB *inicializa();
//Cria um nó na arvore B (sempre folha e com ponteiros de filho == NULL)
TAB *cria(int t);
//Imprime a arvore B
void imprime(TAB *a, int andar);
//Libera a arvore B
TAB *libera(TAB *a);
//Busca nó que contém/deveria conter a chave X
TAB *busca(TAB* x, int ch);
//Insere chave k na arvore de ordem t
TAB *insere(TAB *a, char k, int t);
TAB* remover(TAB* arv, int ch, int t);
TAB* retira(TAB* arv, int k, int t);