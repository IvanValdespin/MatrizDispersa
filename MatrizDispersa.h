//
//Matriz dispersa.h
// Autores: Ivan Giovanni Valdespin Garcia y Citlalli Avalos Montiel
//Entrega 3-Diciembre-2021




#ifndef MatrizDispersa_h
#define MatrizDispersa_h

#define SB 100
#define TAMMAX 5 //Define el tamaño maximo de matriz que se puede mostrar en pantalla.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Columna{
	int num_columna;
	double valor;
	struct _Columna *siguiente;
	struct _Columna *anterior;
}Columna;

//Estructura lista de columnas de casa fila
typedef struct _ListaColumnas{
	Columna *primer_columna;
	int tamano;
}ListaColumnas;

//Estructura Lista de listas
typedef struct _Fila{
	int num_fila;
	ListaColumnas primer_listacol;
	struct _Fila *siguiente;
	struct _Fila *anterior;
}Fila;

typedef struct _ListaFilas{
	Fila *primer_fila;
	int tamano;

}ListaFilas;


typedef struct _Matriz{
	int m;
	int n;
	ListaFilas Filas; 
}Matriz;


//Leectura de archivor de entrada e inicialización de estructuras.
Matriz LeerArchivo(FILE *fp,char **argv,Matriz matriz, int n);
void Iniciar_ListaColumnas(ListaColumnas *lc);
void Iniciar_ListaFilas(ListaFilas *lf);
void Iniciar_Matriz(Matriz matriz);

//Insercion de elementos el las listas ligadas
void Insertar_Columna(Columna *col, int pos, ListaColumnas *lc);
void Insertar_Fila(Fila *fil, int pos, ListaFilas *lf);

//Aplicación de operaciones deseadas
void MultEsc(Matriz matriz, int escalar);
void Multiplicacion(Matriz matriz, Matriz matriz2);
void SumaM(Matriz matriz, Matriz matriz2);

//Borrar elementos y liberación de memoria
void anular_listfil(ListaFilas *lf);
Matriz anular_matriz(Matriz matriz);

//Impresion de elelemtos de entrada y salida
void imprimir_elementos(Matriz matriz);
void ImprimeMatrizOriginal(Matriz matriz);
void ImprimeMatriz(double *C,Matriz matriz);
#endif /*MatrizDispersa*/
