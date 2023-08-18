#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>
#include "Celula.h"

static const int FILAS_MAX = 20;
static const int COLUMNAS_MAX = 80;

struct Tablero {
    Celula grilla[FILAS_MAX][COLUMNAS_MAX];
    Celula copia[FILAS_MAX][COLUMNAS_MAX];
    int celulasVivas;
    float celulasMuertas;
    float celulasNacidas;
    int celulasNacidasTurno;
    int celulasMuertasTurno;
    int promedioMuertes;
    int promedioNacimientos;
    int turnos;
};


//Inicializa todas las celulas del tablero
void inicializarTablero(Tablero &tablero);


//Muestra por consola el tablero
void mostrarTablero(Tablero &tablero);


//actualiza los valores del tablero
void actualizarValores(Tablero &tablero);


//Devuelve la celula que esta en la posicion pasada por parametro
Celula getCelula(Tablero tablero, int fil, int col);


#endif