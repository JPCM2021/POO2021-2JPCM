//
// Created by lufe0 on 3/11/2021.
//

#include "gtest/gtest.h"
#include "../src/Model/Admin.h"

TEST(AdminTest, recaudarAdmin){
    int tarifaAdmin = 100;

    Admin admin;
    int resultado = admin.recaudarAdmin();
    EXPECT_EQ(70005,resultado);

}

TEST(AdminTest, mostrarPropParqueadero){

    Admin admin;
    int propietarios = admin.mostrarPropParqueadero();

    EXPECT_EQ(5, propietarios);
}

TEST(AdminTest, imprimirBeneficios){
    int id = 1;
    Admin admin;

    int beneficios = admin.mostrarBeneficios(id);

    EXPECT_EQ(2, beneficios);
}

/*TEST(AdminTest, cambiarTipoPropietario){
    //No pude entender bien esta funcion :(
}*/