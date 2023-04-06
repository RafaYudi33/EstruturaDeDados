#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no{
 int elemento; 
 struct no *prox; 
};
typedef struct no nodePilha; 

struct Pilha{
    struct no *topo; 
};
typedef struct Pilha Pilha; 


void inicializaPilha(Pilha *pilha){
    pilha->topo = NULL; 
}

bool verificaVazia(Pilha *pilha){
    if(pilha->topo == NULL){
        printf("A pilha esta vazia");  
        return true; 
    }else{
        printf("A pilha nao esta vazia"); 
    }
        
}

void push(Pilha *pilha, int novoElemento){
    nodePilha *novoNo = (nodePilha*) malloc(sizeof(nodePilha)); 
    novoNo->elemento = novoElemento; 
    novoNo->prox = pilha->topo; // o prox do novo no aponta para o prox elemento a ser desempilhado, ou seja, o elemento do topo
    pilha->topo = novoNo;// atualiza o topo
}

void pop(Pilha *pilha){

    if(verificaVazia(pilha)){
        printf("A pilha esta vazia"); 
    }

    Pilha *aux = pilha->topo; 
    pilha->topo = pilha->topo->prox;    
    free(aux); 

}






int main(int argc, char const *argv[])
{
    Pilha pilha; 
    inicializaPilha(&pilha); 
    verificaVazia(&pilha); 

}
