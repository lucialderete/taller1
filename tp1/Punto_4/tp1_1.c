#include <stdio.h>

int main(){
    int num= 22;
    int *punt = &num;

    printf("1. Contenido del puntero: %d\n", *punt);
    printf("2. Direccion de memoria almacenada por el puntero: %p\n", punt);
    printf("3. Direccion de memoria de la variable: %p\n", &num);
    printf("4. Direccion de memoria del puntero: %p\n", &punt);
    printf("5. Tamaño de la memoria de la variable %zu bytes\n", sizeof(num));
    return 0;
}