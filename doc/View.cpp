#include "View.h"

View::View()
{
}

void View::mostrarMenuReportes()
{
    int opcion = -1;
    do
    {

        cout << "Reportes\n"
             << endl;
        cout << "0. Volver \n";
        std::cout << "Digita el numero: ";
        std::cin >> opcion;

        // TODO completar
        Reporte generadorReportes;
        switch (opcion)
        {
        case 1:
            generadorReportes.existenciasDeInventario(laFarra);
            break;
        case 2:
            generadorReportes.cantidadProductosVendidos(laFarra);
            break;

        case 3:
            generadorReportes.totalGananciasTienda(laFarra);
            break;

        case 4:
            generadorReportes.verProductosTienda(laFarra);
            break;

        case 5:
            generadorReportes.valoraPagarIVA(laFarra);
            break;
        }

    } while (opcion != 0);
}

void View::mostrarMenu()
{
    int opcion = -1;
    do
    {

        cout << "Menu Tienda\n";
        cout << "1. Agregar Productos \n";
        cout << "2. Mostrar Productos \n";
        cout << "3. Vender \n";
        cout << "4. Mostrar Ventas \n";
        cout << "5. Reportes \n";
        cout << "0. Salir \n";
        std::cout << "Digita el numero: ";
        std::cin >> opcion;

        switch (opcion)
        {

        case 1:
            laFarra.agregarProducto();
            break;
        case 2:
            laFarra.mostrarProductos();
            break;

        case 3:
            laFarra.vender();
            break;

        case 4:
            laFarra.mostrarFacturas();
            break;

        case 5:
            mostrarMenuReportes();
            break;
        }

    } while (opcion != 0);
}