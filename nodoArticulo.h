////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SÁNCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023
#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

struct nodoArticulo;


// estructura nodo y lista de componentes
struct nodoArticulo {
    string codigo;
    int cantidadAlmacen;
    int tiempoFabricacion;
    string categoria;
    string ubicacion;
    nodoArticulo * siguiente;
    nodoArticulo * anterior;
    // constructor

    nodoArticulo() {
	    codigo = "";
	    cantidadAlmacen = 0;
	    tiempoFabricacion = 0;
	    categoria = "";
	    ubicacion = "";
	    siguiente = NULL;
    	anterior = NULL;
    }
    
    nodoArticulo(string pcodigo, int pcantidadAlmacen, int ptiempoFabricacion, string pcategoria, string pubicacion) {
		codigo = pcodigo;
		cantidadAlmacen = pcantidadAlmacen;
		tiempoFabricacion = ptiempoFabricacion;
		categoria = pcategoria;
		ubicacion = pubicacion;
		siguiente = NULL;
		anterior = NULL;
    }
};
