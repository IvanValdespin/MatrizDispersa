# Algoritmo de Matrices Dispersas Comprimidas

Este proyecto implementa un algoritmo para operaciones con matrices dispersas comprimidas. A continuación, se detallan los archivos generados y los pasos para compilar y ejecutar el programa.

## Archivos Generados
- **Main_Matriz.c:** Contiene la función principal `main`.
- **LecturaArchivo.c:** Funciones para la lectura de archivos txt que contienen matrices de prueba.
- **InsertarAnular.c:** Funciones para insertar en las estructuras mencionadas y anular la matriz dispersa comprimida, liberando memoria.
- **Operaciones.c:** Funciones para operaciones como suma, multiplicación y multiplicación por un escalar.
- **Impresiones.c:** Funciones para imprimir matrices, ya sea en un arreglo o directamente desde la estructura de datos del proyecto.
- **MatrizDispersa.h:** Archivo de encabezado.

## Archivos de Prueba
- **A.txt, B.txt, A1.txt, B1.txt, ... :** Archivos que contienen matrices utilizadas para pruebas y confirmación de la corrección del algoritmo.

## Compilación y Ejecución
Para compilar, ejecuta las siguientes líneas en la consola:

```bash
gcc -c LecturaArchivo.c InsertarAnular.c Operaciones.c Impresiones.c
gcc -o main Main_Matriz.c

# Ejecución
./main A.txt B.txt
