#include <cstdlib>
#include <iostream>
#include "nodoCliente.h"
#include <fstream>
#include <sstream>


using namespace std;

struct listaClientes;

struct listaClientes{
    nodoCliente * primerNodo;


    listaClientes(){
        primerNodo = NULL;
    }

    void insertar(string codigoCliente,string nombreCliente, int prioridadCliente);
    void imprimir();
    nodoCliente * eliminar;
	bool existeClienteEnLista(string pcodigo);
	bool leerClientes();
};


