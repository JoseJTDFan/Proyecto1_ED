////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023
#pragma once
#include <cstdlib>
#include <iostream>
#include "ListaSimple.h"

using namespace std;

struct nodoPedido;


// estructura nodo y lista de componentes
struct nodoPedido {
    int numPedido;
    string codCliente;
    Nodo * primerNodo, *ultimoNodo;
    nodoPedido * siguiente;
       // constructor
   	nodoPedido(int pnumPedido, string pcodCliente) {
        numPedido = pnumPedido; // asigna los datos
        codCliente = pcodCliente;
        primerNodo = ultimoNodo = NULL;
        siguiente = NULL; // sig es null       
   	}
   	
    nodoPedido(int pnumPedido, string pcodCliente, Nodo * nodo) {
        numPedido = pnumPedido; // asigna los datos
        codCliente = pcodCliente;
        primerNodo = ultimoNodo = nodo;
        siguiente = NULL; // sig es null       
   	}
   	
	void insertarAlInicio (string pcodigo, int pcantidad);
	void insertarAlFinal (string pcodigo, int pcantidad);
	Nodo * borrarAlInicio ();
	Nodo * borrarAlFinal ();
	void imprimir();
	int largo (void);
	bool esta(string nom);
	void insertarEnPosicion (string pcodigo, int pcantidad, int posicion);
	Nodo * borrarEnPosicion (int posicion);	
};
