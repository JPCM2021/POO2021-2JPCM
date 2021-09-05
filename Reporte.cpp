#include <iostream>
#include "Reporte.h"
#include "Producto.h"


Reporte::Reporte()
{
}

void Reporte::existenciasDeInventario(Tienda tienda)
{
	int x;
	cout << "Digita la cantidad: ";
	cin >> x;

	cout << "Los productos con menos cantidad que x son: ";

	for (map<int, Producto>::iterator pProducto = tienda.inventario.begin();
		pProducto != inventario.end(); pProducto++)
	{
		Producto valor = pProducto->second; // Se obtiene el valor asociado al mapa
		if (valor.getCantUnidades() < x)
		{
			valor.mostrarProducto();
		}
	}
}

void Reporte::cantidadProductosVendidos(Tienda tienda)
{
	int totalLicores = 0; // Valores por defecto para iniciar las variables de instancia
	int totalSnacks = 0;

	for (vector<Factura>::iterator pFactura = tienda.facturas.begin();
		pFactura != tienda.facturas.end(); pFactura++)
	{
		for (vector<DetalleFactura>::iterator pDetalleFactura = pFactura->getDetalles().begin();
			pDetalleFactura != pFactura->getDetalles().end(); pDetalleFactura++)
		{
			if (pDetalleFactura->getProducto().getTipoProducto().getNombre() == "Licor")
			{
				totalLicores++;
			}

			if (pDetalleFactura->getProducto().getTipoProducto().getNombre() == "Snack")
			{
				totalSnacks++;
			}
		}
		
	}
	cout << "El total de licores vendidos es de: "<< totalLicores;
	cout << "El total de snacks vendidos es de: " << totalSnacks;

}

void Reporte::totalGananciasTienda(Tienda tienda)
{
	int totalVenta = 0; // Valores por defecto para iniciar las variables de instancia
	int totalCosto = 0;
	int totalGanancia= 0;

	for (vector<Factura>::iterator pFactura = tienda.facturas.begin();
		pFactura != tienda.facturas.end(); pFactura++)
	{
		totalVenta += pFactura->getValorPagarSinIVA();
		for (vector<DetalleFactura>::iterator pDetalleFactura = pFactura->getDetalles().begin();
			pDetalleFactura != pFactura->getDetalles().end(); pDetalleFactura++)
		{
			totalCosto += pDetalleFactura->getCantUnidVend() * pDetalleFactura->getProducto().getCosto();
		}

	}
	totalGanancia = totalVenta - totalCosto;
	cout << "Las ganancias de la tienda fueron de un total de: " << totalGanancia;
	

}

void Reporte::verProductosTienda(Tienda tienda)
{
	string nombre;
	float precio = 0;
	int unidades = 0;
	
	for (map<int, Producto>::iterator pProducto = tienda.inventario.begin();
		pProducto != inventario.end(); pProducto++)
	{
		Producto miProducto = pProducto->second; // obtengo el producto del mapa
		nombre = miProducto.getNombre();
		precio = miProducto.getPrecio();
		unidades = miProducto.getCantUnidades();

		cout << "Nombre: " << nombre << "precio:" << precio << "unidades:" << unidades;
	}

}

void Reporte::valoraPagarIVA(Tienda tienda)
{
	float total = 0; // Valores por defecto para iniciar las variables de instancia
	
	for (vector<Factura>::iterator pFactura = tienda.facturas.begin();
		pFactura != tienda.facturas.end(); pFactura++)
	{
		total += pFactura->getValorTotal();
	}
	
	cout << "El valor a pagar a la DIAN por IVA es un total de: " << total;


}


