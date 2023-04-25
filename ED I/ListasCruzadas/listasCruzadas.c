#include<stdio.h>
#include<stdlib.h> 
#define qtdLin 10 
#define qtdCol 10 

struct no{
    int info; 
    int linha; 
    int coluna; 
    struct no *direita;
    struct no *baixo;
};
typedef struct no nodeMatriz; 

struct MatrizEsparsa{
    nodeMatriz *linha[qtdLin];  
    nodeMatriz *coluna[qtdCol];  
};
typedef struct MatrizEsparsa MatrizEsparsa; 

void inicializaMatriz(MatrizEsparsa *matriz){
    for(int i = 0; i < qtdLin; i++){
        matriz->linha[i] = NULL; 
    }
    for(int i = 0; i < qtdCol; i++){
        matriz->coluna[i] = NULL; 
    }
}

void inserir(MatrizEsparsa *matriz, int novoElemento, int lin, int col){
    nodeMatriz *novoNo = (nodeMatriz*)malloc(sizeof(nodeMatriz)); 
    nodeMatriz *pontCol, *pontLinha, *ant; 

    novoNo->info = novoElemento;
    novoNo->linha = lin; 
    novoNo->coluna = col; 
    novoNo->baixo = NULL; 
    novoNo->direita = NULL;
    pontLinha = matriz->linha[lin]; 
    pontCol = matriz->coluna[col]; 

    


}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
