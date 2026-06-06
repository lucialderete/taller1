#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//estructuras
typedef struct Tarea {
    int TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
}Nodo;

Nodo *CrearNodo(Tarea T){
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo -> T = T;
    nuevoNodo ->Siguiente= NULL;
    return nuevoNodo;
}


//modulos
void InsertarNodo(Nodo **Start, Nodo *nuevoNodo );
void cargarTarea(Nodo **tareasPendientes, int *id, char buff[]);
void mostrarTarea(Nodo *lista);
void moverTareas(Nodo **tareasPendientes, Nodo **tareasRealizadas, int idTR);
void buscarTareaId(Nodo *tareasPendientes, Nodo *tareasRealizadas, int id, int idBuscar);
void buscarTareaPalabra(Nodo *tareasPendientes, Nodo *tareasRealizadas, char palabra[]);
void liberarLista(Nodo **lista);
//------------------funcion principal
int main(){
    Nodo *tareasRealizadas = NULL;
    Nodo *tareasPendientes = NULL;
    int id = 1000;
    char buff[120];
    char palabra[50];
    int continuar, opcion, idTR, idBuscar; //idTR = id Tareas Realizadas
    printf("Seleccione una opcion:\nAgregar nueva tarea = 1 || No agregar tareas= 0\n:");
    scanf("%d", &continuar);
    //cargar las tareas
    while(continuar == 1){
        cargarTarea(&tareasPendientes, &id, buff);
        printf("Seleccione una opcion");
        printf("1=Agregar nueva tarea || 0=No agregar tareas\n");
        scanf("%d", &continuar);
    }

    printf("--Lista de Tareas Pendientes--\n");
    mostrarTarea(tareasPendientes);

    //transferir tareas
    printf("seleccione el id de las tareas realizadas: \n");
    scanf("%d", &idTR);
    if(idTR > id){
        printf("ingrese un id valido\n");
    }else{
        moverTareas(&tareasPendientes, &tareasRealizadas, idTR);
    }
    
    printf("--Lista de tareas realizadas--");
    mostrarTarea(tareasRealizadas);


    printf("Seleccione una opcion: 1=Buscar por ID || 2=buscar por palabra clave: ");
    scanf("%d", &opcion);
    if(opcion == 1){
        buscarTareaId(tareasPendientes, tareasRealizadas, id, idBuscar);
    }else if(opcion == 2){
        buscarTareaPalabra(tareasPendientes, tareasRealizadas, palabra);
    }else{
        printf("ingrese una opcion valida");
    }

        //liberar memorias
    liberarLista(&tareasPendientes);
    liberarLista(&tareasRealizadas);    

    
    return 0;
}
//desarrollo de los modulos
void InsertarNodo(Nodo **Start, Nodo *nuevoNodo ){
    nuevoNodo -> Siguiente = *Start;
    *Start = nuevoNodo; 
}

void cargarTarea(Nodo **tareasPendientes, int *id, char buff[]){
    Tarea nuevaTarea;
    nuevaTarea.TareaID = *id;
    (*id)++;
    printf("Descripcion: ");
    scanf( " %[^\n]", buff); 
    nuevaTarea.Descripcion = (char *)malloc((strlen(buff)+1)*sizeof(char));
    strcpy(nuevaTarea.Descripcion, buff);
    printf("Duracion: ");
    scanf(" %d", &nuevaTarea.Duracion);
    Nodo *nuevo = CrearNodo(nuevaTarea);
    InsertarNodo(tareasPendientes, nuevo);
}

void mostrarTarea(Nodo *lista){
    Nodo *aux = lista;
    while(aux != NULL){
        printf("ID: %d\n", aux ->T.TareaID);
        printf("Descripcion: %s\n", aux -> T.Descripcion);
        printf("Duracion: %d\n", aux -> T.Duracion);
        aux = aux ->Siguiente;
    }
    if(lista == NULL){
        printf("Es lista vacia\n");
    }
}

void moverTareas(Nodo **tareasPendientes, Nodo **tareasRealizadas, int idTR){
    Nodo *aux = *tareasPendientes;
    Nodo *anterior = NULL;
    while(aux != NULL){
        if(aux->T.TareaID == idTR){
            if(anterior == NULL){
                *tareasPendientes = aux->Siguiente;
            }else{
                anterior->Siguiente = aux->Siguiente;
            }
            aux->Siguiente = NULL;
            InsertarNodo(tareasRealizadas, aux); 
            break;          

        }else{
            anterior = aux;
            aux = aux->Siguiente;
        }
    }
}

void buscarTareaId(Nodo *tareasPendientes, Nodo *tareasRealizadas, int id, int idBuscar){
    int encontrado =0;
    printf("Ingrese el id que desea buscar: ");
    scanf("%d", &idBuscar);
    Nodo *aux = tareasPendientes;
    while(aux != NULL){
        if(aux->T.TareaID == idBuscar){
            printf("Tarea Encontrada (Estado: pendiente)\n");
            printf("Descripcion: %s\n", aux->T.Descripcion);
            printf("Duracion: %d\n", aux->T.Duracion);
            encontrado++;
        }
        aux = aux->Siguiente; 
    }
    aux = tareasRealizadas;
    while(aux != NULL){
        if(aux->T.TareaID == idBuscar){
            printf("Tarea Encontrada (Estado: realizada)\n");
             printf("Descripcion: %s\n", aux->T.Descripcion);
            printf("Duracion: %d\n", aux->T.Duracion);
            encontrado++;
        }
        aux = aux->Siguiente; 
    }
    if(encontrado ==0){
            printf("no se hay ninguna tarea con ese ID.\n");
    }
    

}

void buscarTareaPalabra(Nodo *tareasPendientes, Nodo *tareasRealizadas, char palabra[]){
    int encontrado=0;
    printf("Ingrese la palabra que desea buscar: ");
    scanf(" %[^\n]", palabra);
    Nodo *aux = tareasPendientes;
    while(aux != NULL){
        if(strstr(aux->T.Descripcion, palabra) != NULL ){
            printf("Tarea Encontrada (Estado: pendiente)\n");
            printf("ID: %d\n", aux->T.TareaID);
            printf("Descripcion: %s\n", aux->T.Descripcion);
            printf("Duracion: %d\n", aux->T.Duracion);
        }
        aux = aux->Siguiente; 
    }
    aux = tareasRealizadas;
    while(aux != NULL){
        if(strstr(aux->T.Descripcion, palabra) != NULL ){
            printf("Tarea Encontrada (Estado: realizada)\n");
            printf("ID: %d\n", aux->T.TareaID);
            printf("Descripcion: %s\n", aux->T.Descripcion);
            printf("Duracion: %d\n", aux->T.Duracion);
        } 
        aux = aux->Siguiente;
    }
    if(encontrado ==0){
        printf("no se encontro ninguna tarea con esa palabra");
    }
   
}

void liberarLista(Nodo **lista){
    Nodo *aux = *lista;
    Nodo *temp;
    while(aux != NULL){
        temp = aux -> Siguiente;
        free(aux -> T.Descripcion);
        free(aux);
        aux = temp;
    }
    *lista = NULL;
}