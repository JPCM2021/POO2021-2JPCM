//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout << "Inicialice casino";
    // Inicia un jugador en el mapa para comenzar
    jugadoresMap.insert({1,new Jugador(1,"Pedro rodriguez", 500)});

    // Inicia  los juegos disponibles y los agrega al mapa de juegos
    Mayor13 * juego1 = new Mayor13();
    juegosDisponibles.push_back(juego1);
    DosColores * juego2 = new DosColores();
    juegosDisponibles.push_back(juego2);
    Adivinador * juego3 = new Adivinador();
    juegosDisponibles.push_back(juego3);

    // Agregar aqui los demas juegos
}

void Casino::agregarJugador(long id, string nombreJugador, double dinero) {
    int cantGonzos;
    if (verExisteJugador(id) == false){
        cantGonzos = convertirPesosAGonzos(dinero);
        //Aqui miro en el codigo completo como agregar al jugador, ya que no lo pude resolver.
        Jugador * pJugador = new Jugador (id, nombreJugador, cantGonzos);
        jugadoresMap.insert({pJugador->getId(), pJugador});
    }else{
        throw std::domain_error("Ya existe un jugador con dicho id\n");
    }

    //throw std::logic_error("Metodo por implementar");
}

bool Casino::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (gonzosApostar < 1 ){
        throw std::domain_error("Debe apostar al menos 1 gonzo\n");
    }

    if (verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > juegosDisponibles.size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador, gonzosApostar)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }

    throw std::logic_error("Metodo incompleto");
    // Retorna verdadero si el jugador ganó y false si el jugador perdio
    return false;
}

void Casino::verInfoJugador(long idJugador){
    throw std::logic_error("Metodo por implementar");
}

bool Casino::verPuedeContinuar(int idJugador, float gonzosApostar) {
    throw std::logic_error("Metodo por implementar");

}

void Casino::retirarJugador(long idJugador) {
    //aqui miro en el codigo para saber por que no me funciona el apuntador al mapa de jugadores, y descubro que me falta poner[idJugador]
    Jugador * pJugador = jugadoresMap[idJugador];
    jugadoresMap.erase(idJugador);
    throw std::logic_error("Metodo por implementar");

}

void Casino::recargarGonzos(long idJugador) {
    if (verExisteJugador() == true){
        float dinero;
        Jugador *pJugador = jugadoresMap[idJugador];
        cout << "Ingrese la cantidad de dinero a convertir en gonzos: ";
        cin >> dinero;
        convertirPesosAGonzos(dinero);
    }
    throw std::logic_error("Metodo por implementar");
}



bool Casino::verExisteJugador(long id) {
    for (map<long, Jugador*>::iterator pJugador = jugadoresMap.begin();
         pJugador != jugadoresMap.end(); pJugador++)
    {
        if (pJugador->first == id){
            return true;
        }
    }
    return false;

    throw std::logic_error("Metodo por implementar");
}

double Casino::convertirPesosAGonzos(double dinero) {
    return (dinero / 100);
}


Casino::~Casino() {
    cout << "Llame al destructor de casino \n";
    // Se libera la memoria del jugadores y de juegos
    for(map<long, Jugador*>::iterator it = jugadoresMap.begin(); it != jugadoresMap.end(); it++)
    {
        Jugador * jugadorTemp = jugadoresMap[it->first];
        delete jugadorTemp;
    }

    for(int i=0; i< juegosDisponibles.size(); i++)
    {
        Juego * juegoTemp = juegosDisponibles.at(i);
        delete juegoTemp;
    }
}