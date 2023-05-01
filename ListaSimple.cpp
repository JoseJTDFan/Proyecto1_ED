////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include "ListaSimple.h"

void ListaSimple::insertarAlInicio (string codigo, int cantidad)
    {
            // si no hay elementos
       if (primerNodo == NULL)
       {
        // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(codigo, cantidad);
         ultimoNodo = primerNodo; 
         // ambos apuntan al nuevo               
       }
       else{
         Nodo *nuevo = new Nodo(codigo, cantidad);
  		// a lo que apunta pN ahora es el segundo
		// por eso, nuevo->siguiente es pN
         nuevo->siguiente = primerNodo;
		// ahora devolvemos pN a que apunte al nuevo
		// y primero de las lista
         primerNodo = nuevo; 
		// el puntero nuevo deja de existir, no se 
		//libera memoria porque se pierde la info
      }            
}// fin metodo

void ListaSimple::insertarAlFinal (string codigo, int cantidad){
	  	if (primerNodo == NULL){
	  		primerNodo = ultimoNodo = new Nodo(codigo, cantidad);
		}
		else{
			Nodo * temp = primerNodo;
			while (temp->siguiente!=NULL){
				temp = temp->siguiente;
			}
			temp->siguiente = new Nodo(codigo, cantidad);
		}
}

Nodo * ListaSimple::borrarAlInicio (){
	Nodo * temp = primerNodo;
	if (primerNodo==NULL){
		return NULL;
	}
	else if(primerNodo->siguiente==NULL){
		primerNodo = ultimoNodo = NULL;
	}
	else{
		primerNodo=temp->siguiente;
	}
	return temp;
}

Nodo * ListaSimple::borrarAlFinal (){
	Nodo * temp = primerNodo;
	if (primerNodo==NULL){
		return NULL;
	}
	else if (primerNodo==ultimoNodo){
		primerNodo = ultimoNodo = NULL;
		return temp;
	}
	else {
		while (temp->siguiente->siguiente!=NULL){
			temp= temp->siguiente;
		}
		ultimoNodo= temp;
		temp = temp->siguiente;
		ultimoNodo -> siguiente = NULL;
		return temp;
	}
}

void ListaSimple::imprimir(){
	Nodo * tmp = primerNodo;
	while(tmp != NULL){
		// aqu� programar lo que necesiten en cada iteraci�n
		cout<<"		Articulo: "<<tmp->codigo<<" - Cantidad: "<<tmp->cantidad<<endl;
		tmp = tmp->siguiente;
	}
	cout<<endl;
}

int ListaSimple::largo (void){
	  Nodo * temp = primerNodo;
	  int contador = 0;
	  while (temp!=NULL){
	    contador++;
	    temp= temp->siguiente;
	  }
	return contador;
}

//retorna true si el codigo del argumento esta en la lista
Nodo * ListaSimple::buscar(string nom){
	Nodo * temp = primerNodo;
	while (temp!=NULL){
		if (nom==temp->codigo){
			return temp;
		   }
		temp = temp-> siguiente;
	   }
	return NULL;
}
   
void ListaSimple::insertarEnPosicion (string codigo, int cantidad, int posicion){
	if (posicion==0){
		insertarAlInicio (codigo,cantidad);
	   }
	else{
		Nodo * temp = primerNodo;
		int contador=1;
		while(temp!=NULL){
			if (contador==posicion){
				Nodo * nodoNuevo = new Nodo(codigo, cantidad,temp->siguiente);
				temp->siguiente = nodoNuevo;
				return;
			}
			temp=temp->siguiente;
			contador++;
		}
		insertarAlFinal (codigo,cantidad);
	}
}
   
Nodo * ListaSimple::borrarEnPosicion (int posicion){
	if (posicion==0){
		borrarAlInicio();
	}
	else{
		Nodo * temp = primerNodo;
		int contador=1;
		while(temp!=NULL){
			if (contador==posicion){
				Nodo * nodoBorrado = temp->siguiente;
				temp->siguiente= temp->siguiente->siguiente;
				nodoBorrado->siguiente = NULL;
				return nodoBorrado;
			}
			temp=temp->siguiente;
			contador++;
		}
		return borrarAlFinal();
	}
}
