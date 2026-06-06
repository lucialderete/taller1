/*
*    AUTHOR: Catedra de lenguajes de Taller 1 
*    DATE: 04/2025
*    LICENCE: Creative Commons 
*/

#include "funciones.h"


// DECLARE SUS FUNCIONES ACA
nodo *crearNodo(Producto p);
void InsertarNodo(nodo **Start, nodo *nuevoNodo );
void separarCategoria(nodo **listaHardware, nodo **listaSoftware,  Producto *arreglo, int cantidad);
void actualizarDisponibilidad(nodo *listaSoftware, nodo *listaHardware);
void eliminarProductos(nodo **lista);
void moverExcedentes(nodo **listaSoftware, nodo **listaExcedente);
void mostrarLista(nodo *lista);
void liberarLista(nodo **lista);

int main() 
{    
    int cantidad = 40; //cantidad total de productos

    //inicia las cabeceras de las listas como vacias
    nodo *listaHardware = NULL;
    nodo *listaSoftware = NULL;
    nodo *listaExcedente = NULL;

    //arreglo 
    Producto * TodosLosProductos  = ProductoElectronicos();
    MostrarProductosDeArreglo(TodosLosProductos, 40, "Productos de Proveedor 1");
    //punto 1
    separarCategoria(&listaHardware, &listaSoftware, TodosLosProductos, cantidad);
    //mostrar listas ordenadas
    printf("---MOSTRAR LISTA SOFTWARE---\n");
    mostrarLista(listaSoftware);
    printf("------------------------------\n");
    printf("---MOSTRAR LISTA hardware---\n");
    mostrarLista(listaHardware);
    printf("------------------------------\n");

    
    

    //punto 2
    actualizarDisponibilidad(listaSoftware, listaHardware);
    printf("eliminar productos inactivos software \n");
    eliminarProductos(&listaSoftware);
    printf("eliminar productos inactivos hardware \n");
    eliminarProductos(&listaHardware);
    moverExcedentes(&listaSoftware, &listaExcedente);

   
   
    liberarLista(&listaExcedente);
    liberarLista(&listaSoftware);
    liberarLista(&listaHardware);
    free(TodosLosProductos);
    /*fin del programa*/
    printf("\nFin programa\n"); 
    return 0;
}

// IMPLEMENTE SUS FUNCIONES ACA
nodo *crearNodo(Producto p){
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo -> Producto = p;
    nuevoNodo ->Siguiente= NULL;
    return nuevoNodo;
}

void InsertarNodo(nodo **Start, nodo *nuevoNodo ){
    nuevoNodo -> Siguiente = *Start;
    *Start = nuevoNodo; 
}

//punto 1
void separarCategoria(nodo **listaHardware, nodo **listaSoftware, Producto *arreglo, int cantidad){
    for(int i=0; i<cantidad; i++){
        nodo *nuevo = crearNodo(arreglo[i]);
        if(strcmp(arreglo[i].Categoria, "Software")==0){
            InsertarNodo(listaSoftware, nuevo);
        }else if(strcmp(arreglo[i].Categoria, "Hardware")==0){
            InsertarNodo(listaHardware, nuevo);
        }
    }
}

//punto 2
void actualizarDisponibilidad(nodo *listaSoftware, nodo *listaHardware){
    int continuar=1;
   
    while(continuar != 0){
        int idIngresado;
        int encontrado =0;
        printf("Ingrese el id del producto que desea actualizar la disponibilidad: ");
        scanf("%d", &idIngresado);

        nodo *aux = listaSoftware;
        while(aux != NULL){
            if(aux ->Producto.Id == idIngresado){
                aux -> Producto.Activo = 0;
                printf("estado del producto: %s desactivado\n", aux->Producto.Nombre);
                encontrado=1;
                break;
            }
            aux = aux->Siguiente;
        }
        aux = listaHardware;
        while(aux != NULL){
            if(aux -> Producto.Id == idIngresado){
                aux->Producto.Activo = 0;
                printf("estado del producto: %s desactivado\n", aux->Producto.Nombre);
                encontrado=1;
            }
            aux = aux->Siguiente;

        }
        if(encontrado == 0){
            printf("no se encontraron productos con ese id\n");
        }
        printf("desea cambiar la disponibilidad de otro producto?\n");
        printf("1: continuar || 0=terminar");
        scanf("%d", &continuar);
    }
}

//punto 3
void eliminarProductos(nodo **lista){
    
    nodo *aux =*lista;
    nodo *anterior = NULL;
    while(aux != NULL){
        if(aux -> Producto.Activo == 0){
            nodo *eliminar = aux;
            if(anterior == NULL){
                *lista = aux->Siguiente; //si era el primero de la lista mueve la cabecera
            }else{
                anterior -> Siguiente = aux -> Siguiente;
            }
            
            aux = aux -> Siguiente;//avanza al siguiente
            free(eliminar->Producto.Nombre);
            free(eliminar->Producto.Categoria);
            free(eliminar);
            
        }else{
            anterior = aux;
            aux = aux->Siguiente;
        }
    }

}

void moverExcedentes(nodo **listaSoftware, nodo **listaExcedente){
    printf("---verificar si hay excedentes---\n");
    int cantidadMax=50;
    int suma =0;
    nodo *aux = *listaSoftware;
    nodo *anterior = NULL;
    while(aux != NULL){
        suma += aux -> Producto.Stock; //suma el stock
        if(suma > cantidadMax){ //si la suma es mayor a la cantidad maxima
            if(anterior == NULL){ //si el primero de la lista supero la cantidad maxima se mueve la lista completa a la lista excedente
                *listaExcedente = *listaSoftware;
                *listaSoftware = NULL;//la lista de soft queda vacia
            }
            else{//si desde aux hasta el final pasa a ser excedente
                anterior ->Siguiente = NULL;
                *listaExcedente = aux;
            }
            printf("los excedentes se movieron a otra lista. el stock de software quedo en: %d productos", suma-(aux ->Producto.Stock));
            break;
        }
        anterior = aux;
        aux = aux->Siguiente;
    }
}

//libera la memoria de las listas, recordar que nombre y categoria son arreglos
void liberarLista(nodo **lista){
    nodo *aux = *lista;
    nodo *temp;
    while(aux != NULL){
        temp = aux -> Siguiente;
        free(aux -> Producto.Nombre);
        free(aux-> Producto.Categoria);
        free(aux);
        aux = temp;
    }
    *lista = NULL;
}

//muestra la lista xd
void mostrarLista(nodo *lista){
    nodo *aux = lista;
    while(aux != NULL){
        printf("%2d - %-10s | %-40s | $%7.2f | Stock: %2d | Activo: %d\n",
        aux->Producto.Id,
        aux->Producto.Categoria,
        aux->Producto.Nombre,
        aux->Producto.Precio,
        aux->Producto.Stock,
        aux->Producto.Activo);
        aux = aux->Siguiente;
    }
}