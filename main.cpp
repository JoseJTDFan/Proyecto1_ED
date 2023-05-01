//////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include "listaArticulo.h"
#include "listaPedidos.h"
#include "listaClientes.h"
#include <thread>

int main(int argc, char *argv[])
{
	listaArticulo articulos;
	listaPedidos pedidos;
	listaClientes clientes;
	
	if(articulos.leerArticulo()==false | clientes.leerClientes()== false){
		cout<<"No se puede iniciar la simulacion";
	}
	else{
		//articulos.imprimir();
		//clientes.imprimir();
	}
//	while(true){
		//std::thread thread();
		//thread.join();
  		//std::this_thread::sleep_for(std::chrono::seconds(10));
//	}
	
	pedidos.leerPedidos(clientes,articulos);
	pedidos.imprimir();
	
	
}
