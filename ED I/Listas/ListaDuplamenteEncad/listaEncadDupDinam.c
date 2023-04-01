#include<stdlib.h> 
#include<stdio.h>
#include<stdbool.h>

struct NodeDuplo{
    int elemento;
    struct NodeDuplo *prox; 
    struct NodeDuplo *ant; 
};
typedef struct NodeDuplo NodeDuplo; 

typedef struct{
    struct NodeDuplo *primElemento; 
    struct NodeDuplo *ultElemento; 
}Lista; 


void inicializaLista(Lista *lista){
    lista->primElemento = NULL; 
    lista->ultElemento = NULL; 
}

bool listaVAzia(Lista *lista){
    if(lista->primElemento == NULL){
        //printf("\n lista vazia"); 
        return true; 
    }else{
        //printf("lista nao esta vazia"); 
        return false;
    }
}

void insereListaInicio(Lista *lista, int novoElemento){
    NodeDuplo *novoNo = (NodeDuplo*) malloc (sizeof(NodeDuplo)); 
    novoNo->ant = NULL; 
    novoNo->prox = NULL; 
    novoNo->elemento = novoElemento; 
    
    if(listaVAzia(lista)){
        lista->primElemento = novoNo; 
        lista->ultElemento = novoNo; 
    }else{
        novoNo->prox = lista->primElemento; 
        lista->primElemento->ant = novoNo; 
        lista->primElemento = novoNo; 
    }
}

void insereListaFim(Lista *lista, int novoElemento){
    NodeDuplo *novoNo = (NodeDuplo*) malloc(sizeof(NodeDuplo)); 
    novoNo->ant = NULL; 
    novoNo->prox = NULL; 
    novoNo->elemento = novoElemento; 

    if(listaVAzia(lista)){
        lista->primElemento = novoNo; 
        lista->ultElemento = novoNo; 
    }else{
        novoNo->prox = lista->ultElemento->prox; 
        lista->ultElemento->prox = novoNo; 
        lista->ultElemento = novoNo;
    }

}





void insereOrdenado(Lista *lista, int novoElemento){
    NodeDuplo *novoNo = (NodeDuplo*) malloc(sizeof(NodeDuplo)); 
    novoNo->ant = NULL; 
    novoNo->prox = NULL; 
    novoNo->elemento = novoElemento; 

    if(listaVAzia(lista)){
        lista->primElemento = novoNo; 
        lista->ultElemento = novoNo; 
    }else{

        NodeDuplo *aux;
        aux = lista->primElemento; 
        
        while (aux != NULL && aux->elemento < novoElemento){  
            //printf("o prox: %d ", aux->prox); 
            aux = aux->prox; 
        }   
        //printf("%d ", aux->elemento); 
        if(aux == NULL){// se for inserir no fim
            novoNo->prox = lista->ultElemento->prox;
            lista->ultElemento->prox = novoNo;
            novoNo->ant = lista->ultElemento; 
            lista->ultElemento = novoNo;
        }else if(aux->ant == NULL){//insere no começo
            novoNo->prox = lista->primElemento;
            novoNo->ant = lista->primElemento->ant;
            lista->primElemento->ant = novoNo; 
            lista->primElemento = novoNo;
        }else{// se for inserir no meio 
            novoNo->ant = aux->ant; // arrumo o anterior do novoNo
            novoNo->prox = aux;  // arrumo o prox do novo no
            aux->ant->prox = novoNo; // arrumo o prox do anterior
            aux->ant = novoNo; // arrumo o anterior do aux
            // quando inserir no meio, sempre terei que arrumar 4 ponteiros 
        }
        

    }
}


void imprimeLista(Lista *lista){
    NodeDuplo *aux; 
    aux = lista->primElemento; 

    while(aux != NULL){
        printf("%d ", aux->elemento); 
        aux = aux->prox; 
    }
    printf("\n");

}

void imprimeListaInversa(Lista *lista){
    NodeDuplo *aux; 
    aux = lista->ultElemento; 

    while(aux != NULL ){
        printf("%d ", aux->elemento); 
        aux = aux->ant; 
    }
    printf("\n");

}

NodeDuplo getUltElem(Lista *lista){
    printf("\nO ultimo elemento: %d\n", lista->ultElemento->elemento); //ou assim: (*lista->ultElemento) 
    return *lista->ultElemento; 
}

NodeDuplo getPrimElem(Lista *lista){
    printf("\nO primeiro elemento: %d\n", *lista->primElemento);
    return *lista->primElemento; 
}

int main(int argc, char const *argv[]){

    Lista li; 

    inicializaLista(&li); 
    // insereListaFim(&li, 3); 
    // insereListaFim(&li, 6); 
    // insereListaFim(&li, 9); 
    // insereListaFim(&li, 12); 
    insereOrdenado(&li, 1); 
    insereOrdenado(&li, 0); 
    // getPrimElem(&li);
    insereOrdenado(&li, 10); 
    insereOrdenado(&li, 8); 
    //getUltElem(&li); 
    imprimeLista(&li); 
    imprimeListaInversa(&li); 


}
