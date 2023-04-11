#include <stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

struct FilaEstatica{ 
    int vFila[MAX]; 
    int inicio; 
    int fim; 
}; 
typedef struct FilaEstatica Fila; 

inicializaFila(Fila *fila){
    fila->inicio = 0; 
    fila->fim = 0; 
}


bool verificaVazia(Fila *fila){
    if(fila->inicio == fila->fim){
        // printf("A fila esta vazia\n");
        return true; 
    }else{
        // printf("A fila nao esta vazia\n"); 
        return false; 
    }
}


bool verificaCheia(Fila *fila){
    
    if(fila->fim == MAX){
        //printf("Fila Cheia\n"); 
        return true;
    }else{
        //printf("A fila nao esta cheia\n"); 
        return false; 
    }

} 

void inserir(Fila *fila, int novoElemento){
    if(verificaCheia(fila)){
        printf("Fila Cheia\n");    
    }else{
        fila->vFila[fila->fim] = novoElemento; 
        fila->fim++; 
    }
}

void removeFila(Fila *fila){
    if(verificaVazia(fila)){
        printf("A fila esta vazia, nao ha elementos para remover\n");
    }else{
        fila->vFila[fila->inicio] = NULL; 
        fila->inicio++; 
    }
}

void imprimeFila(Fila *fila){
    int aux = fila->inicio; 

    while(aux != fila->fim){
        printf("%d ", fila->vFila[aux]); 
        aux++; 
    }

}

int main(int argc, char const *argv[])
{
    Fila fila; 
    
    inicializaFila(&fila); 
    //verificaVazia(&fila);  
    inserir(&fila, 3); 
    inserir(&fila, 4); 
    inserir(&fila, 5); 
    inserir(&fila, 6); 
    inserir(&fila, 7); 
    removeFila(&fila); 
    //inserir(&fila, 8); 
    imprimeFila(&fila); 
}
