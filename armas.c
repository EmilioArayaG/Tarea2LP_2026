#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "armas.h"

bool escopeta(struct Juego *juego, int dir_x, int dir_y){

    int obj_x = juego->jugador.x + dir_x;
    int obj_y = juego->jugador.y + dir_y;

    printf("\nEscopeta disparada!...\n");

    if (obj_x >= 0 && obj_x < juego->t->W && obj_y >= 0 && obj_y < juego->t->H){
        Celda *c = (Celda *)juego->t->celdas[obj_y][obj_x];
        if (c->pieza != NULL && c->pieza->tipo != 'K'){
            c->pieza->hp -= 2;
            if(c->pieza->hp <= 0){
                printf("El %c ha sido derrotado.\n", c->pieza->tipo);
                free(c->pieza);
                c->pieza = NULL;
            }
        
            return true;
        }
    }
    printf("El disparo no le dio a ningun objetivo.....\n");
    return false;
}
bool francotirador(struct Juego *juego, int dir_x, int dir_y) { 
    printf("Sniper aún no implementado.\n"); return false; 
}
bool granada(struct Juego *juego, int dir_x, int dir_y) { 
    printf("Granada aún no implementada.\n"); return false; 
}
bool especial(struct Juego *juego, int dir_x, int dir_y) { 
    printf("Arma especial aún no implementada.\n"); return false; 
}