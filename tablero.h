#ifndef TABLERO_H
#define TABLERO_H

struct Juego;

typedef struct {
    int W, H;
    void ***celdas;

} Tablero;

Tablero* tablero_crear(int ancho, int alto);
void tablero_imprimir(struct Juego *juego);
void tablero_liberar(Tablero *tablero);

#endif


