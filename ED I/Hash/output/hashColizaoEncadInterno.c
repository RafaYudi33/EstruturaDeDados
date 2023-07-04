#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define tamBase 7
#define tamOver 3
#define MAX tamBase+tamOver

struct aluno{
    int chave; 
    int prox; 
};

struct tabHash{
    struct aluno tabHash[MAX]; 
    int primDispColisao; 
};

typedef struct aluno tabAluno; 
typedef struct tabHash tabelahash;

void inicializaTab(tabelahash *tabhash){
    
    tabhash->primDispColisao = 7; 
    for(int i = 0; i< MAX; i++){
        tabhash->tabHash[i].prox = -1;
        tabhash->tabHash[i].chave = -1; 
    }
}

int funcaoHash(int k){
    return k % tamBase; 
}

void inserir(tabelahash *tabhash, tabAluno reg){
    int x = funcaoHash(reg.chave);
    
    if(tabhash->tabHash[x].chave == -1){// se nao der colisao 
        tabhash->tabHash[x].chave = reg.chave; 
    }else if(tabhash->tabHash[x].chave != -1){// se der colisao 
        if(tabhash->tabHash[x].prox == -1){// deu colisao, mas foi a primeira vez
            tabhash->tabHash[x].prox = tabhash->primDispColisao; 
            tabhash->tabHash[tabhash->primDispColisao].chave = reg.chave;
            tabhash->primDispColisao++; 
        }else{// deu colisao mas nao foi a primeira vez 
            int aux = tabhash->tabHash[x].prox; 
            int ant = -1;

            while(aux != -1){
                ant = aux; 
                aux = tabhash->tabHash[aux].prox; 
            }
            
            tabhash->tabHash[ant].prox = tabhash->primDispColisao; 
            tabhash->tabHash[tabhash->primDispColisao].chave = reg.chave;   
            tabhash->tabHash[tabhash->primDispColisao].prox = -1; 
            tabhash->primDispColisao ++; 
        }


    }
}

void remover(tabelahash *tabhash, int chave){
   int x = funcaoHash(chave); 

    if(tabhash->tabHash[x].chave == chave){// remocao da area base
        tabhash->tabHash[x].chave = -1; 
    }else if(tabhash->tabHash[x].prox != -1){//remoção area de overflow
        int aux = tabhash->tabHash[x].prox; 
        int ant = tabhash->tabHash[x].prox;

        while(aux != -1 && tabhash->tabHash[aux].chave != chave){
            ant = aux; 
            aux = tabhash->tabHash[aux].prox; 
        }

        if(aux == -1){
            printf("elemento inexistentee"); 
        }else{
            tabhash->tabHash[aux].chave = -1; 
            tabhash->tabHash[ant].prox = tabhash->tabHash[aux].prox; 
        }

    }else{
        printf("Elemento inexistente"); 
    }

}

void busca(tabelahash *tabHash, int chave){
    int x = funcaoHash(chave); 

    while(tabHash->tabHash[x].chave != -1){
        if(tabHash->tabHash[x].chave == chave){
            printf("elemento encontrado na posicao %d",x); 
            break; 
        }
        x = tabHash->tabHash[x].prox; 
    }
}

void buscaColisoes(tabelahash *tabHash, int chave){
    int x = funcaoHash(chave); 

    while(tabHash->tabHash[x].chave != -1){
        printf("elemento da colisao %d\n", tabHash->tabHash[x].chave); 
         
        x = tabHash->tabHash[x].prox; 
        printf("o prox %d\n\n", x);
    
    }
}

void imprimeTab(tabelahash *tabHash){
   for(int i = 0; i < MAX; i++){
      if(tabHash->tabHash[i].chave != -1){
         printf("\nChave: %d", tabHash->tabHash[i].chave);
         printf("\nPosicao do Vetor: %d", i); 
         printf("\n\n"); 
      }
   }
}

int main(int argc, char const *argv[])
{
    tabelahash tabela; 
    
    inicializaTab(&tabela);

    tabAluno reg1; 
    reg1.chave = 210; 

    tabAluno reg2; 
    reg2.chave = 70; 

    tabAluno reg3; 
    reg3.chave = 700; 

    tabAluno reg4; 
    reg4.chave = 233; 

    tabAluno reg5; 
    reg5.chave = 2100; 

    inserir(&tabela, reg1); 
    inserir(&tabela, reg2); 
    inserir(&tabela, reg3);
    inserir(&tabela, reg4);
    inserir(&tabela, reg5);
    remover(&tabela, 700);

    buscaColisoes(&tabela, 210); 

    imprimeTab(&tabela); 
}