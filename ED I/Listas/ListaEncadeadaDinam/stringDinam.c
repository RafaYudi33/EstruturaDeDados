#include <stdio.h>
#include<stdlib.h>

struct strdim{
    char c; 
    struct strdim *prox; 
};
typedef struct strdim Strdim; 

struct ListaString {
    Strdim *primElem;
    Strdim *UltElem;
};
typedef struct ListaString ListaString; 

void inicializaString(ListaString *lista){
    lista->primElem = NULL; 
    lista->UltElem = NULL; 
}    

void reinicializaString(ListaString *lista){
    Strdim *aux = lista->primElem; 
    lista->primElem = NULL; 
    //int cont = 0;   
    Strdim *ant = NULL; 
    
    while(aux != NULL){
        ant = aux; 
        aux = aux->prox;
        free(ant); 
    }
    lista->UltElem = NULL; 
}



void imprimeString (ListaString *lista){
    Strdim *aux = lista->primElem; 

    if(aux == NULL){
        printf("\nA lista esta vazia");   
    }else{
        printf("\n"); 
        while(aux != NULL){
            printf("%c",aux->c); 
            aux = aux->prox; 
        }
    }
}

void copiaCaracteres(ListaString *str1, ListaString *str2){
    Strdim *aux = str1->primElem; 

    while (aux!=NULL){
        insereCaractere(str2, aux->c);
        aux = aux->prox;  
    }

}

void ConcatenaStrings(ListaString *str1, ListaString *str2, ListaString *str3){
    copiaCaracteres(str1, str3);   
    copiaCaracteres(str2, str3);   
}

int tamanhoString(ListaString *lista){
    Strdim *aux = lista->primElem; 
    int tam = 0; 

    while (aux != NULL ){
        aux = aux->prox; 
        tam++; 
    }
    printf("tamanho da string: %d", tam); 
    return tam; 
}

void insereCaractere(ListaString *lista, char newChar){
    Strdim *newNode = (char*) malloc(sizeof(Strdim)); 
    newNode->c = newChar; 
    newNode->prox = NULL; 

    if(lista->primElem == NULL){
        lista->primElem = newNode; 
        lista->UltElem = newNode; 
    }else{
        Strdim *aux = lista->primElem; 
        Strdim *anterior = NULL; 

        while(aux != NULL){
            anterior = aux; 
            aux = aux->prox; 
        }
        anterior->prox = newNode; 
        lista->UltElem = newNode; 
    }

}

void removeCaractere(ListaString *str, int qtd){
    Strdim *aux = str->primElem; 
    Strdim *ant = NULL;
    int cont = 0; 
    

    while (aux!=NULL && cont!=qtd){
        ant = aux; 
        aux = aux->prox; 
        free(ant); 
        cont++; 
    }
    
    str->primElem = aux; 
}

int main(int argc, char const *argv[])
{
    
    ListaString str1, str2, str3; 
    inicializaString(&str1); 
    insereCaractere(&str1, 'o'); 
    insereCaractere(&str1, 'l'); 
    insereCaractere(&str1, 'a');
    imprimeString(&str1); 

    inicializaString(&str2); 
    copiaCaracteres(&str1, &str2); 
    imprimeString(&str2);
    
    // reinicializaString(&str1); 
    // insereCaractere(&str1, 'U'); 
    // insereCaractere(&str1, 'A'); 
    // insereCaractere(&str1, 'U'); 
    // imprimeString(&str1); 

    inicializaString(&str3);
    ConcatenaStrings(&str1,&str2,&str3); 
    removeCaractere(&str3, 1); 
    imprimeString(&str3);

}
