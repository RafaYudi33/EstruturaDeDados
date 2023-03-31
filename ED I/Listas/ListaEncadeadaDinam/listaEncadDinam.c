#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct no{
    int elemento; 
    struct no *prox; 
};
typedef struct no Node; 

struct Lista{
    Node *primElem; 
    Node *ultElem; 
}; 
typedef struct Lista Lista;

void inicializaLista(Lista *lista){
    lista->primElem = NULL;
    lista->ultElem = NULL;  
}

bool listaVazia(Lista *lista){
    
    if(lista->primElem == NULL){
        //printf("A lista esta vazia!"); 
        return true; 
    }else{
        //printf("A lista nao esta vazia");
        return false;
    }
}

void insereNoInicio(Lista *lista, int novoElemento){
    Node *novoNo;
    novoNo = (Node*) malloc(sizeof(Node)); 
    novoNo->elemento = novoElemento; 
    novoNo->prox = NULL; 

    if(listaVazia(lista)){// se a lista estiver vazia
        lista->ultElem = novoNo; 
        lista->primElem = novoNo;         
    }else{
        novoNo->prox = lista->primElem;  
        lista->primElem = novoNo; 
    }
}    


void imprimeLista(Lista *lista){
    Node *aux; 
    aux = lista->primElem; 

    while(aux!=NULL){
        
        printf("%d ", aux->elemento); 
        aux = aux->prox; 
    }
}

Node* buscaNo(Lista *lista, int elemento){
    Node *aux = lista->primElem; 

    while (aux != NULL && aux->elemento != elemento){
        aux = aux->prox; 
    } 

    if(aux == NULL){
        printf("Elemento inexistente!"); 
    }else{
        printf("Elemento encontrado: %d", aux->elemento); 
    }
}

void removeNo(Lista *lista, int elemento){
    Node *anterior = NULL; 
    Node *aux = lista->primElem; 

    while(aux != NULL && aux->elemento != elemento){
        anterior = aux; 
        aux = aux->prox; 
    } 

    if(aux == NULL){
        printf("Elemento nao pertence a lista!");
    }else if(aux == lista->primElem){// se for o primeiro da lista
        lista->primElem = aux->prox; 
    }else if(aux == lista->ultElem){
        anterior->prox = aux->prox; 
        lista->ultElem = anterior; 
    }else{
        anterior->prox = aux->prox;   
    }
    free(aux); 
}

Node getPrimElemento(Lista *lista){
    printf("\nO primeiro elemento:%d ", *lista->primElem);
}    

Node getUltElemento(Lista *lista){
    printf("\nO ultimo elemento:%d ", *lista->ultElem);
}

void verificaTam(Lista *lista){
    Node *aux = lista->primElem;  
    int tam = 0; 

    while(aux != NULL){
        aux = aux->prox; 
        tam++;
    }

    printf("\nO tamanho da lista: %d ", tam); 
}


void insereOrdenado(Lista *lista, int novoElemento){
    Node *novoNo; 
    novoNo = (Node*) malloc(sizeof(Node)); 
    novoNo->elemento = novoElemento; 
    novoNo->prox = NULL; 

    if(listaVazia(lista)){// se a lista estiver vazia 
        lista->primElem = novoNo; 
        lista->ultElem = novoNo; 
    }else{

        Node *aux = lista->primElem; 
        Node *anterior = NULL; 

        while(aux != NULL && aux->elemento < novoElemento){
            anterior = aux; 
            aux = aux->prox; 
        }

        if(anterior == NULL){ //se for inserir no inicio da lista
            novoNo->prox = lista->primElem; 
            lista->primElem = novoNo; 
        }else if(aux == NULL){//se for inserir no ultimo da lista
            lista->ultElem = novoNo;
            novoNo->prox = anterior->prox;
            anterior->prox = novoNo;
        }else{// se for no meio da lista
            novoNo->prox = anterior->prox; 
            anterior->prox = novoNo; 
        }
    }
}

int main(int argc, char const *argv[])
{
    Lista li; 

    inicializaLista(&li); 
    // insereNoInicio(&li, 6);
    // insereNoInicio(&li, 7);
    // insereNoInicio(&li, 8);
    // insereNoInicio(&li, 9);
    insereOrdenado(&li, 3); 
    insereOrdenado(&li,2);
    insereOrdenado(&li,8);
    insereOrdenado(&li,4);
    removeNo(&li,4); 

    imprimeLista(&li);
    getPrimElemento(&li);  
    getUltElemento(&li); 
    verificaTam(&li); 
    //buscaNo(&li, 8); 
    //listaVazia(&li); 
}
