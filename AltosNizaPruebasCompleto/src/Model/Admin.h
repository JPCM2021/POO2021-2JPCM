#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <map>
#include "Propietario.h"
#include "Reventa.h"
#include "Fundador.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::map;

class Admin{
    private:
        map<int, Propietario*> propietarios;
        int tarifaAdmin;
        void crearDummyData();
    public:
        Admin();
        int recaudarAdmin();
        int mostrarBeneficios(int id);
        int mostrarPropParqueadero();
        void cambiarTipoPropietario(int id,  int idNuevoProp, string nuevoProp);
};

#endif