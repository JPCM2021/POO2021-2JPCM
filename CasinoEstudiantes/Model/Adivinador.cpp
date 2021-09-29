//
// Created by jpces on 22/09/2021.
//

#include "Adivinador.h"

float Adivinador::jugar(float gonzosApostar){
   int opcion, arregloNumeros[30], generador, contador;
   int eleccionJugador, eleccionCasino;
   int resJugador, resCasino;
   srand(time(NULL));
   opcion = 1+rand()%5;
    cout << "El numero para esta ronda es: " << opcion;
    cout << "Jugador: ingrese la cantidad de veces que cree se va a repetir el numero: ";
    cin >> eleccionJugador;
    cout << "Casino: ingrese la cantidad de veces que cree se va a repetir el numero: ";
    cin >> eleccionCasino;

    for (int i = 0; i <= 30; i++) {
        generador = 1+rand()%15;
        arregloNumeros[i] = generador;
    }

    for (int i = 0; i <= 30; i++) {
        if (arregloNumeros[i] == opcion){
            contador += 1;
        }
    }

    resJugador = abs(contador - eleccionJugador);
    resCasino = abs(contador - eleccionCasino);

    if (resJugador < resCasino){
        cout << "¡El jugador gana!";
    }else if (resCasino < resJugador){
        cout << "¡El casino gana!";
    }
}


