
#include "listaClientes.h"

//insertar cliente a la lista

void listaClientes::imprimir(){
    Nodo * tmp = primerNodo; // el nodo no debe ser el clientes? en lugar de el de la lista?
    while(tmp != NULL){
        // aqui programar lo que necesiten en cada iteracion
        tmp->imprimir();
        tmp = tmp->siguiente;
    }
    cout<<endl;
}

void listaClientes::insertar(string codigoCliente,string nombreCliente, int prioridadCliente){}
if (primerNodo == NULL){
primerNodo = new nodoCliente(string codigoCliente,string nombreCliente, int prioridadCliente);
}
else{
nodoCliente * nuevo = new nodoCliente(string codigoCliente,string nombreCliente, int prioridadCliente);
nuevo->siguiente = primerNodo;
primerNodo = nuevo;
}

bool listaClientes::existeClienteEnLista(listaClientes  * listaDeClientes, string codigo) {
    NodoCliente* nodoActual = listaDeCliente->siguiente;
    while (nodoActual != NULL) {
        if (nodoActual->codigo == codigo) {
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
            if(*cliente existe* == false)
            insertar(codigoCliente, nombreCliente, prioridad);
            else {
                return false
                else{
                    return false;
                }
            }

