// codigo a completar
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20
int main()
{
    int i;
    double vt[N];
    double *punt = vt;
    
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        *(punt + i)= 1 + rand() % 100;
        printf("\n%.2f", *(punt + i));
    }
      
}
