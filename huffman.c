#include "TARVB.c"
#include "contaNivel.c"

typedef struct huffman
{
    /* data */
    char letra;
    float frequencia;
}Huff;

typedef struct LHuffman
{
    Huff letraFreq;
    struct LHuffman *prox;
}ListHuff;



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
    FILE *fp;
    float freq;
    char letr;
    ListHuff *listLetra = NULL; //variavel inicial da lista
    //------------------ Le do arquivo binario ------------------
    fp=fopen("alfabetoFreq.bin","rb");
    while (!feof(fp)) // verifica se chegou ao fim do arquivo 
    {
        Huff x; //estrutura do no
        fread(&x,sizeof(x),1,fp); //le uma estrutura por vez
        ListHuff *aux = (ListHuff *) malloc(sizeof(ListHuff)); //alocando o no
        aux->prox = listLetra;
        aux->letraFreq = x;
        listLetra = aux;
    }
    while (listLetra!=NULL)
    {
        printf("%c %f\n",listLetra->letraFreq.letra, listLetra->letraFreq.frequencia);
        ListHuff *aux = listLetra;
        listLetra = listLetra->prox;
        free(aux);
    }
    
    
    fclose(fp);
}