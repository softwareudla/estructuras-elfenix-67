#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void inicializarBiblioteca(struct Libro biblioteca[], int *contador) {
    *contador = 0;
}

void convertirMinusculas(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

int validarEstado(char *estado) {
    char estadoCpy[11];
    strncpy(estadoCpy, estado, 11);
    estadoCpy[10] = '\0';
    convertirMinusculas(estadoCpy);
    return strcmp(estadoCpy, "disponible") == 0 || strcmp(estadoCpy, "prestado") == 0;
}

void leerCadena(const char *mensaje, char *cadena, int tamano) {
    printf("%s", mensaje);
    fgets(cadena, tamano, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int agregarLibro(struct Libro biblioteca[], int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("\nNo se pueden agregar mas libros. Biblioteca llena.\n");
        return 0;
    }

    struct Libro nuevoLibro;

    printf("\nIngrese el ID del libro: ");
    scanf("%d", &nuevoLibro.id);
    getchar();

    for (int i = 0; i < *contador; i++) {
        if (biblioteca[i].id == nuevoLibro.id) {
            printf("\nEl ID ya existe.\n");
            return 0;
        }
    }

    leerCadena("Ingrese el titulo: ", nuevoLibro.titulo, 101);
    leerCadena("Ingrese el autor: ", nuevoLibro.autor, 51);
    printf("Ingrese el año: ");
    scanf("%d", &nuevoLibro.anio);
    getchar();

    do {
        leerCadena("Ingrese el estado (Disponible o Prestado): ", nuevoLibro.estado, 11);
        if (!validarEstado(nuevoLibro.estado))
            printf("Estado invalido. Intente nuevamente.\n");
    } while (!validarEstado(nuevoLibro.estado));

    biblioteca[(*contador)++] = nuevoLibro;
    printf("\nLibro agregado exitosamente.\n");
    return 1;
}

void mostrarLibros(struct Libro biblioteca[], int contador) {
    if (contador == 0) {
        printf("\nNo hay libros en la biblioteca.\n");
        return;
    }

    printf("\n%-10s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Año", "Estado");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%-10d %-30s %-20s %-10d %-15s\n",
               biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
    }
}

void buscarLibro(struct Libro biblioteca[], int contador) {
    if (contador == 0) {
        printf("\nNo hay libros en la biblioteca para buscar.\n");
        return;
    }

    int opcion;
    printf("\nBuscar por: 1. ID 2. Titulo\nSeleccione una opcion: ");
    scanf("%d", &opcion);
    getchar();

    if (opcion == 1) {
        int id;
        printf("\nIngrese el ID del libro: ");
        scanf("%d", &id);

        for (int i = 0; i < contador; i++) {
            if (biblioteca[i].id == id) {
                printf("\nID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
                return;
            }
        }
    } else if (opcion == 2) {
        char titulo[101];
        leerCadena("\nIngrese el titulo del libro: ", titulo, 101);
        for (int i = 0; i < contador; i++) {
            if (strcmp(biblioteca[i].titulo, titulo) == 0) {
                printf("\nID: %d\nTitulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
                return;
            }
        }
    } else {
        printf("\nOpcion invalida.\n");
    }
    printf("\nNo se encontro el libro.\n");
}

void actualizarEstado(struct Libro biblioteca[], int contador) {
    if (contador == 0) {
        printf("\nNo hay libros en la biblioteca.\n");
        return;
    }

    int id;
    printf("\nIngrese el ID del libro: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < contador; i++) {
        if (biblioteca[i].id == id) {
            printf("\nEstado actual: %s\n", biblioteca[i].estado);

            char nuevoEstado[11];
            do {
                leerCadena("Ingrese el nuevo estado: ", nuevoEstado, 11);
                if (!validarEstado(nuevoEstado))
                    printf("Estado invalido. Intente nuevamente.\n");
            } while (!validarEstado(nuevoEstado));

            strcpy(biblioteca[i].estado, nuevoEstado);
            printf("\nEstado actualizado.\n");
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}

void eliminarLibro(struct Libro biblioteca[], int *contador) {
    if (*contador == 0) {
        printf("\nNo hay libros en la biblioteca.\n");
        return;
    }

    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d");
    getchar();

    for (int i = 0; i < *contador; i++) {
        if (biblioteca[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            (*contador)--;
            printf("\nLibro eliminado.\n");
            return;
        }
    }
    printf("\nLibro no encontrado.\n");
}
