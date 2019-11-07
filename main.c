#include "TARVB.c"
#include "contaNivel.c"

int main(int argc, char *argv[]){
  TAB * a = inicializa();
  
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

  a = criaAlfabeto("alfabetoCompleto.txt", t);

  printf("\n");

  while(letra != '#'){
    printf("------MENU------\n");
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
      a = retira(a, from, t);
      imprime(a, 0);
    }

    //Sai do programa
    else if(letra == '#'){
      printf("\n");
      imprime(a, 0);
      libera(a);
      return 0;
    }

    //imprime
    else if(letra == '*'){
      printf("\n");
      imprime(a, 0);
    }

    else if (letra == '$') {
      int j = contadorDeNivel(a, 'e');
      printf("Nível de E na arvore: %d", j);
    }
    
    printf("\n");
  }
}