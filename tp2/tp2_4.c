#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// estructuras
typedef struct
{
    int velocidad;
    int anio;
    int cant_nucleos;
    char *tipo_cpu;
} compu;

// funciones
void cargarDatosPc(compu pcs[], char tipos[][10], int cantPc);
void listarPCs(compu pcs[], char tipos[][10], int cantPc);
void mostrarMasAntigua(compu pcs[], int cantPc, char tipos[][10]);
void mostrarMasVeloz(compu pcs[], int cantPc, char tipos[][10]);

// funcion principal
int main()
{
    int cantPc = 5;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athion", "Core", "Pentiun"};
    srand(time(NULL));
    compu pcs[cantPc];
    cargarDatosPc(pcs, tipos, cantPc);
    listarPCs(pcs, tipos, cantPc);
    mostrarMasAntigua(pcs, cantPc, tipos);
    mostrarMasVeloz(pcs, cantPc, tipos);

    return 0;
}

void cargarDatosPc(compu pcs[], char tipos[][10], int cantPc)
{
    int indice;
    for (int i = 0; i < cantPc; i++)
    {
        pcs[i].velocidad = 1 + rand() % 3;
        pcs[i].anio = 2015 + rand() % 10;
        pcs[i].cant_nucleos = 1 + rand() % 8;
        indice = rand() % 6;
        pcs[i].tipo_cpu = tipos[indice];
    }
}

void listarPCs(compu pcs[], char tipos[][10], int cantPc)
{
    printf("--lista de computadoras--\n");
    for (int i = 0; i < cantPc; i++)
    {
        printf("Computadora %d: \n", i + 1);
        printf("Velocidad de procesamiento: %d GHz\n", pcs[i].velocidad);
        printf("Anio de fabricacion: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cant_nucleos);
        printf("Tipo de procesador: %s \n", pcs[i].tipo_cpu);
        printf("----------------------\n");
    }
}

void mostrarMasAntigua(compu pcs[], int cantPc, char tipos[][10])
{
    printf("---computadora mas antigua---\n");

    int antigua = 2024;
    int indice=0;
    for (int i = 0; i < cantPc; i++)
    {
        if (pcs[i].anio < antigua)
        {
            antigua = pcs[i].anio;
            indice = i;
        }
    }
    printf("Computadora %d: \n", indice+1);
    printf("Velocidad de procesamiento: %d GHz\n", pcs[indice].velocidad);
    printf("Anio de fabricacion: %d\n", pcs[indice].anio);
    printf("Cantidad de nucleos: %d\n", pcs[indice].cant_nucleos);
    printf("Tipo de procesador: %s \n", pcs[indice].tipo_cpu);
    printf("----------------------\n");
}

void mostrarMasVeloz(compu pcs[], int cantPc, char tipos[][10]){
    printf("--computadora con mayor velocidad de procesamimento---\n");
    int indice=0;
    int veloz = 0;
    for(int i=0; i<cantPc; i++){
        if(pcs[i].velocidad > veloz){
            indice = i;
            veloz = pcs[i].velocidad;
        }
    }
    
    printf("Computadora %d: \n", indice+1);
    printf("Velocidad de procesamiento: %d GHz\n", pcs[indice].velocidad);
    printf("Anio de fabricacion: %d\n", pcs[indice].anio);
    printf("Cantidad de nucleos: %d\n", pcs[indice].cant_nucleos);
    printf("Tipo de procesador: %s \n", pcs[indice].tipo_cpu);
    printf("----------------------\n");

}