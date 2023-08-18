#ifndef JUEGODELAVIDA_H_ 
#define JUEGODELAVIDA_H_ 

#include "Tablero.h"

static const int vecinos[16] = {0,1, 0,-1, 1,0, -1,0, 1,1, -1,-1, 1,-1, -1,1}; //coordenadas de los posibles vecinos van de 2 en 2

//Recorre la grilla
void pasarTurno(Tablero &tablero);

//Verifica si la posicion pasada corresponde a una valida del tablero.
bool posicionValida(int x, int y);

//Pide al usuraio las coordenadas en las que quiere que nazcan celulas y las pasa al tablero.
void iniciarJuego(Tablero &tablero);

//Pide al usuario en cada turno si quiere pasar un turno, reiniciar o salir.
char pedir_entrada();

//Verifica si el juego se congelo es decir no sufrió modificaciones en dos turnos consecutivos.
bool juegoCongelado(Tablero tablero);

//Copia la grilla actual
void copiarGrilla(Tablero &tablero);


#endif