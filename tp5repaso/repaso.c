#include "funciones.h"

//funciones 
//modificar lista -> puntero doble
//leer la lista con puntero simple

nodo *crearListaVacia();
void insertarEnLista(nodo **lista, nodo *nodoNuevo);


int main(){
    nodo *listaHardware = crearListaVacia();
    nodo *listaSoftware = crearListaVacia();
    
    Producto *TodosLosProductos = ProductosElectronicos();
    return 0;
}

nodo *crearListaVacia(){
    return NULL;
}

void insertarInicio(nodo **Start, nodo *nodoNuevo){
    nodoNuevo -> Siguiente = *Start;
    *Start = nodoNuevo;

}