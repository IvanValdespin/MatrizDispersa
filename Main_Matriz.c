//  Main_Matriz.c
//  
//
//  Por: Ivan Giovanni Valdespin Garcia y Citlalli Selene Avalos Montiel e 
//  Entrega:31.10.2021

#include "LecturaArchivo.c"
#include "Operaciones.c"

int main(int argc, char **argv){
		
	FILE *fp, *fpLeerp;
	Matriz  matriz,matriz2;
	Iniciar_Matriz(matriz);
	matriz = LeerArchivo(fp,argv,matriz,1);
	matriz2 = LeerArchivo(fp,argv,matriz2,2);
	double esc;
	int i;
	int seleccion,seleccion0,seleccion2,seleccion3;
	int a = 1;


		do	{

			if ((matriz.m+1) >TAMMAX || (matriz2.n+1) > TAMMAX){
			printf("Matriz demasiado grande para mostrar...\n");
			printf("Dimensiones de matriz A\nNum.Filas: %d\nNum.Columnas: %d\n\n", (matriz.m+1),(matriz.n+1));
			printf("Dimensiones de matriz B\nNum.Filas: %d\nNum.Columnas: %d\n\n", (matriz2.m+1),(matriz2.n+1));}
			else{

			printf("Matriz A\n");
			ImprimeMatrizOriginal(matriz);
			//Lineas para imprimir los elementos de las listas generadas
			//printf("\nElementos de A \n");
			//imprimir_elementos(matriz);
			printf("\n\n");
			printf("Matriz B\n");
			ImprimeMatrizOriginal(matriz2);
			printf("\n");}
			//Lineas para imprimir los elementos de las listas generadas
			//printf("\nElementos de B \n");
			//imprimir_elementos(matriz2);
			printf("\n");
			printf("1.Suma de Matrices\n2.Multiplicacion de matrices\n3.Multiplicacion por un escalar\n");
			printf("Selecciona operacion a realizar: ");
			scanf("%d",&seleccion);

			if (seleccion > 4){seleccion = 4;}

			switch(seleccion)
			{
				case 1:
					printf("\n---Suma Matrices A+B: \n");
					SumaM(matriz,matriz2);
					printf("\n");
					break;

				case 2:
					
					printf("\n1.A*b\n2.B*A");
					printf("\nSelecciona tipo de Multiplicacion: ");
					scanf("%d",&seleccion2);
					while(seleccion2 != 1 && seleccion2 != 2){
						printf("\nOpción no valida, seleccione opcion aceptable\n");
						printf("\n-Selecciona tipo de multiplicacion: ");
						scanf("%d",&seleccion2);
						}

					switch(seleccion2)
					{
						case 1:
							printf("\n----Multiplicacion A*B: \n");
							Multiplicacion(matriz,matriz2);
							printf("\n");
							break;
						case 2:
							printf("\n----Multiplicacion B*A: \n");
							Multiplicacion(matriz2,matriz);
							printf("\n");
							break;
					}
					break;

				case 3:
					
					printf("\n---Multiplicacion por Escalar:\n");
					printf("1.A\n2.B\n");
					printf("\n-Selecciona matriz a multiplicar: ");
					scanf("%d",&seleccion3);
					while(seleccion3 != 1 && seleccion3 != 2){
						printf("\nOpción no valida, seleccione opcion aceptable\n");
						printf("\n-Selecciona matriz a multiplicar: ");
						scanf("%d",&seleccion3);
						}

					
					switch(seleccion3)
					{
						case 1:
							
							printf("\nIngresa el escalar: ");
							i=scanf( "%lf", &esc);
							printf("\n%lf * A = \n\n",esc);
							MultEsc(matriz,esc);
							printf("\n");
							break;
						case 2:
							printf("\nIngresa el escalar: ");
							i=scanf( "%lf", &esc);
							printf("\n%lf * B = \n\n",esc);
							MultEsc(matriz2,esc);
							printf("\n");
							break;
					}

					break;
				case 4:
					printf("\nSeleccion fuera de rango\n");
			}
			printf("¿Deseas realizar otra operacion?\n1.Si\n2.No\n");
			scanf("%d",&seleccion0);
			a = seleccion0;
			printf("\n");
			}
		while(a==1);

	//anular
	matriz = anular_matriz(matriz);
	matriz2 = anular_matriz(matriz2);

	return 0;

}
	
