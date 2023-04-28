////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SÁNCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023
#include "listaArticulo.h"
#include "ListaSimple.h"


// INSERTAR AL INICIO
void listaArticulo::insertar(string pcodigo, int pcantidadAlmacen, int ptiempoFabricacion, string pcategoria, string pubicacion)
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
			cout << tmp->codigo << " - " << tmp->cantidadAlmacen << " - " << tmp->tiempoFabricacion << " - " << tmp->categoria;
			cout<< " - " << tmp->ubicacion<<endl;
			tmp = tmp->siguiente;
		}while(tmp!=primerNodo);
	}
}

nodoArticulo * listaArticulo::buscar(string pcodigo)
{
	if (primerNodo != NULL){
		
		nodoArticulo * tmp = primerNodo;
		do{
			if (tmp->codigo == pcodigo)
				return tmp;
			tmp = tmp->siguiente;
		}while(tmp!=primerNodo);
	}
	return NULL;
}

nodoArticulo * listaArticulo::eliminar(string pcodigo){
	nodoArticulo * eliminado = buscar(pcodigo);
	
	if (eliminado != NULL){ // sí lo encontró
		if (primerNodo->siguiente == primerNodo) // solo un elemento
			eliminado->siguiente = eliminado->anterior = NULL;
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

void listaArticulo::leerArticulo(){
 	ifstream file("Articulos.txt");
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            stringstream ss(line);
            string codigo, categoria, ubicacion;
            int cantidadAlmacen, tiempoFabricacion;
            ss >> codigo >> cantidadAlmacen >> tiempoFabricacion >> categoria >> ubicacion;
            insertar(codigo,cantidadAlmacen,tiempoFabricacion,categoria,ubicacion);
            // Aquí puedes hacer lo que quieras con los valores leídos
        }
    } else {
        cerr << "No se pudo abrir el archivo." << std::endl;
    }
}
