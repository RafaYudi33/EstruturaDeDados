#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

struct reg{
    int chave; 
    struct reg *prox; 
};

typedef struct reg reg; 

void inicializaTab(reg *tabhash[]){
    for(int i = 0; i< MAX; i++){
        tabhash[i] = NULL;  
        //tabhash[i]->prox = NULL; 
    }
}

int funcaoHash(int k){
    return k % MAX; 
}

void inserir(reg *tabhash[], reg registro){
    int x = funcaoHash(registro.chave);
    reg *novoNo = (reg*) malloc(sizeof(reg));
    novoNo->chave = registro.chave;
    novoNo->prox = NULL;  

    if(tabhash[x] == NULL){// se nao tiver colisao
        tabhash[x] = novoNo;
    }else{
        reg *aux = tabhash[x]; 

        while(aux->prox != NULL){
            aux = aux->prox; // o aux sai do laço com o valor da ultima posição
        }
        aux->prox = novoNo; 
    } 
}

void remover(reg *tabhash[], reg registro){
    int x = funcaoHash(registro.chave); 
    reg *aux = tabhash[x]; 
    
    if(aux->chave == registro.chave){// se for remover o elemento sem ser de colisao
        if(aux->prox == NULL){ // se o elemento a ser removido nao tiver nenhuma colisao depois dele
            tabhash[x] = NULL; 
            free(aux); 
        }else{// se tiver elementos de colisao depois dele, coloco o primeiro elemento de colisao na posição X
            tabhash[x] = aux->prox;
            free(aux); 
        }


    }else{// se for remover um elemento de colisao 
        reg *ant = NULL; 
        while(aux != NULL && aux->chave != registro.chave){
            ant = aux; 
            aux = aux->prox; 
        }

        if(aux == NULL){
            printf("Elemento inexistente"); 
        }else{// arruma os ponteiros 
            ant->prox = aux->prox; 
            free(aux); 
        }

    }

}

void imprimirTab(reg *tabhash[]){
    for(int i = 0; i<MAX;i++){
        reg *aux = tabhash[i]; 

        while(aux!=NULL){
            printf("%d\n", aux->chave);
            aux = aux->prox; 
        } 
   
    } 
}

int main(int argc, char const *argv[])
{
    reg *tabHash[MAX]; 
    
    inicializaTab(&tabHash);
    



    reg reg1; 
    reg1.chave = 20; 

    reg reg2; 
    reg2.chave = 10; 

    reg reg22; 
    reg22.chave = 30;
   

    reg reg3;     
    reg3.chave = 3; 

    inserir(&tabHash, reg1); 
    inserir(&tabHash, reg2); 
    inserir(&tabHash, reg3);
    inserir(&tabHash, reg22); 
    remover(&tabHash, reg1);

    imprimirTab(&tabHash); 
}


// HASHING ALFANUMERICO
// int hash(TipoChave chave) {
//     int soma = 0;
//     int i;
//     int comp = strlen(chave);

//     // Itera sobre cada caractere da chave
//     for (i = 0; i < comp; i++) {
//         // Multiplica o valor ASCII do caractere pelo índice (com a sugestão de adicionar 1 ao índice)
//         soma = soma + ((i+1) * chave[i]);
//     }

//     // Retorna o valor de hash calculado, utilizando o operador de módulo para limitá-lo ao intervalo desejado
//     return (soma % MAX);
// }