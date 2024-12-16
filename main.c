#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro biblioteca[MAX_LIBROS];
    int contador;
    int opcion;

    inicializarBiblioteca(biblioteca, &contador);

    do {
        printf("\n----- Menu Biblioteca -----\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado de un libro\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) { 
            printf("\nError: Debe ingresar un numero.\n");
            while (getchar() != '\n');
            opcion = -1;  
            continue;     
        }
        while (getchar() != '\n'); 

        switch (opcion) {
            case 1:
                agregarLibro(biblioteca, &contador);
                break;
            case 2:
                mostrarLibros(biblioteca, contador);
                break;
            case 3:
                buscarLibro(biblioteca, contador);
                break;
            case 4:
                actualizarEstado(biblioteca, contador);
                break;
            case 5:
                eliminarLibro(biblioteca, &contador);
                break;
            case 6:
                printf("\nSaliendo del programa. Hasta luego!\n");
                break;
            default:
                printf("\nOpcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 6);

    return 0;
}

