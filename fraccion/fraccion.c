#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

int mcd(int a, int b){
    if(b==0)
        return a;
    return mcd(b, a%b);
}

void simplificarFraccion(Fraccion *f){
    int d = mcd(f->num, f->den);

    f->num = f->num / d;
    f->den = f->den / d;

    if(f->den < 0){      // mantener signo en numerador
        f->den = -f->den;
        f->num = -f->num;
    }
}

Fraccion* crearFraccion(int num, int den){
    if(den == 0){
        printf("Error: denominador no puede ser 0\n");
        return NULL;
    }

    Fraccion *f = (Fraccion*) malloc(sizeof(Fraccion));
    f->num = num;
    f->den = den;
    simplificarFraccion(f);
    return f;
}

Fraccion* sumarFraccion(Fraccion *f1, Fraccion *f2){
    int num = f1->num * f2->den + f2->num * f1->den;
    int den = f1->den * f2->den;
    return crearFraccion(num, den);
}

void imprimirFraccion(Fraccion *f){
    printf("%d/%d\n", f->num, f->den);
}

void destruirFraccion(Fraccion *f){
    free(f);
}
