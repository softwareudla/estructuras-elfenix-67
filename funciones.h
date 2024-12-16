#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_LIBROS 20

struct Libro {
    int id;
    char titulo[101];
    char autor[51];
    int anio;
    char estado[11];
};

void inicializarBiblioteca(struct Libro biblioteca[], int *contador);
void convertirMinusculas(char *cadena);
int validarEstado(char *estado);
int esTextoValido(const char *cadena);
void leerCadenaTexto(const char *mensaje, char *cadena, int tamano);
int leerNumero(const char *mensaje);
void leerCadena(const char *mensaje, char *cadena, int tamano);
int agregarLibro(struct Libro biblioteca[], int *contador);
void mostrarLibros(struct Libro biblioteca[], int contador);
void buscarLibro(struct Libro biblioteca[], int contador);
void actualizarEstado(struct Libro biblioteca[], int contador);
void eliminarLibro(struct Libro biblioteca[], int *contador);

#endif
