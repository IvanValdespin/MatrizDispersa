//
//  Impresiones.c
//  
//
//  Por: Ivan Giovanni Valdespin Garcia Y Citlalli Selene Avalos Montiel.
//  Entrega:31.10.2021


#include "MatrizDispersa.h"


void imprimir_elementos(Matriz matriz){

	Fila *tmp = matriz.Filas.primer_fila;
	Columna *tmp2 = tmp->primer_listacol.primer_columna;
	int m = matriz.Filas.tamano;
	int n = tmp->primer_listacol.tamano;
	
	int i,j;
	for(i = 0;i<m;i++){

		printf("Numero de fila: %d\n", tmp->num_fila);
		for(j = 0; j<n;j++){
			printf("Numero de columna: %d\n",tmp2->num_columna);
			printf("Valor de columna: %f\n",tmp2->valor );
			tmp2 = tmp2->siguiente;
		}
		if (tmp->siguiente !=NULL){
		tmp = tmp->siguiente;
		tmp2 = tmp->primer_listacol.primer_columna;
		n = tmp->primer_listacol.tamano;}
	}
}

void ImprimeMatrizOriginal(Matriz matriz){
	int n = matriz.n+1;
	int m = matriz.m+1;	
	//printf("%d\n",n );
	double *C =(double *)malloc((m+1)*(n+1)*sizeof(double));
	int i,j;
	for(i=0;i<m;i++){//renglón
		for(j=0;j<n;j++){//columna
			C[i*n+j]=0.0;}
	}

	Fila *tmp = matriz.Filas.primer_fila;
	Columna *tmp2 = tmp->primer_listacol.primer_columna;
	int m1 = matriz.Filas.tamano;
	int n1 = tmp->primer_listacol.tamano;
	
	for(i = 0;i<m1;i++){
		for(j = 0; j<n1;j++){
			C[tmp->num_fila*n+tmp2->num_columna] = (tmp2->valor);
			tmp2 = tmp2->siguiente;
		}
		if (tmp->siguiente !=NULL){
		tmp = tmp->siguiente;
		tmp2 = tmp->primer_listacol.primer_columna;
		n1 = tmp->primer_listacol.tamano;}
	}

	ImprimeMatriz(C,matriz);
	free(C);
}

void ImprimeMatriz(double *C,Matriz matriz){
	int i,j;
	int n = matriz.n+1;
	int m = matriz.m+1;
	for(i=0;i<m;i++){//renglón
		for(j=0;j<n;j++){//columna
			printf("%f ",C[i*n+j]);
		}
		printf("\n");
	}	
}
