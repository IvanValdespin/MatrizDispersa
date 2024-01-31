//
//  InsertarAnular.c
//  
//
//  Por: Ivan Giovanni Valdespin Garcia Citlalli Selene Avalos Montiel.
//  Entrega:31.10.2021


#include "MatrizDispersa.h"

//Inserción de elementos
void Insertar_Columna(Columna *col, int pos, ListaColumnas *lc){
	if(pos > lc->tamano) { printf("No se puede insertar elemento\n");}

	else if(pos == 0){
		Columna *tmp = lc->primer_columna;
		lc->primer_columna = (Columna*)malloc(sizeof(Columna));
		lc->primer_columna->num_columna = col->num_columna;
		lc->primer_columna->valor = col->valor;
		lc->primer_columna->siguiente = tmp;
		lc->primer_columna->anterior = NULL;
		lc->tamano++;
	}

	else{

    	Columna *last = lc->primer_columna;
    	Columna *iterador = last->siguiente;
   int i;
    for (i=1; i<pos; i++) {
        last = iterador;
        iterador=last->siguiente;
    	}

    last->siguiente = (Columna *)malloc(sizeof(Columna));
    last->siguiente->num_columna = col->num_columna;
    last->siguiente->valor = col->valor;
    last->siguiente->siguiente = iterador;
    last->siguiente->anterior = last;
    lc->tamano++;		
	}
}

void Insertar_Fila(Fila *fil, int pos, ListaFilas *lf){
	
	if(pos > lf->tamano) { printf("NO se puede insertar elemento\n");}

	else if(pos == 0){
		Fila *tmp = lf->primer_fila;
		lf->primer_fila = (Fila*)malloc(sizeof(Fila));
		lf->primer_fila->num_fila = fil->num_fila;
		lf->primer_fila->primer_listacol = fil->primer_listacol;
		lf->primer_fila->siguiente = tmp;
		lf->primer_fila->anterior = NULL;
		lf->tamano++;
	}

	else{

    	Fila *last = lf->primer_fila;
    	Fila *iterador = last->siguiente;
   int i;
    for (i=1; i<pos; i++) {
        last = iterador;
        iterador=last->siguiente;
    	}

    last->siguiente = (Fila *)malloc(sizeof(Fila));
    last->siguiente->num_fila = fil->num_fila;
    last->siguiente->primer_listacol = fil->primer_listacol;
    last->siguiente->siguiente = iterador;
    last->siguiente->anterior = last;
    lf->tamano++;		
	}	
}



void anular_listfil(ListaFilas *lf){

    Fila *tmp, *tmp2;
    
    tmp=lf->primer_fila;
    while (tmp!=NULL) {
        tmp2=tmp->siguiente;
        free(tmp);
        tmp = tmp2;
    }
    lf->tamano=0;
}


Matriz anular_matriz(Matriz matriz){
	anular_listfil(&matriz.Filas); 
	matriz.m = 0;
	matriz.n = 0;
	return matriz;
}
