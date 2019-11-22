#include "TARVB.c"
#include "contaNivel.c"

typedef struct huffman{
    /* data */
    char letra;
    float frequencia;
}Huff;

typedef struct LHuffman{
    Huff letraFreq;
    struct LHuffman *prox, *ant;
}ListHuff;

ListHuff *criaLista(){
    return ((ListHuff *) malloc(sizeof(ListHuff))); //alocando o no
}

ListHuff *rebobina(ListHuff *aux){ // funcao para voltar toda a lista
    if (aux->ant != NULL)
    {
        rebobina(aux->ant);
    }
    return aux;
}

ListHuff *insereHuffList(ListHuff *aux, ListHuff *listLetra){
   if(listLetra == NULL){ // cria primeiro elemento da lista
	listLetra = aux;
	listLetra->prox = NULL;
	listLetra->ant = NULL;
	return listLetra = rebobina(listLetra); // retorna a lista ja rebobinada
   }
   else if (listLetra->letraFreq.frequencia < aux->letraFreq.frequencia){
       if (listLetra->prox != NULL){
           insereHuffList(aux, listLetra->prox); // caso o elemento atual da lista seja menor e houver um proximo, a funcao e chamada novamente com um item a frente
       }
       else{ // caso menor e nao haja um proximo ele e adicionado
           listLetra->prox = aux;
           aux->ant = listLetra;
           aux->prox = NULL;
           listLetra = aux;
       }
   }
   else if (listLetra->letraFreq.frequencia > aux->letraFreq.frequencia){ // insercao caso elemento atual seja maior
       if (listLetra->ant == NULL) // caso nao tenha um elemento anterior ele e adicionado 
       {
           aux->prox = listLetra;
           aux->ant = NULL;
           listLetra->ant = aux;
           listLetra = aux;
       }
       else{ // se houver anterior significa que precisa ser adicionado no meio de dois elementos
           aux->prox = listLetra;
           aux->ant = listLetra->ant;
           listLetra->ant->prox = aux;
           listLetra->ant = aux;
           listLetra = aux;
       }
   }
   return listLetra = rebobina(listLetra);
}

ListHuff *huffmanInit(ListHuff *listLetra){
    FILE *fp;
    float freq;
    char letr;
    fp=fopen("alfabetoFreq.bin","rb");
    while (!feof(fp)){ // verifica se chegou ao fim do arquivo
        Huff x; //estrutura do no
        fread(&x,sizeof(x),1,fp); //le uma estrutura por vez
        ListHuff *aux = criaLista(); // aloca um espaco de memoria para o elemento
        aux->letraFreq = x; // diz que o elemento alocado tem valor X
        listLetra = insereHuffList(aux,listLetra); // insercao em ordem crescente
    }
    fclose(fp);
    
    return listLetra = rebobina(listLetra);
}

int main(int argc, char *argv[]){
    /*
    ------------------ Faz escrita e leitura e salva em arquivo binario ------------------
    FILE *fp;
    float freq;
    char letr;
    Huff x;

    //------------------ Escreve no arquivo binario ------------------
    fp=fopen("alfabetoFreq.bin","wb"); //abre arquivo
    scanf("%c %f\n",&letr,&freq);
    while (freq>=0)
    {
        fflush(stdin); //limpa buffer do teclado
        if(freq>=0){
            x.letra = letr;
            x.frequencia = freq;
            printf("letra: %c  Freq: %f\n",x.letra,x.frequencia); //teste de leitura
            fwrite(&x,sizeof(x),1,fp); // escreve estrutura em arquivo
        }
        scanf("%c %f\n",&letr,&freq);
    }
    
    //------------------ Le do arquivo binario ------------------
    fp=fopen("alfabetoFreq.bin","rb");
    while (!feof(fp)) // verifica se chegou ao fim do arquivo 
    {
        fread(&x,sizeof(x),1,fp); //le uma estrutura por vez
        printf("%c %f\n",x.letra,x.frequencia);
    }
    
    fclose(fp);
    */


    //------------------ Cria uma lista encadeada (desnecessaria) para ordenar e comprimir a arvore ------------------
    ListHuff *listLetra = huffmanInit(listLetra); //variavel inicial da lista
    //------------------ Le do arquivo binario ------------------
    
    while (listLetra!=NULL){
        printf("%c %f\n",listLetra->letraFreq.letra, listLetra->letraFreq.frequencia);
        ListHuff *aux = listLetra;
        listLetra = listLetra->prox;
        free(aux);
    }
}
