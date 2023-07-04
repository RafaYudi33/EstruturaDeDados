#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 7

struct tpdados
{
   int matricula; 
   char nome[80];
   char email[40]; 

};
typedef struct tpdados tpdados; 

void inicializaTabHash(tpdados *tbhash){
   for(int i = 0; i<MAX; i++){
      tbhash[i].matricula = -1; 
   }
}

int hash(int k){
   return k % MAX; 
}

void inserir(tpdados *tabhash, tpdados reg){
      int x = hash(reg.matricula); 

      tabhash[x].matricula = reg.matricula; 
      strcpy(tabhash[x].nome, reg.nome); 
      strcpy(tabhash[x].email, reg.email); 
}

void remover(tpdados *tabhash, int matricula){
   int x = hash(matricula); 

   if(tabhash[x].matricula == matricula){
      tabhash[x].matricula = -1; 
   }else{
      printf("Elemento nao existe na tabela");
   }

}

void busca(tpdados *tabhash, int matricula){
   int x = hash(matricula); 

   if(tabhash[x].matricula == matricula){
      printf("Matricula: %d", tabhash[x].matricula);
      printf("\nNome: %s", tabhash[x].nome); 
      printf("\nEmail: %s", tabhash[x].email); 
   }else{
      printf("Elemento nao existe na tabela"); 
   }
}

void imprimeTab(tpdados *tabHash){
   for(int i = 0; i < MAX; i++){
      if(tabHash[i].matricula != -1){
         printf("\nMatricula: %d", tabHash[i].matricula);
         printf("\nNome: %s", tabHash[i].nome);
         printf("\nEmail: %s", tabHash[i].email);
         printf("\n"); 
      }
   }
}


int main(int argc, char const *argv[])
{

   tpdados tabHash[MAX];
   inicializaTabHash(&tabHash); 

   tpdados reg1; 
   reg1.matricula = 210; 
   strcpy(reg1.nome, "Eu"); 
   strcpy(reg1.email, "euEmail");

   tpdados reg2; 
   reg2.matricula = 70; 
   strcpy(reg2.nome, "Rafael"); 
   strcpy(reg2.email, "RafaelEmail");

   tpdados reg3; 
   reg3.matricula = 700; 
   strcpy(reg3.nome, "Gabriel"); 
   strcpy(reg3.email, "GabrielEmail");


   inserir(&tabHash, reg1); 
   inserir(&tabHash, reg2); 
   inserir(&tabHash, reg3); 
   //busca(&tabHash, 123441);  
   imprimeTab(&tabHash); 
    
}


