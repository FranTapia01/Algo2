#include "JuegoDeLaVida.h"

using namespace std;

void iniciarJuego(Tablero &tablero) {
    int fil, col, cantidad, i;
    cout<<"--------------Juego De La Vida--------------"<<endl;
    do {
        cout<<"Cuantas celulas quiere inicializar? (maximo "<<FILAS_MAX*COLUMNAS_MAX<<"):"; cin >> cantidad;
    } while(cantidad > FILAS_MAX*COLUMNAS_MAX || cantidad < 0);

    for(i = 1; i <= cantidad; i++) {
        cout<<"ingrese x e y con un espacio de por medio para la "<< i <<"° coordenada :";
        cin>>fil>>col;
        cambiarEstado(tablero.grilla[fil-1][col-1], Viva);
    }
    actualizarValores(tablero);
}


char pedir_entrada() {
    char entrada;
    cout<<"Pasar turno: p    Reiniciar: r    Salir: s"<<endl;
    cout<<"entrada: ";cin>>entrada;
    return entrada;
}


bool posicionValida(int x, int y) {
    if(x < 0 || x >= FILAS_MAX || y < 0 || y >= COLUMNAS_MAX) {
        return false;
    }
    return true;
}


void pasarTurno(Tablero &tablero) {
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) { 
            int vecino = 0, cantvivas = 0;
          
            for(int cord = 1; cord <= 8; cord++) {
                int fil = i+vecinos[vecino];
                int col = j+vecinos[vecino+1];
                if(posicionValida(fil, col)) {
                    if(getEstado(getCelula(tablero, fil, col)) == Viva || getEstado(getCelula(tablero, fil, col)) == Muriendo) {
                        cantvivas++;
                    }
                }
                vecino += 2;
            }
            if(getEstado(getCelula(tablero, i, j)) == Viva) {
                if(cantvivas < 2 || cantvivas > 3) {
                    cambiarEstado(tablero.grilla[i][j], Muriendo);
                }
            }
            else {
                if(cantvivas == 3) {
                    cambiarEstado(tablero.grilla[i][j], Naciendo);       
                }
            }
        }
    }
    actualizarValores(tablero);
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) { 
            if(getEstado(getCelula(tablero, i, j)) == Muriendo) {
                cambiarEstado(tablero.grilla[i][j], Muerta);
            }
            if(getEstado(getCelula(tablero, i, j)) == Naciendo) {
                cambiarEstado(tablero.grilla[i][j], Viva);
            }
        }
    }
}


bool juegoCongelado(Tablero tablero) {
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) {
            if(getEstado(tablero.grilla[i][j]) != getEstado(tablero.copia[i][j])) {
                return false;
            }
        }
    }   
    return true;
}


void copiarGrilla(Tablero &tablero) {
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) {
            tablero.copia[i][j] = tablero.grilla[i][j];
        }
    }
}
