#include <stdio.h>
#include "fraccion.h"

int main(){

    Fraccion *f1 = crearFraccion(2,4);
    Fraccion *f2 = crearFraccion(3,6);

    Fraccion *resultado = sumarFraccion(f1,f2);

    imprimirFraccion(f1);
    imprimirFraccion(f2);
    imprimirFraccion(resultado);

    destruirFraccion(f1);
    destruirFraccion(f2);
    destruirFraccion(resultado);

    return 0;
}
