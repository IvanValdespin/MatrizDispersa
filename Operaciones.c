//
//  Operaciones.c
//  
//
//  Por: Ivan Giovanni Valdespin Garcia y Citlalli Selene Avalos Montiel
//  Entrega:31.10.2021

#include "MatrizDispersa.h"
#include "Impresiones.c"


void MultEsc(Matriz matriz, int escalar){

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
			C[tmp->num_fila*n+tmp2->num_columna] = (tmp2->valor)*escalar;
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


void SumaM(Matriz A, Matriz B){

	if (A.m!=B.m || A.n!= B.n){
		printf("Las matrices no son del mismo orden \n");
		printf("No se puede realizar la suma\n");
	}
	else{
	int n = A.n+1;
	int m = A.m+1;	


	//printf("%d\n",n );
	double *C =(double *)malloc((m+1)*(n+1)*sizeof(double));
	int i,j;
	for(i=0;i<m;i++){//renglón
		for(j=0;j<n;j++){//columna
			C[i*n+j]=0.0;}
	}

	Fila *Atmp = A.Filas.primer_fila;
	Columna *Atmp2 = Atmp->primer_listacol.primer_columna;
	int mA = A.Filas.tamano;
	int nA = Atmp->primer_listacol.tamano;
	Fila *Btmp = B.Filas.primer_fila;
	Columna *Btmp2 = Btmp->primer_listacol.primer_columna;
	int mB = B.Filas.tamano;
	int nB = Btmp->primer_listacol.tamano;
	
	for(i = 0;i<mA;i++){
		for(j = 0; j<nA;j++){
			
			C[Atmp->num_fila*n+Atmp2->num_columna]=Atmp2->valor;
			Atmp2 = Atmp2->siguiente;
		}
		if (Atmp->siguiente !=NULL){
		Atmp = Atmp->siguiente;
		Atmp2 = Atmp->primer_listacol.primer_columna;
		nA = Atmp->primer_listacol.tamano;}
	}

	for(i = 0;i<mB;i++){
		for(j = 0; j<nB;j++){
			
			C[Btmp->num_fila*n+Btmp2->num_columna]+=Btmp2->valor;
			Btmp2 = Btmp2->siguiente;
		}
		if (Btmp->siguiente !=NULL){
		Btmp = Btmp->siguiente;
		Btmp2 = Btmp->primer_listacol.primer_columna;
		nB = Btmp->primer_listacol.tamano;}
	}


	ImprimeMatriz(C,A);
	free(C);}
}

void Multiplicacion(Matriz A, Matriz B){

	if (A.n!=B.m){
		printf("No se puede realizar la multiplicacion\n por el orden de las matrices\n");
	}
	else{
	
	int n = A.n+1;
	int m = A.m+1;	
	int n1 = B.n+1;
	int m1 = B.m+1;	


	double *C =(double *)malloc((m+1)*(n1+1)*sizeof(double));//dimensiones de C: mxn1
	int i,j;
	for(i=0;i<m;i++){//renglón
		for(j=0;j<n1;j++){//columna
			C[i*n1+j]=0.0;}
	}

	Fila *Atmp = A.Filas.primer_fila;
	Columna *Atmp2 = Atmp->primer_listacol.primer_columna;
	int mA = A.Filas.tamano;
	int nA = Atmp->primer_listacol.tamano;
	Fila *Btmp = B.Filas.primer_fila;
	Columna *Btmp2 = Btmp->primer_listacol.primer_columna;
	int mB = B.Filas.tamano;
	int nB = Btmp->primer_listacol.tamano;
	int op=0;

	
	for(i = 0;i<mA;i++){
		//Elementos fila A
		for(j = 0; j<nA;j++){
			//Elementos de la columna A de la fila i
			int ac=Atmp2->num_columna;
			while(ac>Btmp->num_fila && Btmp->siguiente!=NULL){
				Btmp=Btmp->siguiente;
				Btmp2 = Btmp->primer_listacol.primer_columna;
			}
			
			if(ac==Btmp->num_fila){
				do{
		
					C[Atmp->num_fila*n1+Btmp2->num_columna]+=Btmp2->valor*Atmp2->valor;
					if (Btmp2->siguiente !=NULL){
						Btmp2=Btmp2->siguiente;
						op=0;
						
					}
					else op=1;

				}while(op==0);
			}

			Atmp2 = Atmp2->siguiente;
			Btmp = B.Filas.primer_fila;
			Btmp2 = Btmp->primer_listacol.primer_columna;
		}
		if (Atmp->siguiente !=NULL){
		Atmp = Atmp->siguiente;
		Atmp2 = Atmp->primer_listacol.primer_columna;
		nA = Atmp->primer_listacol.tamano;
		Btmp = B.Filas.primer_fila;
		Btmp2 = Btmp->primer_listacol.primer_columna;
		}
	}

	Matriz Z;
	Z.n=n1-1;
	Z.m=m-1;
	ImprimeMatriz(C,Z);
	free(C);
	}
}
