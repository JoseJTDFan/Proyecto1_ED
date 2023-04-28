////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023
#pragma once
#include <cstdlib>
#include <iostream>
#include "nodoArticulo.h"
#include "nodoPedido.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct listaPedidos;

struct listaPedidos{
	nodoPedido *primerNodo,*ultimoNodo;
	int cantPedidos=0;

	
	listaPedidos(){ 
		primerNodo = NULL;
	}	
	
	void insertarAlInicio (int numPedido, string pcodCliente, Nodo * nodo);
	void insertarAlFinal (int pnumPedido, string pcodCliente, Nodo * nodo);
	nodoPedido * borrarAlInicio ();
	nodoPedido * borrarAlFinal ();
	void imprimir();
	int largo (void);
	void insertarEnPosicion (int pnumPedido, string pcodCliente, Nodo * nodo, int posicion);
	nodoPedido * borrarEnPosicion (int posicion);	
	bool leerPedidos();
}; 
