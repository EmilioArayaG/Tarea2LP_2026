#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    Juego juego;
    juego.nivel_actual = 1;
    
    printf("Iniciando Rey - Nivel %d...\n", juego.nivel_actual);
    juego.t = tablero_crear(12, 12);

    tablero_imprimir(&juego);

    tablero_liberar(juego.t);

    free(juego.t);

    return 0;
}