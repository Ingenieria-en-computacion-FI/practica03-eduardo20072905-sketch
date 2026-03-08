#include <stdlib.h>
#include "nodo.h"


int WinMain() {

    printf("Prueba del TAF Nodo\n");

    Nodo* nodo1 = crearNodo(10); // Crear un nuevo nodo con el valor 10
    if (nodo1 == NULL) {
        return -1; // Manejo de error: no se pudo crear el nodo
    }

    printf("Valor del nodo: %d\n", obtenerValor(nodo1)); // Imprimir el valor del nodo

    asignarValor(nodo1, 25); // Asignar un nuevo valor al nodo
    printf("Nuevo valor del nodo: %d\n", obtenerValor(nodo1)); // Imprimir el nuevo valor del nodo

    destruirNodo(nodo1); // Liberar la memoria ocupada por el nodo
    return 0;
}
