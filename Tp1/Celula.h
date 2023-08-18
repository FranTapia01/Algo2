#ifndef CELULA_H_
#define CELULA_H_

enum EstadoCelula {
    Viva,
    Muerta,
    Naciendo,
    Muriendo
};

struct Celula {
    EstadoCelula estado;
};

//Inicializa la celula como muerta
void inicializarCelula(Celula &celula);

//Cambia el estado de una celula
void cambiarEstado(Celula &celula,  EstadoCelula estado);

//Devuelve el estado de una celula
EstadoCelula getEstado(Celula celula);

#endif