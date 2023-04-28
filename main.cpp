//////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SÁNCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include "listaArticulo.h"

int main(int argc, char *argv[])
{
	listaArticulo articulos;
	
	
	if(articulos.leerArticulo()==false){
		cout<<"No se puede iniciar la simulacion";
	}
	else{
		articulos.imprimir();
	}
	
	
}
