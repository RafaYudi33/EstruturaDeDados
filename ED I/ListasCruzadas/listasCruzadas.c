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
    pontLinha = matriz->linha[lin]; // aponta para o primeiro elemento da linha que vai ocorrer a inserção
    pontCol = matriz->coluna[col]; // aponta para o primeiro elemento da coluna que vai ocorrer a inserção

    //inserção ordenada na linha considerando o valor da coluna 
    if(pontCol == NULL){ // se nao tiver nenhum elemento na coluna apenas inserir na coluna
        matriz->coluna[col] = novoNo; 
    }else{
        ant = NULL; 

        while((pontLinha->coluna < col) && (pontLinha != NULL)){//pontLinha->coluna é a coluna do primeiro elemento dessa linha
            ant = pontLinha; 
            pontLinha = pontLinha->direita;     
        } 

        if(pontLinha != NULL){// se a linha nao for vazia
            if(pontLinha->coluna == col){
                printf("Ja existe um elemento nesta coluna!"); 
            }else if(ant == NULL){// se for no inicio
                novoNo->direita = matriz->linha[lin]; 
                matriz->linha[lin]; 
            }else if((ant != NULL) && (pontLinha!=NULL)){//se for no meio
                novoNo->direita = ant->direita; 
                ant->direita = novoNo; 
            }else{// se for no final
                ant->direita = novoNo; 
            }   
        }
    }

    //inserção ordenada na coluna considerando o valor da linha    
    if(pontLinha == NULL){
        matriz->linha[lin] = novoNo; 
    }else{
        ant = NULL; 

        while((pontCol->linha < lin) && (pontCol != NULL)){
            ant = pontCol; 
            pontCol = pontCol->baixo;
        }

        if(pontCol != NULL){
            if(pontCol->linha == lin){
                printf("Ja existe um elemento nessa linha"); 
            }else if(ant = NULL){// se for no inicio
                novoNo->baixo = matriz->coluna[col]; 
                matriz->coluna[col] = novoNo; 
            }else if((ant != NULL)&&(pontCol != NULL)){// se for no meio
                novoNo->direita = ant->direita; 
                ant->direita = novoNo; 
            }else{// se for no final
                ant->direita = novoNo; 
            }
        }
    }

}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
