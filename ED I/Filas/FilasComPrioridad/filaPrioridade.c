#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct nodeFila{
    int elemento; 
    struct nodeFila *prox; 
    int prioridade; 
};

struct Fila{
    struct nodeFila *inicio; 
    struct nodeFila *fim; 
};

typedef struct nodeFila nodeFila; 
typedef struct Fila Fila; 

inicializaFila(Fila *fila){
    fila->inicio = NULL; 
    fila->fim = NULL; 
}

bool vazia(Fila *fila){
    if(fila->inicio == NULL){
        return true; 
    }else{
        return false; 
    }
}

void inserir(Fila *fila, int elemento, int prioridade){
    nodeFila *novoNo = (nodeFila*) malloc(sizeof(nodeFila)); 
    novoNo->elemento = elemento; 
    novoNo->prioridade = prioridade; 
    novoNo->prox = NULL; 

    if(novoNo == NULL){// fila cheia, malloc retorna NULL quando nao há espaço para alocar 
        printf("Fila cheia!"); 
    }else if(vazia(fila)){
        fila->inicio = novoNo; 
        fila->fim = novoNo;
    }else{
        nodeFila *aux = fila->inicio; 
        nodeFila *ant = NULL; 

        while(aux != NULL && prioridade <= aux->prioridade){
            ant = aux; 
            aux = aux->prox; 
        }
        
        if(aux == NULL){// no fim
            fila->fim->prox = novoNo; 
            fila->fim = novoNo; 
        }else if(ant == NULL){// no começo
            novoNo->prox = fila->inicio; 
            fila->inicio = novoNo; 
        }else{//no meio
            novoNo->prox = ant->prox; 
            ant->prox = novoNo; 
        }
    }
}

void imprimir(Fila *fila){ 
    nodeFila *aux = fila->inicio; 
    if(vazia(fila)){
        printf("Fila vazia"); 
    }else{
        while(aux != NULL){
            printf("%d ", aux->elemento); 
            aux = aux->prox; 
            // printf("o prox e: %d ", aux); 
        }
    }
}

int main(int argc, char const *argv[])
{
    Fila fila; 

    inicializaFila(&fila); 
    inserir(&fila, 20, 11); 
    inserir(&fila, 30, 13);
    inserir(&fila, 25, 12);
    inserir(&fila, 10, 7);
     

    imprimir(&fila); 
}
