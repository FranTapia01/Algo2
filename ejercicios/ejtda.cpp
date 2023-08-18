#include <iostream>
using namespace std;
enum Estado {
    abierto,
    cerrado
};


class IntervaloNumerico {
    private:
    int limiteSup;
    int limiteInf;
    Estado estado;
    public:
    IntervaloNumerico(int s, int i, Estado condicion) {
        limiteInf = i;
        limiteSup = s;
        estado = condicion;
    }
    int getLimiteSup() {
        return limiteSup;
    }
    int getLimiteInf() {
        return limiteInf;
    }
    void setLimiteSup(int nuevoSup) {
        limiteSup = nuevoSup;
    }
    void setLimiteInf(int nuevoInf) {
        limiteInf = nuevoInf;
    }
    int medirLongitud() {
        if (estado == abierto) {
            return (limiteInf - limiteSup)+2;
        }
        return (limiteInf - limiteSup);
    }
    bool esta(int x) {
        int cont = limiteSup;
        while(cont <= limiteInf) {
            if (cont == x){
                return true;
            }
            cont++;
        }
        return false;
    }
    bool incluidoEn(IntervaloNumerico otro) {
        return (limiteSup >= otro.getLimiteSup() && limiteInf <= otro.getLimiteInf());
    }
    bool incluido(IntervaloNumerico otro) {
        return (otro.getLimiteSup() >= limiteSup && otro.getLimiteInf() <= limiteInf);
    }
    void ver() {
        for(int i=limiteSup; i<=limiteInf; i++) {
            cout<<i;
        }
        cout<<endl;
    }

};

int main() {
    IntervaloNumerico inter1(2, 6, cerrado);
    IntervaloNumerico inter2(3, 9, abierto);
    
    inter1.ver();
  
    cout<<inter1.medirLongitud()<<endl;
    cout<<inter2.medirLongitud()<<endl;



    return 0;
}