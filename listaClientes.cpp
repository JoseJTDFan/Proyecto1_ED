
#include "listaClientes.h"

//insertar cliente a la lista

void listaClientes::imprimir(){
    nodoCliente * tmp = primerNodo; // el nodo no debe ser el clientes? en lugar de el de la lista?
    while(tmp != NULL){
    	cout<<"Codigo: "<<tmp->codigo<<endl;
		cout<<"Nombre: "<<tmp->nombre<<endl;
		cout<<"Prioridad: "<<tmp->prioridad<<endl;
		tmp = tmp->siguiente;
    }
    cout<<endl;
}

void listaClientes::insertar(string codigoCliente,string nombreCliente, int prioridadCliente){
	if (primerNodo == NULL){
		primerNodo = new nodoCliente(codigoCliente, nombreCliente, prioridadCliente);
	}
	else{
		nodoCliente * nuevo = new nodoCliente(codigoCliente, nombreCliente, prioridadCliente);
		nuevo->siguiente = primerNodo;
		primerNodo = nuevo;
	}
}

bool listaClientes::existeClienteEnLista(string pcodigo){
    nodoCliente * nodoActual = primerNodo;
    while (nodoActual != NULL) {
        if (nodoActual->codigo == pcodigo) {
            return true; // El cliente ya existe en la lista
        }
        nodoActual = nodoActual->siguiente;
    }
    return false; // El cliente no existe en la lista
}



bool listaClientes::leerClientes(){

//    no tengo que hacer un new de una lista? y de paso me sirve como el parametro de existe?
    ifstream file("clientes.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string codigoCliente, nombreCliente;
            int prioridad;
            ss >> codigoCliente >> nombreCliente >> prioridad;
            if(existeClienteEnLista(codigoCliente) == false)
            	insertar(codigoCliente, nombreCliente, prioridad);
            else {
                return false;
        	}
		}
	}
	return true;
}
