//
// Created by jpces on 7/10/2021.
//

#ifndef UNTITLED_PROPIETARIO_H
#define UNTITLED_PROPIETARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Propiedad.h"

class Propietario{
private:
    string nombre;
    int id;
    Propiedad propiedad;
    int tipoPropietario;

public:
    void pagarAdmin(Propietario);
};
#endif //UNTITLED_PROPIETARIO_H
