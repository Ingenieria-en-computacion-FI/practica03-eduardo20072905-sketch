#ifndef FRACCION_H
#define FRACCION_H

typedef struct{
    int num;
    int den;
} Fraccion;

Fraccion* crearFraccion(int num, int den);
void simplificarFraccion(Fraccion* f);
Fraccion* sumarFraccion(Fraccion *f1, Fraccion *f2);
void imprimirFraccion(Fraccion *f);
void destruirFraccion(Fraccion *f);

#endif 
