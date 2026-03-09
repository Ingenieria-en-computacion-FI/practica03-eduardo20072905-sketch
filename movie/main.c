#include <stdio.h>
#include "pelicula.h"

int main()
{

    printf("Prueba del TAD Pelicula\n");

   Pelicula* p = crearPelicula("Titanic", 1997, "Drama");

  


   if(p == NULL)
        return 1;

    agregarDirector(p,"Wachowski");

    imprimir(p);

    printf("\nCambiar genero\n");

    cambiarGenero(p,"Accion");

   imprimir(p);

    destruir(p);

    return 0;
}

