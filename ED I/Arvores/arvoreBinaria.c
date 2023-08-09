#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int elemento; 
    struct node *dir; 
    struct node *esq; 
};

typedef struct node Node; 



void CriaArvoreVazia(Node *raiz){
    return NULL; 
}

Node* inserir(Node *raiz, int elemento){ 
    if(raiz == NULL){
        Node *novoNo = (Node*) malloc(sizeof(Node)); 
        novoNo->elemento = elemento; 
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        return novoNo; 
        
    }else{
        if(elemento < raiz->elemento){
            raiz->esq = inserir(raiz->esq, elemento); // 
            
        }else{
            raiz->dir = inserir(raiz->dir,  elemento); 
        }
        return raiz; 
    }
}

Node* remover(Node *raiz, int elemento){
    if(raiz == NULL){
        printf("Elemento nao encontrado");
        return NULL; 
    }else{
        if(raiz->elemento == elemento){
            if(raiz->esq == NULL && raiz->dir == NULL){// remover no folha
                free(raiz); 
                return NULL;
            }else{
                if(raiz->esq == NULL || raiz->dir == NULL){ //remover no com apenas um filho
                    Node *aux; 
                    if(raiz->esq !=NULL){
                        aux = raiz->esq; 
                    }

                    if(raiz->dir != NULL){
                        aux = raiz->dir;
                    }

                    free(raiz); 
                    return(aux);
                }else{
                    Node *aux = raiz->esq; 

                    while(aux != NULL){
                        aux = raiz->dir; 
                    }

                    raiz->elemento = aux->elemento;
                    aux->elemento = elemento; 
                    raiz->esq = remover(raiz->esq, elemento);
                }
            }
        }else{
            if(elemento <  raiz->elemento){
                raiz->esq = remover(raiz->esq, elemento); 
            }else{
                raiz->dir = remover(raiz->dir, elemento); 
            }
        }
    }
}

void imprimirPreOrdem(Node *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->elemento);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);  
    }
    
}

void imprimirInOrdem(Node *raiz){
    if(raiz != NULL){
        imprimirInOrdem(raiz->esq);
        printf("%d ", raiz->elemento);
        imprimirInOrdem(raiz->dir);  
    }
   
}

void imprimirPosOrdem(Node *raiz){
    if(raiz != NULL){
        imprimirPosOrdem(raiz->esq);
        imprimirPosOrdem(raiz->dir);  
        printf("%d ", raiz->elemento);
    }
   
}

void retornaPai(Node *raiz, int elemento, Node *pai){
    if(raiz != NULL){
        if (raiz->elemento == elemento){
            if(pai == NULL){
                printf("Este elemento é a raiz"); 
            }else{
                printf("O pai do elemento:%d ---> %d ",elemento , pai->elemento);
            }
        }else{
            retornaPai(raiz->esq, elemento, raiz); 
            retornaPai(raiz->dir, elemento, raiz); 
        }
    }
}

void verificaNivel(Node *raiz, int elemento, int nivel){
    if(raiz != NULL){
        if (raiz->elemento == elemento){
            printf("O nivel do elemento %d na arvore --> %d", elemento, nivel); 
        }else{
            verificaNivel(raiz->esq, elemento, nivel+1); 
            verificaNivel(raiz->dir, elemento, nivel+1); 
        }
    }
}

bool verificaEstritamenteBin(Node *raiz){
    if(raiz == NULL){
        return true;
    }

    if(raiz->esq == NULL && raiz->dir == NULL ){
        //printf("Arvore estritamente Binaria"); 
        return true; 
    }

    if(raiz->esq != NULL && raiz->dir != NULL){
        bool subArvoreEsquerda = verificaEstritamenteBin(raiz->esq); 
        bool subarvoreDireita = verificaEstritamenteBin(raiz->dir); 
        return subArvoreEsquerda && subarvoreDireita;       
    }

    //printf("Arvore nao e estritamente binaria"); 
    return false; 

}

int alturaDaArvore(Node *raiz){ // 10 15 
    if(raiz == NULL){
        return -1; 
    }else{
        int subArvoreEsq = alturaDaArvore(raiz->esq); //-1 
        int subArvoreDir = alturaDaArvore(raiz->dir); //0

        if(subArvoreEsq>subArvoreDir){
            return subArvoreEsq + 1;            
        }else{
            return subArvoreDir + 1; 
        }
    }
}

int contaNos(Node *raiz){
    if(raiz == NULL){
        return 0; 
    }else{
        return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);  
    }
}

int contaFolhas(Node *raiz){
    if(raiz == NULL){
        return 0;
    }else if(raiz->esq == NULL && raiz->dir == NULL){
        return 1; 
    }else{
        return contaFolhas(raiz->esq) + contaFolhas(raiz->dir);  
    }
}

bool verificaBalanceamento(Node *raiz){
    if(raiz == NULL){
        return 1; 
    }else{

        int diferencaBal = alturaDaArvore(raiz->esq) - alturaDaArvore(raiz->dir); 

        if((diferencaBal <=1 && diferencaBal >= -1) && (verificaBalanceamento(raiz->esq) && verificaBalanceamento(raiz->dir))){
            return 1; 
        }else{
            return 0; 
        }

    }
}

void percursoNivel(Node *raiz){
    if(raiz == NULL){ 
        printf("Arvore esta vazia"); 
    }

    //Fila *fila = criarFila(); 

    //enfileirar(raiz); 

    while(/* !FilaVazia(fila) */1){
        Node *noAtual = /*desenfileirar(fila)*/1; 
        printf("No atual"); 

        if(noAtual->esq != NULL){
            //enfileirar(noAtual->esq);
        }

        if(noAtual->dir != NULL){
            //enfileirar(noAtual->dir);
        }
    }

}


int main(int argc, char const *argv[])
{
    Node *raiz = NULL; 

    raiz = inserir(raiz, 100); 
    raiz = inserir(raiz, 90);
    //raiz = inserir(raiz, 80);
    //raiz = inserir(raiz, 95); 
    // raiz = inserir(raiz, 120); 
    raiz = inserir(raiz, 110); 
    // raiz = inserir(raiz, 130);  
    
    imprimirPreOrdem(raiz); 
    
    printf("\n");
    imprimirInOrdem(raiz); 
    
    printf("\n");
    imprimirPosOrdem(raiz); 
    
    // printf("\n");
    // retornaPai(raiz, 110, NULL); 
    
    // printf("\n");
    // verificaNivel(raiz, 110, 0); 
    
    printf("\n"); 
    if(verificaEstritamenteBin(raiz)){
        printf("Arvore estritamente Binaria");
    }else{
        printf("Arvore NAO estritamente binaria"); 
    }

    printf("\n"); 
    int qtdFolhas = contaFolhas(raiz); 
    printf("Quantidade de folhas --> %d", qtdFolhas); 

    printf("\n");
    if(verificaBalanceamento(raiz)){
        printf("Balanceada"); 
    }else{
        printf("Nao balanceada");
    } 
    
}
