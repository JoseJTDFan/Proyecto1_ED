////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SÁNCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include "ListaSimple.h"

void ListaSimple::insertarAlInicio (string dato)
    {
            // si no hay elementos
       if (primerNodo == NULL)
       {
        // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(dato);
         ultimoNodo = primerNodo; 
         // ambos apuntan al nuevo               
       }
       else{
         Nodo *nuevo = new Nodo(dato);
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

void ListaSimple::insertarAlFinal (string dato){
	  	if (primerNodo == NULL){
	  		primerNodo = ultimoNodo = new Nodo(dato);
		}
		else{
			Nodo * temp = primerNodo;
			while (temp->siguiente!=NULL){
				temp = temp->siguiente;
			}
			temp->siguiente = new Nodo(dato);
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
		// aquï¿½ programar lo que necesiten en cada iteraciï¿½n
		tmp->imprimir();
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

//retorna true si el dato del argumento estï¿½ en la lista
bool ListaSimple::esta(string nom){
	Nodo * temp = primerNodo;
	while (temp!=NULL){
		if (nom==temp->dato){
			return true;
		   }
		temp = temp-> siguiente;
	   }
	return false;
}
   
void ListaSimple::insertarEnPosicion (string dato, int posicion){
	if (posicion==0){
		insertarAlInicio(dato);
	   }
	else{
		Nodo * temp = primerNodo;
		int contador=1;
		while(temp!=NULL){
			if (contador==posicion){
				Nodo * nodoNuevo = new Nodo(dato,temp->siguiente);
				temp->siguiente = nodoNuevo;
				return;
			}
			temp=temp->siguiente;
			contador++;
		}
		insertarAlFinal(dato);
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
