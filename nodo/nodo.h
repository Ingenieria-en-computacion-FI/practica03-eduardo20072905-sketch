#ifndef __NODO_H__
#define __NODO_H__

#include <stdio.h>

struct Nodo {

    int valor;
  
};

typedef struct Nodo Nodo;

Nodo* crearNodo(int valor); //Crear un nuevo nodo con el valor dado

int obtenerValor(Nodo* nodo); //Obtener el valor almacenado en el nodo

void asignarValor(Nodo* nodo, int valor); //Asignar un nuevo valor al nodo

void destruirNodo(Nodo* nodo); //Liberar la memoria ocupada por el nodo


#endif
