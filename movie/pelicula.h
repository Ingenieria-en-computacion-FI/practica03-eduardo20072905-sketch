#ifndef __PELICULA_H__
#define __PELICULA_H__

#define MAX_DIRECTORES 10

struct Pelicula
{
    char* titulo;               // Cadena dinámica para el título
    int anio;                   // Año de estreno
    char* genero;               // Cadena dinámica para el género
    char* directores[MAX_DIRECTORES];  // Arreglo de cadenas dinámicas para directores
    int numDirectores;          // Contador de directores agregados
};

typedef struct Pelicula Pelicula;

// Crear película
Pelicula* crearPelicula(const char* titulo, int anio, const char* genero);

// Imprimir película
void imprimir(Pelicula* p);

// Cambiar género
void cambiarGenero(Pelicula* p, const char* nuevoGenero);

// Agregar director
void agregarDirector(Pelicula* p, const char* director);

// Liberar memoria
void destruir(Pelicula* p);

#endif
