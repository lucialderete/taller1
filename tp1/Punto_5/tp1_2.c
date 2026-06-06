#include <stdio.h>

// 5a) Haga una función que devuelva el cuadrado de un número
int cuadrado_Numero(int num)
{
    int cuad;
    cuad = num * num;
    return cuad;
}

// 5b) Haga la función anterior, pero devolviendo un tipo void

void cuadradoNumero(int *num)
{
    *num = (*num) * (*num);
}

// 5c) Al recibir una variable muestre por pantalla la dirección y el contenido de la variable
void mostrarDireccionContenido(int *num)
{
    printf("\nDireccion de la variable: %p", num);
    printf("\nContenido de la variable: %d", *num);
}
// 5d) Al recibir una variable muestre por pantalla la dirección y el contenido de la variable
void Invertir(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// 5e) Dado dos parámetros de entrada, deberá devolverlos de forma ordenada, en el primer parámetro el menor y en el segundo el mayor.
void orden(int *a, int *b)
{
    int aux = 0;
    if (*a > *b)
    {
        int aux = *a;
        *a = *b;
        *b = aux;
    }
}

int main()
{
    int valor, cuadrado, num1, num2;
    // 5a)
    printf("Ingrese un numero entero: ");
    scanf("%d", &valor);
    cuadrado = cuadrado_Numero(valor);
    printf("\nEl cuadrado de %d es %d \n ", valor, cuadrado);

    // 5b)
    cuadradoNumero(&valor);
    printf("El cuadrado del numero ingresado es %d", valor);

    // 5c)
    mostrarDireccionContenido(&valor);

    // 5d)
    printf("\n\nIngrese un par de numeros: ");
    scanf("%d %d", &num1, &num2);
    Invertir(&num1, &num2);
    printf("\nSe invirtieron los numeros");
    printf("num1= %d y num2= %d", num1, num2);

    // 5e)
    printf("\n\nIngrese un par de numeros enteros: ");
    scanf("%d %d", &num1, &num2);
    orden(&num1, &num2);
    printf("\nPar de numeros ordenados: num1:menor, num2: mayor ");
    printf("\nnum1= %d, num2=%d", num1, num2);

    //5f)
    printf("\n\nIngrese un par de numeros enteros: ");
    scanf("%d %d", &num1, &num2);
    printf("\nNumeros ingresados: num1=%d, num2= %d", num1, num2);
    Invertir(&num1, &num2);
    printf("\nNumeros invertidos: num1= %d, num2= %d", num1, num2 );
    orden(&num1, &num2);
    printf("\nNumeros ordenados: num1(mayor)=%d , num2(menor)=%d", num1, num2);



    return 0;
}