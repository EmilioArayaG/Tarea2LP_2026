#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "piezas.h"

void spawn_nivel(struct Juego *juego, int nivel){
    Tablero *tablero = juego->t;
    
    int y_rey = tablero->H - 1;
    int x_rey = 1 + (rand() % (tablero->W - 2));

    juego->jugador.tipo = 'K';
    juego->jugador.hp = 1;
    juego->jugador.x = x_rey;
    juego->jugador.y = y_rey;

    Celda *celda_rey = (Celda *)tablero->celdas[y_rey][x_rey];
    celda_rey->pieza = &(juego->jugador);

    
}