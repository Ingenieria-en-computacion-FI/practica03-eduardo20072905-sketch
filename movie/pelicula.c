#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"



/* Función auxiliar para copiar cadenas usando malloc + strcpy */
char* copiarCadena(const char* texto)
{
    if (texto == NULL) {
        return NULL;
    }
    // Reservar memoria para la copia (incluyendo el carácter nulo)
    char* copia = (char*)malloc(strlen(texto) + 1);
    if (copia == NULL) {
        printf("Error: No se pudo asignar memoria para la cadena\n");
        return NULL;
    }
    // Copiar el texto
    strcpy(copia, texto);
    return copia;
}


/* Crear película */
Pelicula* crearPelicula(const char* titulo, int anio, const char* genero)
{
    // 1. Reservar memoria para la estructura Pelicula
    Pelicula* nuevaPelicula = (Pelicula*)malloc(sizeof(Pelicula));
    if (nuevaPelicula == NULL) {
        printf("Error: No se pudo asignar memoria para la película\n");
        return NULL;
    }

    // 2. Copiar título
    nuevaPelicula->titulo = copiarCadena(titulo);
    if (nuevaPelicula->titulo == NULL) {
        free(nuevaPelicula);  // Liberar memoria ya asignada si falla
        return NULL;
    }

    // 3. Copiar género
    nuevaPelicula->genero = copiarCadena(genero);
    if (nuevaPelicula->genero == NULL) {
        free(nuevaPelicula->titulo);  // Liberar título ya copiado
        free(nuevaPelicula);          // Liberar estructura
        return NULL;
    }

    // 4. Inicializar año
    nuevaPelicula->anio = anio;

    // 5. Inicializar contador de directores en 0 y limpiar el arreglo
    nuevaPelicula->numDirectores = 0;
    for (int i = 0; i < MAX_DIRECTORES; i++) {
        nuevaPelicula->directores[i] = NULL;
    }

    // 6. Regresar la película creada
    return nuevaPelicula;
}


/* Imprimir película */
void imprimir(Pelicula* p)
{
    if (p == NULL) {
        printf("Error: La película es NULL\n");
        return;
    }

    printf("Título: %s\n", p->titulo);
    printf("Año: %d\n", p->anio);
    printf("Género: %s\n", p->genero);

    // Imprimir lista de directores
    printf("Directores: ");
    if (p->numDirectores == 0) {
        printf("Sin directores registrados\n");
    } else {
        for (int i = 0; i < p->numDirectores; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%s", p->directores[i]);
        }
        printf("\n");
    }
}


/* Cambiar género */
void cambiarGenero(Pelicula* p, const char* nuevoGenero)
{
    if (p == NULL) {
        printf("Error: La película es NULL\n");
        return;
    }

    // 1. Liberar el género anterior
    free(p->genero);

    // 2. Copiar el nuevo género
    p->genero = copiarCadena(nuevoGenero);
    if (p->genero == NULL) {
        printf("Error: No se pudo actualizar el género\n");
        // En caso de error, se podría restaurar el género anterior, pero aquí solo se reporta
    }
}


/* Agregar director */
void agregarDirector(Pelicula* p, const char* director)
{
    if (p == NULL) {
        printf("Error: La película es NULL\n");
        return;
    }

    // 1. Verificar que no exceda el máximo de directores
    if (p->numDirectores >= MAX_DIRECTORES) {
        printf("Error: No se pueden agregar más directores (máximo %d)\n", MAX_DIRECTORES);
        return;
    }

    // 2. Copiar el nombre del director
    char* copiaDirector = copiarCadena(director);
    if (copiaDirector == NULL) {
        printf("Error: No se pudo agregar el director\n");
        return;
    }

    // 3. Guardarlo en el arreglo
    p->directores[p->numDirectores] = copiaDirector;

    // 4. Incrementar el contador
    p->numDirectores++;
}


/* Liberar memoria */
void destruir(Pelicula* p)
{
    if (p == NULL) {
        return;
    }

    // 1. Liberar título
    free(p->titulo);

    // 2. Liberar género
    free(p->genero);

    // 3. Liberar cada director
    for (int i = 0; i < p->numDirectores; i++) {
        free(p->directores[i]);
    }

    // 4. Liberar la estructura
    free(p);
}
