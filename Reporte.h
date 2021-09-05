#ifndef REPORTE_H
#define REPORTE_H


#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include "Tienda.h"



using std::cin;
using std::cout;
using std::endl;
using std::string;

class Reporte
{
private: //Atributos
	string nombre;
	map<int, Producto> inventario;
	int cantidadProductos;
	int gananciaTotal;


	/*Se crea un metodo por cada reporte solicitado abajo
	Informes:

	Reporte de productos para los que quedan menos de X productos en inventario, donde X es un valor dado por el usuario.

		Cantidad de productos de tipo Snack y de tipo Licores vendidos.

		Ganancias obtenidas por la tienda

		Ver todos los productos de la tienda

		Valor a pagar por IVA a la DIAN.*/

public:
	Reporte();
	void existenciasDeInventario(Tienda tienda);
	void cantidadProductosVendidos(Tienda tienda);
	void totalGananciasTienda(Tienda tienda);
	void verProductosTienda(Tienda tienda);
	void valoraPagarIVA(Tienda tienda);

};
#endif /* !REPORTE_H */