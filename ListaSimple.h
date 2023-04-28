////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SÁNCHEZ
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
       string dato; // parte de datos
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor
       Nodo(string d) {
         dato = d; // asigna los datos
         siguiente = NULL; // sig es null       
       }
       // constructor
       Nodo(string d, Nodo * _siguiente)  {
         dato = d; // asigna los datos
         siguiente = _siguiente; // sig es null       
       }
       void imprimir()
       { 
	   		cout << "|" << dato << "| -> " ;
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
    void insertarAlInicio (string dato);
	void insertarAlFinal (string dato);
	Nodo * borrarAlInicio ();
	Nodo * borrarAlFinal ();
	void imprimir();
	int largo (void);
	bool esta(string nom);
	void insertarEnPosicion (string dato, int posicion);
	Nodo * borrarEnPosicion (int posicion);
};

