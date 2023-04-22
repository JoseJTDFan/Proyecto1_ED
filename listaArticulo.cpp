

#include "listaArticulo.h"


// INSERTAR AL INICIO
void listaArticulo::insertar(string pcodigo, int pcantidadAlmacen, int ptiempoFabricacion, char pcategoria, string pubicacion)
{
	if (primerNodo == NULL){
	
		primerNodo = new nodoArticulo(pcodigo, pcantidadAlmacen, ptiempoFabricacion, pcategoria, pubicacion);
		primerNodo->siguiente= primerNodo;
		primerNodo->anterior = primerNodo;
	}
	else{
		nodoArticulo * nuevo = new nodoArticulo(pcodigo, pcantidadAlmacen, ptiempoFabricacion, pcategoria, pubicacion);
		nuevo->siguiente = primerNodo;
		nuevo->anterior = primerNodo->anterior;
		primerNodo->anterior->siguiente = nuevo;
		primerNodo->anterior = nuevo;
	}
}

// IMPRIMIR LISTA
void listaArticulo::imprimir()
{
	if (primerNodo != NULL){
		
		nodoArticulo * tmp = primerNodo;
		do{
			cout << tmp->codigo << endl;
			tmp = tmp->siguiente;
		}while(tmp!=primerNodo);
	}
}

	// IMPRIMIR LISTA
nodoArticulo * listaArticulo::buscar(int pcodigo)
{
	if (primerNodo != NULL){
		
		nodoArticulo * tmp = primerNodo;
		do{
			if (tmp->codigo == codigo)
				return tmp;
			tmp = tmp->siguiente;
		}while(tmp!=primerNodo);
	}
	return NULL;
}

nodoArticulo * listaArticulo::eliminar(int pcodigo){
	Nodo * eliminado = busca(pcodigo);
	
	if (eliminado != null){ // sí lo encontró
		if (primerNodo->siguiente == primerNodo) // solo un elemento
			elmininado->siguiente = eliminado->anterior = NULL;
		else{
			if (eliminado == primerNodo)
				primerNodo = primerNodo->siguiente;
			
			nodoArticulo * tmp = eliminado->anterior;
			tmp->siguiente = tmp->siguiente->siguiente;
			eliminado->siguiente->anterior = tmp;
			eliminado->siguiente = eliminado->anterior = NULL;
		} 
	}
	return eliminado;
}

void nodoArticulo::leerArticulo(listaDC &L2,lista &L1, string nombre){
	//Lee el archivo con los pasillos, los mete a una lista y luego lo carga a una lista doble circular con los datos correctos
  	string linea;
	ifstream archivo(nombre.c_str());
	while (!archivo.eof()) { //Cada line del archivo se mete a una lista simple
		getline(archivo, linea);
		L1.InsertarFinal(linea);}
    pnodoL aux=primero; //se crea un nodo en primero de la lista simple
    while(aux!=NULL){ 
		bool flag=true;
    	int temp =aux->valor.length(); //Crea un temp con la cantidad de caracteres que tenga cada linea del nodo
    	string num = "";
    	string nombre = "";
    	string tempNom=aux->valor; //Un temp que tiene la linea
    	for (int i = 0; i < temp; i++){ //Se hace un while con un contador mientras sea menor al temp
    		if (tempNom[i]!=';'){ //Hasta que no se encuentre un ; va a ingresar los caracteres a la variable num
    			if (flag==true){
    				num+=aux->valor[i];}
				else{
					nombre+=aux->valor[i];}}
			else{//Si se encuentra un ;, cambia la bandera a false y se lo salta
				flag=false;}
		}
		if (L2.verificar(stoi(num))==false){//Se verifica que el numero de pasillo no este ya ingresado en la lista
			L2.InsertarFinal(stoi(num), nombre);} //Si no se encontraba lo ingresa en la lista
		aux= aux->siguiente;}
	L1.~lista();}
