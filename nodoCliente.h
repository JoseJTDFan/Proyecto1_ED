#include <cstdlib>
#include <iostream>

using namespace std;

struct nodoCliente{
    string codigo;
    string nombre;
    int prioridad;
    nodoCliente * siguiente;

//    constructor
    nodoCliente(){
        codigo = "";
        nombre = " ";
        prioridad = 0;
        siguiente =  NULL;

    }

    nodoCliente(string codigoCliente,string nombreCliente, int prioridadCliente){
        codigo = codigoCliente;
        nombre = nombreCliente;
        prioridad = prioridadCliente;
    	siguiente =  NULL;
    }
};
