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




    //inserção ordenada na coluna considerando o valor da linha    
    if(pontCol == NULL){
        matriz->coluna[col]= novoNo; 
    }else{
        ant = NULL; 

        while((pontCol->linha < lin) && (pontCol != NULL)){
            ant = pontCol; 
            pontCol = pontCol->baixo;
        }

        if(pontCol != NULL){
            if(pontCol->linha == lin){
                printf("Ja existe um elemento nessa linha "); 
            }else if(ant == NULL){// se for no inicio
                novoNo->baixo = matriz->coluna[col]; 
                matriz->coluna[col] = novoNo; 
            }else{// se for no meio
                novoNo->baixo = pontCol; 
                ant->baixo = novoNo; 
            }
        }else if(pontCol == NULL){// se for no final, pontcol é NULL, pois percorreu todas as linhas e saiu nulo do while
                ant->baixo = novoNo; 
            }

    }



    //inserção ordenada na linha considerando o valor da coluna 
    if(pontLinha == NULL){ // se nao tiver nenhum elemento na coluna apenas inserir na coluna
        matriz->linha[lin] = novoNo; 
    }else{
        ant = NULL; 

        while((pontLinha->coluna < col) && (pontLinha != NULL)){//pontLinha->coluna é a coluna do primeiro elemento dessa linha
            ant = pontLinha; 
            pontLinha = pontLinha->direita;     
        } 
       

        if(pontLinha != NULL){// se a linha nao for vazia
            if(pontLinha->coluna == col){
                printf("Ja existe um elemento nesta coluna! "); 
            }else if(ant == NULL){// se for no inicio  
                novoNo->direita = matriz->linha[lin]; 
                matriz->linha[lin] = novoNo;  
            }else{//se for no meio
                 
                novoNo->direita = pontLinha; 
                ant->direita = novoNo; 
            }

        }else if(pontLinha == NULL){// se for no final, pontlinha é nulo, pois percorreu todas as colunas e saiu nulo do while
                ant->direita = novoNo; 
            }   
    }   

}

void imprimirLinha(MatrizEsparsa *matriz, int lin){
    nodeMatriz *aux = matriz->linha[lin]; 

    for(int col = 0; col<qtdCol; col++){
        if(aux != NULL && col == aux->coluna){
            printf("%d ", aux->info);
            aux = aux->direita; 
        }else{
            printf("0 ");        
        }
    }
        printf("\n"); 
}

void imprimirCol(MatrizEsparsa *matriz, int col){
    nodeMatriz *aux = matriz->coluna[col]; 

    for(int linha = 0; linha<qtdLin; linha++){
        if(aux != NULL && linha == aux->linha){
            printf("%d ", aux->info); 
            aux = aux->baixo;
        }else{
            printf("0 "); 
        }
    printf("\n"); 
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    MatrizEsparsa matriz; 

    inicializaMatriz(&matriz); 
    inserir(&matriz, 1, 0, 4); 
    //inserir(&matriz, 3, 0, 5); 
    inserir(&matriz, 4, 0, 3); 
    inserir(&matriz, 5, 0, 0); 
    //inserir(&matriz, 5, 0, 1); 
    //inserir(&matriz, 6, 0, 7); 
    //inserir(&matriz, 2, 1, 4);
    imprimirLinha(&matriz, 0);
    //imprimirLinha(&matriz, 1);
    //imprimirCol(&matriz, 4); 


}
