#include <stdlib.h>
#include <stdio.h>



void descobreMaiorMenor(int *v, int *Menor, int *Maior, int tam){

    *Menor = v[0]; 
    *Maior = v[0]; 

    for (int i = 0; i<tam; i++){
        if(v[i] < *Menor){
            *Menor = v[i]; 
        }

        if(v[i] > *Maior){
            *Maior = v[i]; 
        }
    }
    printf("MAIOR: %d MENOR: %d", *Maior,*Menor);

}

int main(int argc, char const *argv[])
{
    int vet[] = {10,20,2,30,100}; 
    int valor1, valor2; 
    descobreMaiorMenor(vet, &valor1, &valor2, 5);     


    return 0;
}
