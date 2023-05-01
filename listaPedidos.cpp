////// JOSE JULIAN BRENES GARRO y ALEJANDRO PACHECO SANCHEZ
////// ESTRUCTURAS DE DATOS
////// I SEMESTRE 2023

#include "nodoPedido.h"
#include "listaPedidos.h"


void listaPedidos::insertarAlInicio (int pnumPedido, string pcodCliente, Nodo * nodo)
    {
            // si no hay elementos
       if (primerNodo == NULL)
       {
        // ambos apuntan al nuevo en memoria
         primerNodo = new nodoPedido(pnumPedido, pcodCliente, nodo);
         ultimoNodo = primerNodo; 
         // ambos apuntan al nuevo               
       }
       else{
         nodoPedido *nuevo = new nodoPedido(pnumPedido, pcodCliente, nodo);
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

void listaPedidos::insertarAlFinal (int pnumPedido, string pcodCliente, Nodo * nodo){
	  	if (primerNodo == NULL){
	  		primerNodo = ultimoNodo = new nodoPedido(pnumPedido, pcodCliente, nodo);
		}
		else{
			nodoPedido * temp = primerNodo;
			while (temp->siguiente!=NULL){
				temp = temp->siguiente;
			}
			temp->siguiente = new nodoPedido(pnumPedido, pcodCliente, nodo);
		}
}

nodoPedido * listaPedidos::borrarAlInicio (){
	nodoPedido * temp = primerNodo;
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

nodoPedido * listaPedidos::borrarAlFinal (){
	nodoPedido * temp = primerNodo;
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

void listaPedidos::imprimir(){
	nodoPedido * tmp = primerNodo;
	while(tmp != NULL){
		// aqu� programar lo que necesiten en cada iteraci�n
		cout<<"Pedido: "<<tmp->numPedido<<endl;
		cout<<"Codigo: "<<tmp->codCliente<<endl;
		tmp->imprimir();
		tmp = tmp->siguiente;
	}
	cout<<endl;
}

int listaPedidos::largo (void){
	  nodoPedido * temp = primerNodo;
	  int contador = 0;
	  while (temp!=NULL){
	    contador++;
	    temp= temp->siguiente;
	  }
	return contador;
}
   
void listaPedidos::insertarEnPosicion (int pnumPedido, string pcodCliente, Nodo * nodo, int posicion){
	if (posicion==0){
		insertarAlInicio (pnumPedido, pcodCliente, nodo);
	   }
	else{
		nodoPedido * temp = primerNodo;
		int contador=1;
		while(temp!=NULL){
			if (contador==posicion){
				nodoPedido * nodoNuevo = new nodoPedido(pnumPedido, pcodCliente, nodo);
				temp->siguiente = nodoNuevo;
				return;
			}
			temp=temp->siguiente;
			contador++;
		}
		insertarAlFinal (pnumPedido, pcodCliente, nodo);
	}
}
   
nodoPedido * listaPedidos::borrarEnPosicion (int posicion){
	if (posicion==0){
		borrarAlInicio();
	}
	else{
		nodoPedido * temp = primerNodo;
		int contador=1;
		while(temp!=NULL){
			if (contador==posicion){
				nodoPedido * nodoBorrado = temp->siguiente;
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

void moverCarpeta(string carpetaDestino, string nombreArchivo){
    string rutaOrigen = "Pedidos/" + nombreArchivo;
    string rutaDestino = carpetaDestino + nombreArchivo;

    if (rename(rutaOrigen.c_str(), rutaDestino.c_str()) != 0) {
        cout << "Error al mover archivo." << endl;
    }
    else {
        cout << "Archivo movido correctamente." << endl;
    }
}

bool endsWith(const string& str, const string& suffix) {
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool listaPedidos::leerPedidos(listaClientes &pclientes, listaArticulo &particulos) {
    string carpeta = "Pedidos/";
    DIR* dir;
    
    string auxNameFile;
    struct dirent* ent;
    if ((dir = opendir(carpeta.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string filename(ent->d_name);
            auxNameFile = filename;
            
            bool bandera = true;
            int pnumPedido;
			string pcodCliente;
			ListaSimple lista;
			nodoCliente * tempCliente;
			
            if (endsWith(filename, ".txt")) {
                string path = carpeta + filename;
                ifstream archivo(path.c_str());
                string linea;

                getline(archivo, linea); // Leer linea
                pnumPedido = stoi(linea);

                getline(archivo, linea);
                pcodCliente = linea;
                tempCliente = pclientes.buscar(pcodCliente);
                
                if (tempCliente==NULL){
                	bandera = false;
                	break;
				}

                while (getline(archivo, linea)) {
                    stringstream ss(linea);
                    string pcodigo;
                    int pcantidad;
                    ss >> pcodigo >> pcantidad;
                    if (lista.buscar(pcodigo)==NULL){
                    	lista.insertarAlFinal(pcodigo, pcantidad);
					}
					else{
						bandera = false;
						cout<<"wiiii"<<endl;
						break;
					}
                }
            }
            if (bandera){
            	if (tempCliente->prioridad==10)
            		insertarAlInicio(pnumPedido, pcodCliente, lista.primerNodo);
                else	
					insertarAlFinal(pnumPedido, pcodCliente, lista.primerNodo);
				moverCarpeta("Revisados/", auxNameFile);
			}
			else{
				moverCarpeta("Errores/", auxNameFile);
				
			}
        }
        closedir(dir);
    }
    else {
        perror("No se pudo abrir la carpeta.");
        return false;
    }
    return true;
}
