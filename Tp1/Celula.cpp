#include "Celula.h"

void inicializarCelula(Celula &celula) {
    celula.estado = Muerta;
}


void cambiarEstado(Celula &celula,  EstadoCelula estado) {
    celula.estado = estado;
}


EstadoCelula getEstado(Celula celula) {
    return celula.estado;
}

