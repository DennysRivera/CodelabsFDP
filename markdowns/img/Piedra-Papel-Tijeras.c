#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int usuario, pc;

    printf("Seleccionar opcion: \n\n\t1. Piedra\n\t2. Papel\n\t3. Tijera\n\nMi opcion: ");
    scanf("%d", &usuario);

    srand(time(NULL));
    pc = rand() % 3 + 1;

    switch (usuario)
    {
    case 1:
        if (pc == 1)
        {
            printf("\n\t\t**EMPATE**\nSeleccionaste Piedra, y tu contrincante tambien.");
        } else {
            if (pc == 2)
            {
                printf("\n\t\t**DERROTA**\nSeleccionaste Piedra, pero tu contrincante escogio Papel");
            } else {
                printf("\n\t\t**VICTORIA**\nSeleccionaste Piedra, mientras que tu contrincante escogio Tijera");
            }
        }
        
        break;

    case 2:
        if (pc == 2)
        {
             printf("\n\t\t**EMPATE**\nSeleccionaste Papel, y tu contrincante tambien.");
        } else {
            if (pc == 3)
            {
                printf("\n\t\t**DERROTA**\nSeleccionaste Papel, pero tu contrincante escogio Tijera");
            } else {
                printf("\n\t\t**VICTORIA**\nSeleccionaste Papel, mientras que tu contrincante escogio Piedra");
            }
        }

        break;
        
    case 3:
        if (pc == 3)
        {
             printf("\n\t\t**EMPATE**\nSeleccionaste Tijera, y tu contrincante tambien.");
        } else {
            if (pc == 1)
            {
                printf("\n\t\t**DERROTA**\nSeleccionaste Tijera, pero tu contrincante escogio Piedra");
            } else {
                printf("\n\t\t**VICTORIA**\nSeleccionaste Tijera, mientras que tu contrincante escogio Papel");
            }
        }

        break;
    
    default:
        printf("Tu opcion no fue valida. Has sido descalificado");

        break;
    }

    return 0;
}