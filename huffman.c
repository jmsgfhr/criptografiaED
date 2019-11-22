#include "TARVB.c"
#include "contaNivel.c"

//------------------ Estruturas ------------------

typedef struct huffman{ // estrutura com letra e frequencia
    char letra;
    float frequencia;
}Huff;

typedef struct noArv{ // estrutura arvore
    Huff conteudoArvore;
    float frequenciaArv;
    struct noArv *esquerda, *direita;
}ArvHuff;

typedef struct lHuffman{ // estrutura da fila
    ArvHuff *noArvList;
    struct lHuffman *prox, *ant;
}ListHuff;


//------------------ Funcoes ------------------


ListHuff *criaLista(){
    return ((ListHuff *) malloc(sizeof(ListHuff))); //alocando o no
}

ArvHuff *criaArvore(){
    return ((ArvHuff *) malloc(sizeof(ArvHuff)));
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
   else if (listLetra->noArvList->conteudoArvore.frequencia < aux->noArvList->conteudoArvore.frequencia){
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
   else if (listLetra->noArvList->conteudoArvore.frequencia > aux->noArvList->conteudoArvore.frequencia){ // insercao caso elemento atual seja maior
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

void emOrdem(ArvHuff *pNo) {
     if(pNo != NULL) {
         emOrdem(pNo->esquerda);
         if(pNo->esquerda == NULL && pNo->direita == NULL)
            printf("%c %f\n",pNo->conteudoArvore.letra, pNo->conteudoArvore.frequencia);
         emOrdem(pNo->direita);
     }
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
        ArvHuff *NoArvList = criaArvore();
        NoArvList->conteudoArvore = x;
        aux->noArvList = NoArvList;
        aux->noArvList->frequenciaArv = x.frequencia; // diz que o elemento alocado tem valor X
        listLetra = insereHuffList(aux,listLetra); // insercao em ordem crescente
    }
    fclose(fp);
    
    return listLetra = rebobina(listLetra);
}

ArvHuff *huffTreeInit(ListHuff *listLetra){ // ainda em desenvolvimento nao tentar entender =)
    if (listLetra->prox != NULL)
    {
        ArvHuff *pai;
        ListHuff *aux = criaLista();
        pai->esquerda = listLetra->noArvList;
        pai->direita = listLetra->prox->noArvList;
        pai->frequenciaArv = pai->esquerda->frequenciaArv + pai->direita->frequenciaArv;
        listLetra = listLetra->prox->prox;
        free(listLetra->ant->ant);
        free(listLetra->ant);
        listLetra->ant = NULL;
        aux->noArvList = pai;
        listLetra = insereHuffList(aux,listLetra);
        
        return pai;
    }
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

    ListHuff *listLetra = huffmanInit(listLetra); // inicia a lista

    //------------------ Criar a arvore comprimida ------------------

    ArvHuff *huffmanTree = huffTreeInit(listLetra);


    emOrdem(huffmanTree);
}
