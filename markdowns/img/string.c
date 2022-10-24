#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main (){

    int cifra,n,eleccion,valor, contador = 0;
    int n1;

    printf("Las cifras a mostrar son:");
    scanf("% d", &cifra);

    int array[cifra];

    srand(time(NULL));

    for(int i = 0; i < cifra; i++)
    
    
    {


        array[i] = rand() %  100 + 1;


        printf("%d", array[i]);



    }


    printf("indique el numero que desea cambiar:");
    scanf("%d", &cifra);

if ( eleccion == 1){

    While (eleccion == 2);

    {


    printf("Ingrese el nuevo valor:");
    scanf("%d", & cifra);


array[cifra]= valor;

for(int i = 0; i < n; i++)

    {

    printf("%d", array[i]);
    }

return 0;

}