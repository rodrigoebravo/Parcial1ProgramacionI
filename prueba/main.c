#include <stdio.h>
#include <stdlib.h>
int funcion(void);
void recibeFuncion(int (*pepe)(void));

int main()
{
    recibeFuncion(funcion);
    return 0;
}

int funcion(void)
{
    return 7;
}
void recibeFuncion(int (*pepe)(void))
{
    printf("puntero desde funcion %p", pepe);
    printf("puntero desde funcion %d", pepe());

}
