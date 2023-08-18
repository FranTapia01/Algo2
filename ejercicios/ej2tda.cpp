#include <iostream>
using namespace std;


class Turnador {
    private:
    int turnoActual;
    int maximo;
    public:
    Turnador(int max){
        turnoActual=0;
        maximo=max;
    }
    int getTurnoActual(){
        return turnoActual;
    }
    void siguienteTurno(){
        if(turnoActual<maximo){
            turnoActual+1;
        }
    }
    int darTurno(){
        turnoActual++;
        return turnoActual-1;
    }       
    
    int turnosRestantes(){
        return maximo-turnoActual;
    }

    int turnosDados(){
        return turnoActual-1;
    }
    
};

int main(){
    Turnador turnador(10);
    turnador.darTurno();
    
    throw "hola";
    cout<<turnador.getTurnoActual()<<endl;
    return 0;
}