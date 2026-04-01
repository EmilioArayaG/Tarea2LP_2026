#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main() {
    Juego juego;
    juego.nivel_actual = 1;
    
    printf("Iniciando Rey - Nivel %d...\n", juego.nivel_actual);
    juego.t = tablero_crear(12, 12);
    spawn_nivel(&juego, juego.nivel_actual);

    bool jugando = true;
    char input; 
    
    while (jugando) {
        tablero_imprimir(&juego);
        printf("\nIngresa tu movimiento (Q,W,E,A,S,D,Z,C) X PARA SALIR: ");
        scanf(" %c", &input);
        
        if (input == 'X' || input == 'x'){
            jugando = false;
            break;
        }
        
        int dir_x = 0, dir_y = 0;

        switch(input){
            case 'W': case 'w': dir_y = -1; break;
            case 'A': case 'a': dir_x = -1; break;
            case 'S': case 's': dir_y = 1; break;
            case 'D': case 'd': dir_x = 1; break;
            case 'Q': case 'q': dir_x = -1; dir_y = -1; break;
            case 'E': case 'e': dir_x = 1; dir_y = -1; break;
            case 'Z': case 'z': dir_x = -1; dir_y = 1; break;
            case 'C': case 'c': dir_x = 1; dir_y = 1; break;
            default: 
                printf("Movimiento invalido. \n");
                continue;
        }
        
        int new_x = juego.jugador.x + dir_x;
        int new_y = juego.jugador.y + dir_y;
        
        if (new_x >= 0 && new_x < juego.t->W && new_y >= 0 && new_y < juego.t->H){
            Celda *celda_vieja = (Celda*)juego.t->celdas[juego.jugador.y][juego.jugador.x];
            celda_vieja->pieza = NULL;
            juego.jugador.x = new_x;
            juego.jugador.y = new_y;
            Celda *celda_nueva = (Celda*)juego.t->celdas[new_y][new_x];
            celda_nueva->pieza = &(juego.jugador);
        } else {
            printf("Movimiento invalido. \n");
        }
    }

    tablero_liberar(juego.t);

    free(juego.t);

    return 0;
}