#include <stdlib.h>
#include <stdio.h> 

int main(int argc, char const *argv[])
{
    
    int x = 10; 
    int *p; 

    p = &x;

    printf("p = %d",p); //imprime o endereço de memoria 
    printf("\n*p = %d",*p); //imprime o valor dentro de x
    printf("\nx = %d",x);// imprime o valor de x, 10 
    *p = 12; // atualiza o valor de x, pois atualiza o valor em que p aponta 
    printf("\nx = %d",x);// imprime o valor de x, 10

     
}