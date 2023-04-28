////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include <cstdlib>
#include <iostream>
using namespace std;

// Prototipos de estructuras
// es la declaracion de estas estructuras
struct Nodo;
struct ListaSimple;


// estructura nodo para lista simple
struct Nodo {
		string codigo; // parte de codigos
		int cantidad;
		Nodo* siguiente;// puntero para enlazar nodos
		// constructor
		Nodo(string d, int pcantidad) {
			codigo = d; // asigna los codigos
			cantidad= pcantidad;
			siguiente = NULL; // sig es null       
		}
		// constructor
		Nodo(string d, int pcantidad,Nodo * _siguiente)  {
			codigo = d; // asigna los codigos
			cantidad = pcantidad;
			siguiente = _siguiente; // sig es null       
		}
};

struct ListaSimple {
       // solo con pN es suficiente
       Nodo *primerNodo, *ultimoNodo;
       // constructor
       ListaSimple()
       {
           primerNodo = ultimoNodo = NULL;
       }
       
       // funciones
    void insertarAlInicio (string codigo, int cantidad);
	void insertarAlFinal (string codigo, int cantidad);
	Nodo * borrarAlInicio ();
	Nodo * borrarAlFinal ();
	void imprimir();
	int largo (void);
	bool esta(string nom);
	void insertarEnPosicion (string codigo, int cantidad, int posicion);
	Nodo * borrarEnPosicion (int posicion);
};

