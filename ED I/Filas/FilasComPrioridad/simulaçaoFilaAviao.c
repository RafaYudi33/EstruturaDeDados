#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <time.h>


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

void inicializaFila(Fila *fila){
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
        }
    }
}


void remover(Fila *fila){
    if(vazia(fila)){
        printf("A fila esta vazia, nao ha elementos para remover"); 
    }else{
        nodeFila *aux = fila->inicio; 
        fila->inicio = fila->inicio->prox; 
        free(aux);  
    }
}

int main(int argc, char const *argv[])
{
    Fila Pista;
    inicializaFila(&Pista); 

    int tempoAtual = 0; 
    int tempoSimulacao = 500;
    //int tempoSemAviao = 0;  
    int ocupacaoPista = 0; 
    
    time_t t;
    srand((unsigned) time(&t));

    while(tempoAtual <= tempoSimulacao){
        int chegou; 
    
        for(int i = 0; i<4;){
            chegou = rand() % 2; 
            if(i == 3){// verifição pra ver se nao chegou nenhum aviao no intervalo de 5 segundos
                chegou = 1;// forço a chegada de um aviao no ultimo segundo
            }

            if(chegou){
                int prioridade = rand() % 2; // 0 - decolagem     1 - Pouso
                inserir(&Pista, tempoAtual, prioridade);

                if(ocupacaoPista == 0){// se pista == 0, a pista está livre
                    if(!vazia(&Pista)){
                        if(prioridade){
                            printf("Momento da chegada: %d ", Pista.inicio->elemento); 
                            printf("\ntempo atual: %d", tempoAtual);
                            printf("\nTempo de Espera: %d\n", (tempoAtual - Pista.inicio->elemento));// tempo atual = segundo atual que o aviao sera removido, Pista.inicio->elemento = tempo que ele chegou
                            remover(&Pista); 
                            ocupacaoPista = 10;
                        }else{
                            printf("Momento da chegada: %d ", Pista.inicio->elemento); 
                            printf("\ntempo atual: %d", tempoAtual);
                            printf("\nTempo de espera: %d\n", (tempoAtual - Pista.inicio->elemento));
                            remover(&Pista); 
                            ocupacaoPista = 5;
                        }
                    }
                }else{// pista está ocupada 
                    ocupacaoPista--; 
                    tempoAtual++; 
                }
                

                break; //recomeça o intervalo de 1 - 5 segundos 
            }else{
                tempoAtual++;
                i++; 
            }
        }
    }

}
