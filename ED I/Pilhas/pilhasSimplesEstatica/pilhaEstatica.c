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
    pilha->tam = 0;

}

bool verificaVazia(Pilha *pilha){
    if(pilha->tam == 0){
        printf("A pilha esta vazia");
        return true;
    }
}

bool pilhaCheia

void push (Pilha *pilha, int elemento){
    pilha->vPilha[pilha->topo] = elemento; 
    pilha->topo++; 
}

void imprimePilha(Pilha *pilha){
    int aux = pilha->topo; 
    
    while(aux != MAX+1){
        printf("%d ", pilha->vPilha[aux]);
        aux++;  
    }

}




int main(int argc, char const *argv[]){


    Pilha pilha; 
    inicializaLista(&pilha); 
    verificaVazia(&pilha); 

}
