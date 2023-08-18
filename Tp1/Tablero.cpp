#include "Tablero.h"

using namespace std;

void inicializarTablero(Tablero &tablero) {
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) {
            inicializarCelula(tablero.grilla[i][j]);      
        } 
    }
    tablero.celulasMuertas = 0;
    tablero.celulasNacidas = 0;
    tablero.celulasVivas = 0;
    tablero.promedioMuertes = 0;
    tablero.promedioNacimientos = 0;
    tablero.celulasMuertasTurno = 0;
    tablero.celulasNacidasTurno = 0;
    tablero.turnos = 0;
}


void mostrarTablero(Tablero &tablero) {
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) {
              
            if (getEstado(tablero.grilla[i][j]) == Muerta) {
                cout<<"□ ";
            }     
            else {
                cout<<"■ ";
            }   
            if (j == COLUMNAS_MAX-1) {
                cout<<endl;
            }      
        }
    }
    cout<<"Celulas Vivas: "<<tablero.celulasVivas<<"    Turnos: "<<tablero.turnos<<endl;
    cout<<"Murieron: "<<tablero.celulasMuertasTurno<<" "<<"Nacieron: "<<tablero.celulasNacidasTurno<<endl;
    cout<<"Prom Muertes: "<<tablero.promedioMuertes<<"% "<<"Prom Nacimientos: "<<tablero.promedioNacimientos<<"%"<<endl;
}


void actualizarValores(Tablero &tablero) {
    tablero.celulasVivas = 0;
    tablero.celulasNacidasTurno = 0;
    tablero.celulasMuertasTurno = 0;
    
    for(int i = 0; i < FILAS_MAX; i++) {
        for(int j = 0; j < COLUMNAS_MAX; j++) {
            
            if(getEstado(tablero.grilla[i][j]) == Viva) {
                tablero.celulasVivas++;
            } 
            if(getEstado(tablero.grilla[i][j]) == Naciendo) {
                tablero.celulasNacidasTurno++;
                tablero.celulasNacidas++;
                tablero.celulasVivas++;
            } 
            if(getEstado(tablero.grilla[i][j]) == Muriendo) {
                tablero.celulasMuertasTurno++;
                tablero.celulasMuertas++;
            } 
        }
    }
    if(tablero.turnos != 0) { 
        tablero.promedioMuertes = (tablero.celulasMuertas/tablero.turnos)*100;
        tablero.promedioNacimientos = (tablero.celulasNacidas/tablero.turnos)*100;       
    }
    tablero.turnos++;
}


Celula getCelula(Tablero tablero, int fil, int col) {
    return tablero.grilla[fil][col];
}


