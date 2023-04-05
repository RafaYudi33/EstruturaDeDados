#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


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



/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void inicializaString(ListaString *lista){
    lista->primElem = NULL; 
    lista->UltElem = NULL; 
}    
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void reinicializaString(ListaString *lista){
    Strdim *aux = lista->primElem; 
     
    //int cont = 0;   
    Strdim *ant = NULL; 
    
    while(aux != NULL){
        ant = aux; 
        aux = aux->prox;
        ant->prox = NULL; 
        free(ant);  
    }
    lista->primElem = NULL;
    lista->UltElem = NULL; 
    //inicializaString(lista);
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void copiaCaracteres(ListaString *str1, ListaString *str2){
    Strdim *aux = str1->primElem; 

    while (aux!=NULL){
        insereCaractere(str2, aux->c);
        aux = aux->prox;  
    }

}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void ConcatenaStrings(ListaString *str1, ListaString *str2, ListaString *str3){
    copiaCaracteres(str1, str3);   
    copiaCaracteres(str2, str3);   
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
char insereInicio(ListaString *lista, char newChar){
    Strdim *newNode = (char*) malloc(sizeof(Strdim)); 
    newNode->c = newChar; 
    newNode->prox = NULL; 

    if(lista->primElem == NULL){
        lista->primElem = newNode; 
        lista->UltElem = newNode; 
    }else{
        
        newNode->prox = lista->primElem; 
        lista->primElem = newNode; 
        return newChar; 
    }
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void insereSubstring(ListaString *str, ListaString *substring){
    ListaString aux;
    inicializaString(&aux); 
    copiaCaracteres(str, &aux);
    reinicializaString(str); 
 
     

    Strdim *auxSubs = substring->primElem; 
    while(auxSubs != NULL){
        insereCaractere(str, auxSubs->c);
        //printf("%c", auxSubs->c);
        auxSubs = auxSubs->prox; 
    }
    
    
    Strdim *aux2 = aux.primElem;  
    while (aux2!= NULL){
        insereCaractere(str, aux2->c); 
        aux2 = aux2->prox; 
    }

}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
bool comparaTamanho(ListaString *str1, ListaString *str2){
    int contStr1 = 0; 
    int contStr2 = 0;
    Strdim *auxStr1 = str1->primElem; 
    Strdim *auxStr2 = str2->primElem; 
    
    while(auxStr1 != NULL){
        auxStr1 = auxStr1->prox;
        contStr1++; 
    }

    while(auxStr2 != NULL){
        auxStr2 = auxStr2->prox;
        contStr2++;  
    }

    if(contStr1<contStr2){
        //printf("\nA Primeira String e MENOR que a Segunda String!");
        return false; 
    }else if(contStr1>contStr2){
        //printf("\nA Primeira String e MAIOR que a Segunda String");
        return false; 
    }else{
        //printf("\nAs Strings possuem o MESMO tamanho"); 
        return true;
    }

}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
bool verificaStringsIguais(ListaString *str1, ListaString *str2){
    if(comparaTamanho(str1, str2)){
        Strdim *auxStr1 = str1->primElem;
        Strdim *auxStr2 = str2->primElem; 
        while((auxStr1 != NULL)&&(auxStr1->c == auxStr2->c)){            
            auxStr1 = auxStr1->prox; 
            auxStr2 = auxStr2->prox;
        }

        if(auxStr1 == NULL){
            printf("As strings sao iguais"); 
        }else{
            printf("As strings sao diferentes"); 
        }
    }else{
        printf("As strings possuem tamanhos diferentes, portanto são diferentes"); 
    }

}



int main(int argc, char const *argv[])
{
    
    ListaString str1, str2, str3, substring, str4; 
    inicializaString(&str1); 
    insereCaractere(&str1, 'o'); 
    insereCaractere(&str1, 'i'); 
    insereCaractere(&str1, 'i');
    // insereCaractere(&str1, 'a');
    // imprimeString(&str1); 

    // inicializaString(&str2); 
    // copiaCaracteres(&str1, &str2); 
    // //imprimeString(&str2);
    
    // reinicializaString(&str1); 
    // insereCaractere(&str1, 'U'); 
    // insereCaractere(&str1, 'A'); 
    // insereCaractere(&str1, 'U'); 
    // imprimeString(&str1); 

    // inicializaString(&str3);
    // ConcatenaStrings(&str1,&str2,&str3); 
    // removeCaractere(&str3, 1); 
    //imprimeString(&str3);

    // insereCaractere(&str4, 'e'); 
    // insereCaractere(&str4, 'u');
    // InverteString(&str4); 
    // imprimeString(&str4); 

    inicializaString(&substring);
    insereCaractere(&substring,'o'); 
    insereCaractere(&substring,'i');
    insereCaractere(&substring,'i');
    //imprimeString(&substring); 
    //insereSubstring(&str1,&substring);
    //imprimeString(&str1); 

    //verificaSeMenor(&str1, &substring);
    verificaStringsIguais(&str1, &substring); 


}
