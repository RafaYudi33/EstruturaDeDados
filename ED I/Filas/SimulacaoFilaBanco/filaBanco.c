#include <stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

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
    printf("\nO inicio da fila: %d", fila->inicio->elemento); 
}




int main(int argc, char const *argv[])
{
    Fila Caixas[4]; 
    int tempoSimulacao = 500;  
    int tempoAtual = 0; 
    int atendimentoCaixa[] = {0,0,0,0}; 
    int numCliAtendidos[] = {0,0,0,0};
    int tempoEspera[] = {0,0,0,0}; 
    int tempoSemCliente = 0; 


    inicializaFila(&Caixas[0]); 
    inicializaFila(&Caixas[1]); 
    inicializaFila(&Caixas[2]); 
    inicializaFila(&Caixas[3]); 


    while(tempoAtual <= tempoSimulacao){
        int chegou = rand() % 2; 
        
        if(chegou){
            int randomFila = rand() % 4; 
            inserir(&Caixas[randomFila], tempoAtual);
   
            if(atendimentoCaixa[0] == 0){// se está diponivel 
                if(!vazia(&Caixas[0])){ 
                    removeFila(&Caixas[0]);
                    numCliAtendidos[0] = numCliAtendidos[0] + 1;
                    atendimentoCaixa[0] = rand() % 15; 
                    //printf("\n%d\n", atendimentoCaixa[0]); 
                    tempoEspera[0] = tempoEspera[0] + atendimentoCaixa[0]; 
                }
            }else{
                atendimentoCaixa[0] = atendimentoCaixa[0] - 1; //decrementa 1 minuto do tempo de atendimento 
                tempoAtual++;
            }

            if(atendimentoCaixa[1] == 0){// se está diponivel 
                if(!vazia(&Caixas[1])){  
                    removeFila(&Caixas[1]);
                    numCliAtendidos[1] = numCliAtendidos[1] + 1;
                    atendimentoCaixa[1] = rand()%17;
                    tempoEspera[1] = tempoEspera[1] + atendimentoCaixa[1]; 
                }
            }else{
                atendimentoCaixa[1] = atendimentoCaixa[1] - 1; //decrementa 1 minuto do tempo de atendimento 
                tempoAtual++; 
            }

            if(atendimentoCaixa[2] == 0){// se está diponivel 
                if(!vazia(&Caixas[2])){  
                    removeFila(&Caixas[2]);
                    numCliAtendidos[2] = numCliAtendidos[2] + 1;
                    atendimentoCaixa[2] = rand()%17;
                    tempoEspera[2] = tempoEspera[2] + atendimentoCaixa[2]; 
                }
            }else{
                atendimentoCaixa[2] = atendimentoCaixa[2] - 1; //decrementa 1 minuto do tempo de atendimento 
                tempoAtual++;
            }

            if(atendimentoCaixa[3] == 0){// se está diponivel 
                if(!vazia(&Caixas[3])){  
                    removeFila(&Caixas[3]);
                    numCliAtendidos[3] = numCliAtendidos[3] + 1;
                    atendimentoCaixa[3] = rand()%17;
                    tempoEspera[3] = tempoEspera[3] + atendimentoCaixa[3]; 
                }
            }else{
                atendimentoCaixa[3] = atendimentoCaixa[3] - 1; //decrementa 1 minuto do tempo de atendimento 
                tempoAtual++; 
            }   
        }else{
            tempoAtual++; 
            tempoSemCliente++;
        }
    }

    printf("Fila 0: "); imprimeFila(&Caixas[0]);
    printf("\nTempo medio de espera da fila 0: %d minutos", tempoEspera[0]/numCliAtendidos[0]); 
    printf("\nNumero de clientes atendidos nesta fila: %d", numCliAtendidos[0]); 
    printf("\n");
    printf("\n");

    printf("Fila 1: "); imprimeFila(&Caixas[1]); 
    printf("\nTempo medio de espera da fila 1: %d minutos", tempoEspera[1]/numCliAtendidos[1]); 
    printf("\nNumero de clientes atendidos nesta fila: %d", numCliAtendidos[1]); 
    printf("\n");
    printf("\n");

    printf("Fila 2: "); imprimeFila(&Caixas[2]);
    printf("\nTempo medio de espera da fila 2: %d minutos", tempoEspera[2]/numCliAtendidos[2]); 
    printf("\nNumero de clientes atendidos nesta fila: %d", numCliAtendidos[2]);  
    printf("\n");
    printf("\n");

    printf("Fila 3: "); imprimeFila(&Caixas[3]); 
    printf("\nTempo medio de espera da fila 3: %d minutos", tempoEspera[3]/numCliAtendidos[3]); 
    printf("\nNumero de clientes atendidos nesta fila: %d", numCliAtendidos[3]); 

    //printf("\n Tempo sem Clientes atendidos: %d", tempoSemCliente);
    
  
}