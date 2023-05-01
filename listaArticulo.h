////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023
#pragma once
#include <cstdlib>
#include <iostream>
#include "nodoArticulo.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct listaArticulo;

struct listaArticulo{
	nodoArticulo * primerNodo;

	
	listaArticulo(){ 
		primerNodo = NULL;
	}	
	
	void insertar(string pcodigo, int pcantidadAlmacen, int ptiempoFabricacion, string pcategoria, string pubicacion);
	void imprimir();
	nodoArticulo * buscar(string pcodigo);
	nodoArticulo * eliminar(string pcodigo);
	bool leerArticulo();
}; 
