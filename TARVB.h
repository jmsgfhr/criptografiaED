#include <stdio.h>
#include <stdlib.h>

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
TAB* retira(TAB* arv, int k, int t);