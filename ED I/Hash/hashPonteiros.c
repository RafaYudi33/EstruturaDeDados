#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 67

struct aluno{
    int matricula; 
    char nome[90]; 
    char email[40]
};

typedef struct aluno tabAluno; 

void inicializaTab(tabAluno *tabhash[]){
    for(int i = 0; i< MAX; i++){
        tabhash[i] = NULL;  
    }
}

int funcaoHash(int k){
    return k % MAX; 
}

void inserir(tabAluno *tabhash[], tabAluno reg){
    int x = funcaoHash(reg.matricula);

    tabAluno *aux =  (tabAluno*) malloc(sizeof(tabAluno)); 
    aux->matricula = reg.matricula; 
    strcpy(aux->email, reg.email); 
    strcpy(aux->nome, reg.nome);

    tabhash[x] = aux;  
}

void remover(tabAluno *tabhash[], int matricula){
    int x = funcaoHash(matricula); 
    tabAluno *aux = tabhash[x]; 
    
    if(aux->matricula == matricula){
        tabhash[x] = NULL; 
        free(aux);  
    }

}

void imprimirTab(tabAluno *tabhash[]){
    for(int i = 0; i<MAX;i++){
        tabAluno *aux = tabhash[i]; 

        if(aux!=NULL){
            printf("Matricula: %d \n",aux->matricula); 
            printf("Nome: %s\n", aux->nome); 
            printf("Email: %s\n\n", aux->email); 
        }
    } 
}

int main(int argc, char const *argv[])
{
    tabAluno *tabHash[MAX]; 
    
    inicializaTab(&tabHash);

    tabAluno reg1; 
    reg1.matricula = 123441; 
    strcpy(reg1.nome, "Eu"); 
    strcpy(reg1.email, "euEmail");

    tabAluno reg2; 
    reg2.matricula = 132111; 
    strcpy(reg2.nome, "Rafael"); 
    strcpy(reg2.email, "RafaelEmail");

    tabAluno reg3;     reg3.matricula = 213311; 
    strcpy(reg3.nome, "Gabriel"); 
    strcpy(reg3.email, "GabrielEmail");


    inserir(&tabHash, reg1); 
    inserir(&tabHash, reg2); 
    inserir(&tabHash, reg3);
    remover(&tabHash, 213311);

    imprimirTab(&tabHash); 
}
