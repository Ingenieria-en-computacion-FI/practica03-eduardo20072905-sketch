#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo {

    int valor;
  
};

Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // Asignar memoria para un nuevo nodo
    if (nuevoNodo != NULL) {// Verificar que la asignación de memoria fue exitosa
        nuevoNodo->valor = valor;// Inicializar el valor del nodo
    }

    return nuevoNodo;// Devolver el puntero al nuevo nodo
}

int obtenerValor(Nodo* nodo) {
    if (nodo == NULL) {
        return -1; // Manejo de error: nodo nulo
    }
    return nodo->valor; // Devolver el valor almacenado en el nodo
}

void asignarValor(Nodo* nodo, int valor) {
    if (nodo != NULL) { // Verificar que el nodo no sea nulo
        nodo->valor = valor; // Asignar el nuevo valor al nodo
    }
}

void destruirNodo(Nodo* nodo) {
    if (nodo != NULL) {// Verificar que el nodo no sea nulo antes de intentar liberarloc
        free(nodo); // Liberar la memoria ocupada por el nodo
    }
}
