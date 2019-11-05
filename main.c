#include "TARVB.c"

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

int main(int argc, char *argv[]){
  TAB * arvore = inicializa();
  char letra;
  char from;
  int t;
  printf("Informe a ordem da árvore B: ");
  scanf("%d", &t);

  //ordem t deve ser entre 2 e 5
  if ((t > 6) || (t < 2)) {
    printf("Tente um valor entre 2 e 5: ");
    scanf("%d", &t);
  }

  printf("\n");

  while(letra != '#'){
    printf("------MENU------\n");
    printf("Digite uma letra para inserir na árvore\n");
    printf("Digite * para imprimir\n");
    printf("Digite - para remover\n");
    printf("Digite # para sair\n");
    printf("Digite $ para encriptar um texto\n");
    scanf(" %c", &letra);

    //se o usuário tentar inserir número
    if ((letra >= 48) && (letra <= 57)) {
      printf("Digite uma letra: ");
      scanf(" %c", &letra);
    }

    //retira
    if(letra == '-'){
      printf("Informe a letra que deseja remover: ");
      scanf(" %c", &from);
      arvore = retira(arvore, from, t);
      imprime(arvore, 0);
    }

    //Sai do programa
    else if(letra == '#'){
      printf("\n");
      imprime(arvore, 0);
      libera(arvore);
      return 0;
    }

    //imprime
    else if(letra == '*'){
      printf("\n");
      imprime(arvore, 0);
    }

    else if (letra == '$') {
      int j = contadorDeNivel(arvore, 'e');
      printf("Nível de E na arvore: %d", j);
    }
    
    //insere
    else arvore = insere(arvore, letra, t);
    printf("\n");
  }
}