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

void mover_enemigos(struct Juego *juego){
    Tablero *t = juego->t;
    for(int y = 0; y < t->H; y++){
        for(int x = 0; x < t->W; x++){
            Celda *c = (Celda *)t->celdas[y][x];
            if(c->pieza != NULL){
                c->pieza->desplz = false;
            }
        }
    }
    for(int y = 0; y < t->H;y++){
        for(int x = 0; x <t->W; x++){
            Celda *c_actual = (Celda *)t->celdas[y][x];
            Pieza *p_actual = c_actual->pieza;
            if(p_actual != NULL && p_actual->tipo != 'K' && p_actual->desplz == false){
                int dir_x = 0, dir_y = 0;
                if(p_actual->tipo == 'P'){
                    int dif_x = juego->jugador.x - p_actual->x;
                    int dif_y = juego->jugador.y - p_actual->y;
                    if(abs(dif_x) > abs(dif_y)){
                        dir_x = (dif_x > 0) ? 1 : -1;
                    } else {
                        dir_y = (dif_y > 0) ? 1 : -1;
                    }
                }

            int new_x = p_actual->x + dir_x;
            int new_y = p_actual->y +dir_y;
            if (new_x >= 0 && new_x < t->W && new_y >= 0 && new_y < t->H){
                Celda *c_destino = (Celda *)t->celdas[new_y][new_x];

                if(c_destino->pieza == NULL || c_destino->pieza->tipo == 'K'){
                    c_actual->pieza = NULL;
                    p_actual->x = new_x;
                    p_actual->y = new_y;
                    p_actual->desplz = true;
                    c_destino->pieza = p_actual;
                }
            }    
            }
        }
    }
}