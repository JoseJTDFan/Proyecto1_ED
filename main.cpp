//////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include "listaArticulo.h"
#include "listaPedidos.h"
#include "listaClientes.h"

int main(int argc, char *argv[])
{
	listaArticulo articulos;
	listaPedidos pedidos;
	listaClientes clientes;
	
	
	pedidos.leerPedidos();
	
	pedidos.imprimir();


    if(articulos.leerArticulo()==false | clientes.leerClientes()== false){
		cout<<"No se puede iniciar la simulacion";
	}
	else{
		//articulos.imprimir();
		clientes.imprimir();
	}

    while(clientes.primerNodo->siguiente != NULL){
        nodoCliente * tmp = clientes.primerNodo;
        if(tmp->prioridad == 10){
            pedidos.insertarAlInicio(articulos.primerNodo->codigo,tmp->codigo,tmp);
        }
        else{
            pedidos.insertarAlFinal(articulos.primerNodo->codigo, tmp->codigo,primerNodo);
        }
        tmp = tmp->siguiente;
    }



	
	
}
