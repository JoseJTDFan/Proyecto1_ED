#include <cstdlib>
#include <iostream>

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

    nodoCliente(string codigoCliente,string nombreCliente, int prioridadCliente, nodoCliente * _siguiente){
        codigo = codigoCliente;
        nombre = nombreCliente;
        prioridad = prioridadCliente;
    }
};
