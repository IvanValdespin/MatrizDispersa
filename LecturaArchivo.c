//
//MatriDispersa.c
//Autores: Ivan Giovanni Valdespin Garcia y Citlalli Avalos Montiel.
//Entrega: 3-Dic-2021

#include "MatrizDispersa.h"
#include "InsertarAnular.c"

//Inicialización de estructuras

void Iniciar_ListaColumnas(ListaColumnas *lc){
	lc->primer_columna = NULL;
	lc->tamano = 0;
}

void Iniciar_ListaFilas(ListaFilas *lf){
	lf->primer_fila =NULL;
	lf->tamano = 0;
}

void Iniciar_Matriz(Matriz matriz){
	matriz.m = 0;
	matriz.n = 0;
	matriz.Filas.primer_fila = NULL;
	matriz.Filas.tamano = 0;
}


//Lectura de archivos

Matriz LeerArchivo(FILE *fp, char **argv, Matriz matriz, int n){
	char buffer[SB];
		ListaFilas listfil;
		ListaColumnas listcol;
		Fila fil;
		Columna col;
		char caracter;

		fp = fopen(argv[n], "r");
		
		int i,j,k,aux,r,r1;
		k = 0; //Recorre el buffer
		i = 0; //Numero de fila
		j =0; //Numero de columna
		r = 0;//Recorre columnas
		r1 = 0; //Recorre filas
		aux = 0;


		Iniciar_ListaFilas(&listfil);
		Iniciar_ListaColumnas(&listcol);
		while(aux ==0){
			caracter = fgetc(fp);
			if(caracter==',' || caracter== EOF || caracter=='\n'){
				buffer[k] = '\0';
				k=0;
				if (atoi(buffer) != 0){
					col.num_columna = j;
					col.valor = atof(buffer);
					Insertar_Columna(&col,r,&listcol);
					r++;
				}
				if (caracter == ','){j++;}

				if(caracter=='\n' && listcol.tamano!=0 || caracter == EOF && listcol.tamano!=0 ){
					fil.num_fila = i;
					fil.primer_listacol = listcol;
					Insertar_Fila(&fil,r1,&listfil);
					r1++;}

				if(caracter == '\n'){
					Iniciar_ListaColumnas(&listcol);
					j = 0;
					r = 0;
					i++;}
				if(caracter==EOF){aux=1; break;}

				
			}
			else{
				buffer[k] = caracter;
				k++;
			}

		}
		matriz.m = i;
		matriz.n = j;
		matriz.Filas = listfil;
		return matriz;
}	






