#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5 



struct Pilha{
    int vPilha[MAX];
    int topo;  
    int tam; 
};
typedef struct Pilha Pilha; 

void inicializaLista(Pilha *pilha){
    pilha->topo = 0; 
}

bool verificaVazia(Pilha *pilha){
    if(pilha->topo == 0){
        //printf("A pilha esta vazia");
        return true;
    }else{
        //printf("A pilha nao esta vazia"); 
        return false; 
    }
}

bool pilhaCheia(Pilha *pilha){
    if(pilha->topo == MAX){
       // printf("\nA pilha esta cheia"); 
        return true; 
    }else{
        //printf("\nA pilha nao esta cheia"); 
        return false; 
    }
}

void push (Pilha *pilha, int elemento){
    if(pilhaCheia(pilha)){
        printf("A pilha esta cheia, nao e possivel realizar a insercao"); 
    }else{
        pilha->vPilha[pilha->topo] = elemento; 
        pilha->topo++; 
    }

}

void pop(Pilha *pilha){
    int aux = retornaTopo(pilha); 
    if(verificaVazia(pilha)){
        printf("A pilha esta vazia, nao e possivel remover");
    }else{
        pilha->vPilha[pilha->topo-1] = NULL;  
        pilha->topo--; 
    }
}

void imprimePilha(Pilha *pilha){ 
    for(int aux = pilha->topo; aux != 0; aux--){
        printf("%d ", pilha->vPilha[aux-1]);  
    }
}

int retornaTopo(Pilha *pilha){
    printf("\nO elemento do topo: %d \n", pilha->vPilha[pilha->topo-1]); 
    return pilha->vPilha[pilha->topo-1]; 
}



int main(int argc, char const *argv[]){


    Pilha pilha; 
    inicializaLista(&pilha);
    push(&pilha, 3);  
    push(&pilha, 4);  
    push(&pilha, 6);
    push(&pilha, 8);
    push(&pilha, 2);
    pop(&pilha); 
    pop(&pilha);
    imprimePilha(&pilha); 
    retornaTopo(&pilha);   
    //pilhaCheia(&pilha); 
   // verificaVazia(&pilha); 

}
