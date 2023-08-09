#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node{
    int valor; 
    struct Node *dir, *esq; 
    int altura; 
    int fb; 
};
typedef struct Node Node; 


bool maior(int a, int b){
    if(a>b)
        return true; 
    else
        return false;         
}

int alturaNo(Node *no){
    if(no == NULL){
        return -1; 
    }else{
        return no->altura;  
    }

}

int fatorBal(Node *no){
    if(no){
        return (alturaNo(no->esq) - alturaNo(no->dir)); 
    }else{
        return 0;
    }
}

Node* rotEsquerda(Node *raiz){
    Node *aux, *f; 
    aux = raiz->dir; 
    f = aux->esq; 

    aux->esq = raiz; 
    raiz->dir = f; 

    raiz->altura =  maior(raiz->esq, raiz->dir)+1; 
    aux->altura =  maior(aux->esq, aux->dir)+1; 

    return aux; 

}

Node* rotDireita(Node *raiz){
    Node *aux, *f; 
    aux = raiz->esq; 
    f = aux->dir; 

    aux->dir = raiz; 
    raiz->esq = f;

    raiz->altura = maior(raiz->esq, raiz->dir) + 1;  
    aux->altura = maior(aux->esq, aux->dir) + 1;  

    return aux; 
}

Node* rotDireitaEsquerda(Node *raiz){
    raiz->dir = rotDireita(raiz->dir); 
    return rotEsquerda(raiz); 
}

Node* balancear(Node *raiz){
    if(fatorBal(raiz) < -1 && fatorBal(raiz->dir <= 0)){
        raiz =  rotEsquerda(raiz); 
    }

    if(fatorBal(raiz) > 1 && fatorBal(raiz->esq >= 0 )){

    }
}// nao finalizado 

Node* inserirAvl(Node *raiz, int elemento){
    if(raiz ==  NULL){
        Node *novoNo = (Node*) malloc(sizeof(Node)); 
        novoNo->valor = elemento; 
        novoNo->esq = NULL;
        novoNo->dir = NULL; 
        novoNo->altura = 0; 
        return novoNo; 
    }else{
        if(elemento < raiz->valor){
            raiz->esq = inserirAvl(raiz->esq, elemento);
        }else{
            raiz->dir = inserirAvl(raiz->dir, elemento); 
        }
    }

    raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)); 

    raiz = balancear(raiz);
        
    
    return raiz; 

}

int main(int argc, char const *argv[])
{
    
    return 0; 
}
