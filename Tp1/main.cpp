#include "JuegoDeLaVida.h"

using namespace std;

int main()
{
    Tablero tablero;
    inicializarTablero(tablero);
    iniciarJuego(tablero);

    while (true) { 
        mostrarTablero(tablero);
        if(juegoCongelado(tablero)) {
            cout<<"////////////////El juego se congelo :( ////////////////"<<endl;
        }
        copiarGrilla(tablero);

        char desicion = pedir_entrada();
        if(desicion == 's') {
            break;
        }
        if(desicion == 'r') {
            inicializarTablero(tablero);
            iniciarJuego(tablero);
        } 
        if(desicion == 'p') {
            pasarTurno(tablero);
        }
    }
    return 0;
}
