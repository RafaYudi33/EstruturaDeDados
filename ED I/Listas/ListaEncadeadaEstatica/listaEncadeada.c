#include<stdlib.h> 
#include<stdio.h>
#define MAX 20

struct reg{
    int elemento; 
    int prox;
}; 

struct listaEncadeada
{
    int dispo; 
    int prim;   
    struct reg Registro[MAX]; 
    int tam; 
};

typedef struct listaEncadeada Lista; 


void InicializaLista(Lista* lista){
    lista->dispo = 0; 
    lista->prim = -1; 
    lista->tam = 0;
    int i = 0;
    for (i = 0; i<MAX - 1; i++){
        lista->Registro[i].prox = i+1; 
        lista->Registro[i].elemento = NULL; 
    }

    lista->Registro[i].prox = -1; 
}



insereLista(Lista *lista, int elemento){
    if(lista->tam != MAX){ // se a lista não estiver cheia 
        
        lista->Registro[lista->dispo].elemento = elemento; //a primeira posição disponivel recebe o novo elemento
        int aux; 
        aux = lista->Registro[lista->dispo].prox; // auxiliar que guarda a proxima posição disponivel (vai ser usada na linha 69)
        lista->Registro[lista->dispo].prox = -1;  // seta o prox da posição inserida como: -1
        lista->tam++; 
        
        if (lista->prim != -1){// se o elemento não for o unico na lista
            int i, anterior; 
            anterior = -1;  
            i = lista->prim; 
            
            while((i != -1) && (lista->Registro[i].elemento < elemento)){
                anterior = i; // percorre a lista e armazena o anterior
                i = lista->Registro[i].prox; // recebe o prox, para continuar percorrendo 
            }

            if(anterior == -1){// se o elemento vai ser inserido como primeiro da lista 
                lista->Registro[lista->dispo].prox = lista->prim; //o prox do elemento inserido aponta para o antigo primeiro elemento, que agora é o segundo elemento.
                lista->prim = lista->dispo; // atualiza o ponteiro que aponta para o primeiro elemento 
            }else{// se o elemento vai ser inserido como o ultimo da lista 
                lista->Registro[lista->dispo].prox = lista->Registro[anterior].prox; // o ponteiro prox da posicao em que o elemento foi inserido, recebe o ponteiro da posição anterior, que no caso é o -1, apontando para o vazio por ser o ultimo elemento da lista 
                lista->Registro[anterior].prox = lista->dispo;// atualiza o prox do anterior, fazendo ele apontar para a posicao inserida.
            }

        }else{
            lista->prim = lista->dispo; 
        }    

        lista->dispo = aux; 

    }else{
        printf("Lista Cheia!"); 
    }

}


void Remove(Lista *lista, int elemento){
    if(lista->prim == -1){
        printf("Não há elementos para serem removidos!");
    }else{
        int anterior = -1; 
        int i = lista->prim; 
        //int cont = 0;


        while((i!= -1) && (lista->Registro[i].elemento != elemento)){
            anterior = i; 
            i = lista->Registro[i].prox; 
        } 
        printf("\n%d: ", i ); 
        if (i == -1){// verifica se o elemento existe, pois se i == -1, entao todas as posições foram percorridas
            printf("Este elemento nao existe na lista\n");
        }else{// caso o elemento exista    
            lista->Registro[i].elemento == NULL;
            lista->Registro[anterior].prox = lista->Registro[i].prox; // o prox do anterior recebe o prox da posição removida
            
            lista->Registro[i].prox = lista->dispo;// o prox da posiçao i agora aponta para a atual posicao disponivel
            lista->dispo = i;                      //atualiza o ponteiro dispo, que agora aponta para a posição removida, se tornando a primeira posiçao disponivel



            if(lista->Registro[lista->prim].elemento == elemento){ //se o elemento a ser removido for o primeiro da lista 
                lista->prim = lista->Registro[i].prox;  
            }

            lista->tam--; 
        }    
    }
}

void imprimeLista(Lista lista){

    if (lista.prim == -1){
        printf("A lista esta vazia"); 
    }else{
        for(int i = lista.prim; i!= -1; i = lista.Registro[i].prox){ 
            printf("%d ", lista.Registro[i].elemento); 
        }
    }                                                                                                   
}
    


int main(int argc, char const *argv[])
{

Lista li; 

InicializaLista(&li); 
insereLista(&li, 7); 
insereLista(&li, 8);
insereLista(&li,9);
insereLista(&li, 8); 
insereLista(&li,11); 
insereLista(&li, 10); 
Remove(&li, 11); 



 

imprimeLista(li); 

}
