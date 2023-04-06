#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//pilha: inserçao e remoção no começo da lista


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
        //printf("A pilha esta vazia");  
        return true; 
    }else{
        //printf("A pilha nao esta vazia"); 
        return false; 
    }
        
}

void push(Pilha *pilha, int novoElemento){
    nodePilha *novoNo = (nodePilha*) malloc(sizeof(nodePilha)); 
    novoNo->elemento = novoElemento; 

    //pilha topo = lista->primElemento
    novoNo->prox = pilha->topo; // o prox do novo no aponta para o prox elemento a ser desempilhado, ou seja, o elemento do topo
    pilha->topo = novoNo;// atualiza o topo
}

void pop(Pilha *pilha){

    if(verificaVazia(pilha)){
        printf("A pilha esta vazia"); 
    }

    Pilha *aux = pilha->topo; // auxiliar recebe o topo, que será removido
    pilha->topo = pilha->topo->prox;// atualiza o topo 
    free(aux); //remove o antigo topo

}

void imprimePilha(Pilha *pilha){
    nodePilha *aux = pilha->topo; 
    if(verificaVazia(pilha)){
      printf("A pilha está vazia");
    }else{
        
        while(aux != NULL){
            printf("%d ", aux->elemento); 
            aux = aux->prox; 
        }
    }
}








int main(int argc, char const *argv[])
{
    Pilha pilha; 
    inicializaPilha(&pilha); 
    //'verificaVazia(&pilha); 
    push(&pilha, 4);
    push(&pilha, 6);
    push(&pilha, 8);
    pop(&pilha); 
    imprimePilha(&pilha);

}
