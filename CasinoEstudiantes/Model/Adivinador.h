//
// Created by jpces on 22/09/2021.
//

#ifndef CASINO_ADIVINADOR_H
#define CASINO_ADIVINADOR_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>
#include <cmath>

class Adivinador: public Juego{
protected:
    int numeroRepetido;
    int apuestaJugador;
    int apuestaCasino;
    virtual float calcularResultado(float gonzosApostar) override;
public:
    virtual ~Adivinador();
    virtual float jugar(float gonzosApostar) override;
};

#endif //CASINO_ADIVINADOR_H
