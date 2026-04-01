#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tablero.h"
#include "piezas.h"
#include "main.h"


Tablero* tablero_crear(int ancho, int alto){
    Tablero *new_tablero = (Tablero*)malloc(sizeof(Tablero));
    if (new_tablero == NULL){
        printf("error al crear el tablero xdxdxdxd jajajaja big guy big guy big guy");
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
    for(int y=0; y<tablero->H; y++){
        for(int x=0; x<tablero->W; x++){
            Celda *celda_actual = (Celda*)tablero->celdas[y][x];
            free(celda_actual);
        }
        free(tablero->celdas[y]);

    }
    free(tablero->celdas);
}

void tablero_imprimir(struct Juego *juego){
    Tablero *tablero = juego->t;
    printf("\n--- Tablero (%dx%d) ---\n", tablero->W, tablero->H);
    for(int y = 0; y < tablero->H; y++){
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
    printf("-------------------\n");
}