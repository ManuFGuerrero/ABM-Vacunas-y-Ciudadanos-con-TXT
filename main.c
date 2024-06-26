#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define TAM 5
#include "vacuna.h"
#include "ciudadano.h"

/*Crear un programa que permita administrar las 5 posibles dosis
de un ciudadano vacunado contra el COVID-19. Para realizar este
ejercicio se pide que se utilice fuertemente punteros y se
respeten las siguientes estructuras y funciones y procedimientos:

*/
int main()
{
srand (time(0));

Ciu c1=cargarCiudadano();

agregarVacuna(c1);
agregarVacuna(c1);

mostrarCiudadano(c1);

//eliminarVacuna(c1,"v1");
agregarVacuna(c1);
agregarVacuna(c1);
agregarVacuna(c1);
mostrarCiudadano(c1);

agregarVacuna(c1);
char vacunaABuscar[20];
printf("\nQue vacuna desea buscar?\n");
fflush(stdin);
gets(vacunaABuscar);

contarVacuna(c1,vacunaABuscar);

printf("\n\n\n%d",getCodigoC(c1));
    return 0;
}
