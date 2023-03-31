#include <stdlib.h>
#include <stdio.h> 
#define MAX 20 

struct Lista{
    int elementos[MAX]; 
    int qtdElementos;     

}; 
typedef struct Lista Lista; 



void criaLista(Lista *lista){
    
    for(int i =0; i<MAX; i++){
        lista->elementos[i] = NULL;
        
    }
    lista ->qtdElementos = 0 ; 
}



void insereListaFim (Lista *li, int valor){

    if(li->qtdElementos == 0){
        li->elementos[0] = valor; 
        //printf("valor"); 
        li->qtdElementos++; 
    
    }else{    
        li->elementos[li->qtdElementos] = valor;
        li->qtdElementos++;
        
    }
}   


void inserePosicao(Lista *li, int posi, int valor){
    int contaPosi = 0;
    for(int i = posi /*3*/; i<li->qtdElementos; i++){
        contaPosi++; /*2*/   
    }

    int aux = li->qtdElementos;
    for(int i = 0; i<contaPosi; i++){
        li->elementos[aux] = li->elementos[aux-1];
        aux--;
    }

    li->elementos[posi] = valor; 
    li->qtdElementos++; 

} 

void InsereInicio( Lista *li, int valor){
    if (li->qtdElementos == 0){
        li->elementos[0] = valor; 
        li->qtdElementos++; 
    }else{
        int aux = li->qtdElementos;
        for(int i = 0; i < li->qtdElementos; i++){ 
            li->elementos[aux] = li->elementos[aux-1];
            aux--;  
        }

        li->elementos[0] = valor; 
        li->qtdElementos++; 
    }


}

    void imprimeLista (Lista li, int posiAtual){ 
        
        
            if(posiAtual < li.qtdElementos){    
                printf("%d ", li.elementos[posiAtual]);
                imprimeLista(li, posiAtual+1); 
            }

    }

    void removeLista (Lista *li, int posiElem){
        int aux = posiElem; 
        
        for(int i = 0; i<li->qtdElementos; i++){
            li->elementos[aux] = li->elementos[aux+1]; 
            aux++; 
        }

        li->qtdElementos--; 

    }


int main(int argc, char const *argv[])
{
    Lista li;   
    criaLista(&li);  
    insereListaFim(&li,5);
    insereListaFim(&li,4);
    InsereInicio(&li, 6); 
    inserePosicao(&li, 1, 300);
    inserePosicao(&li, 3, 600); 
    removeLista(&li, 1); 
    
  
    imprimeLista(li, 0); 
    



    return 0;
}
