#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>


struct nodeArvore{
    int elemento ;
    struct nodeArvore *dir;  
    struct nodeArvore *esq;  
};

typedef struct nodeArvore no; 


no* criaArvoreVazia(){
   return NULL;  
}

//cria raiz
void criaRaiz(int elemento){
    no *raiz = (no*) malloc(sizeof(no));
    raiz->elemento = elemento; 
    raiz->dir = NULL; 
    raiz->esq = NULL; 
}

bool verificaVazia(no *noArvore){
    if(noArvore->elemento == NULL){
        printf("A arvore esta vazia"); 
        return true; 
    }else{
        printf("A arvore nao esta vazia"); 
        return false;
    }
}

void criaFilhoDireita(no *pai, int elemento){
    no *novoElemento = (no*)malloc(sizeof(no)); 
    novoElemento->elemento = elemento;
    novoElemento->dir = NULL; 
    novoElemento->esq = NULL; 
    pai->dir = novoElemento;
}

void criaFilhoEsquerda(no *pai, int elemento){
    no *novoElemento = (no*)malloc(sizeof(no)); 
    novoElemento->elemento = elemento; 
    novoElemento->esq = NULL; 
    novoElemento->dir = NULL;
    pai->esq = novoElemento;  
}

int verificaNivel(no *raiz, int valor, int nivel){
    if(raiz == NULL){
        return NULL;      
    }

    if(raiz->elemento == valor){
        return nivel; 
        printf("O valor do nivel: %d", nivel); 
    }
    int nivelEsquerda = verificaNivel(raiz->esq, valor, nivel++); 
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
