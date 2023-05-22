#include <stdio.h> 
#include<stdlib.h>
#include<stdbool.h>

struct nodeFila{
    struct nodeFila *prox; 
    int elemento; 
};

struct filaDinamica{
    struct nodeFila *inicio; 
    struct nodeFila *fim; 
};
typedef struct nodeFila nodeFila; 
typedef struct filaDinamica Fila; 


void inicializaFila(Fila *fila){
    fila->inicio = NULL; 
    fila->fim = NULL; 
}

bool vazia(Fila *fila){
    if(fila->inicio == NULL){
        // printf("A fila esta vazia"); 
        return true; 
    }else{
        // printf("A fila nao esta vazia"); 
        return false; 
    }
}

void inserirInicio(Fila *fila, int novoElemento){
    nodeFila *novoNo; 
    novoNo = (nodeFila*) malloc(sizeof(nodeFila)); 
    novoNo->elemento = novoElemento; 

    if(vazia(fila)){
        fila->inicio = novoNo; 
        fila->fim = novoNo;
    }else{
        novoNo->prox = fila->inicio; 
        fila->inicio = novoNo; 
    }
}


void inserir(Fila *fila, int novoElemento){
    
    nodeFila *novoNo; 
    novoNo = (nodeFila*) malloc(sizeof(nodeFila)); 
    novoNo->elemento = novoElemento; 
    
    if(vazia(fila)){
        fila->inicio = novoNo; 
        fila->fim = novoNo; 
        novoNo->prox = NULL; 
    }else{
        fila->fim->prox = novoNo; 
        fila->fim = novoNo;
        novoNo->prox = NULL;  
    }
}

void removeFila(Fila *fila){
    if(vazia(fila)){
        printf("A fila esta vazia, nao ha elementos para remover"); 
    }else{
        nodeFila *aux = fila->inicio;
        fila->inicio = fila->inicio->prox; 
        free(aux); 
    }
}

void imprimeFila(Fila *fila){
    if(vazia(fila)){
        printf("A fila esta vazia"); 
    }else{
        nodeFila *aux = fila->inicio; 

        while(aux != NULL){
            printf("%d ", aux->elemento); 
            aux = aux->prox; 
        }
    }
}

void obterInicio(Fila *fila){
   return fila->inicio->elemento; 
}




int main(int argc, char const *argv[]){

    Fila fila; 

    inicializaFila(&fila); 
    vazia(&fila); 
    inserir(&fila, 8); 
    inserir(&fila, 20); 
    inserir(&fila, 25);
    inserirInicio(&fila, 10); 
    //removeFila(&fila);
    //removeFila(&fila); 
    imprimeFila(&fila);  
    obterInicio(&fila); 
    


}
