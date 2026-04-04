#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tablero.h"
#include "piezas.h"
#include "main.h"


Tablero* tablero_crear(int ancho, int alto){
    Tablero *new_tablero = (Tablero*)malloc(sizeof(Tablero));
    if (new_tablero == NULL){
        printf("Error al crear el tablero\n");
    }
    new_tablero->W = ancho;
    new_tablero->H = alto;

    new_tablero->celdas = (void***)malloc(sizeof(void**) * alto);
    for (int y = 0; y < alto; y++){
        new_tablero->celdas[y] = (void**)malloc(sizeof(void*)* ancho);
        for (int x = 0; x < ancho; x++){
            Celda *new_celda = (Celda*)malloc(sizeof(Celda));
            new_celda->pieza = NULL;
            new_tablero->celdas[y][x] = new_celda;
        }
    }
    return new_tablero;
        
}

void tablero_liberar(Tablero *tablero){
    for(int y = 0; y < tablero->H; y++){
        for(int x = 0; x < tablero->W; x++){
            Celda *celda_actual = (Celda*)tablero->celdas[y][x];
            if (celda_actual->pieza != NULL && celda_actual->pieza->tipo != 'R') {
                free(celda_actual->pieza);
            }
            free(celda_actual);
        }
        free(tablero->celdas[y]);
    }
    free(tablero->celdas);
}

void tablero_imprimir(struct Juego *juego){
    Tablero *tablero = juego->t;
    
    printf("--- Juego REY AJEDREZ - Nivel %d ---\n", juego->nivel_actual);
    printf("Armas: [1] Escopeta (%d/%d) | [2] Sniper (%d/%d) | [3] Granada (%d/%d) | [4] Especial (%d/%d)\n",
        juego->arsenal.municion_actual[0], juego->arsenal.municion_maxima[0],
        juego->arsenal.municion_actual[1], juego->arsenal.municion_maxima[1],
        juego->arsenal.municion_actual[2], juego->arsenal.municion_maxima[2],
        juego->arsenal.municion_actual[3], juego->arsenal.municion_maxima[3]);
    printf("Movimiento: WASD | Diagonales: QEZC | Salir: X\n\n");

    for(int y = 0; y < tablero->H; y++){
        printf("%2d ", tablero->H - y); 
        for(int x = 0; x < tablero->W; x++){
            Celda *c = (Celda*)tablero->celdas[y][x];

            if (c->pieza == NULL){
                printf("[ ]");
            } else {
                printf("[%c]", c->pieza->tipo);
            }
        }
        printf("\n");
    }

    printf("   "); 
    for(int x = 0; x < tablero->W; x++){
        if (x + 1 >= 10) {
            printf(" %d", x + 1);
        } else {
            printf(" %d ", x + 1);
        }
    }
    printf("\n\n");
}