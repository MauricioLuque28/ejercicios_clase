/*
 ============================================================================
 Name        : clase6_e1.c
 Author      : Mauricio Luque
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int minimoNumArrayInt (int* arrayInt, int tamanoArray, int posicion ,int* pNumeroMinimo, int* pIndiceMinimo);

#define LIMITE 5

int main(void) {

	setbuf (stdout, NULL);

	int arrayDeMauricio[LIMITE] = {21,5,15,18,9};

	//aca empieza la funcion de ordenar algoritmo.

	int auxiliar;
	int valorMin;
	int indiceMin;
	int limite;

	limite = LIMITE - 1;

	minimoNumArrayInt (arrayDeMauricio, LIMITE, 0 , &valorMin, &indiceMin); //llamo a mi funcion

	for ( int i = 0 ; i < limite ; i++  )
	{
		minimoNumArrayInt (arrayDeMauricio, LIMITE, i ,&valorMin, &indiceMin); //calculo el minimo desde i

		if ( i != indiceMin)
		{
			auxiliar = arrayDeMauricio[i];
			arrayDeMauricio[i] = valorMin;
			arrayDeMauricio[indiceMin] = auxiliar;
		}
	}
	// FOR para mostrar resultados.

	for ( int ii = 0 ; ii < LIMITE ; ii++ )
	{
		printf ("\nIndice: %d Valor: %d \n", ii, arrayDeMauricio[ii]);
	}

	return EXIT_SUCCESS;
}

int minimoNumArrayInt (int* arrayInt, int tamanoArray, int posicion ,int* pNumeroMinimo, int* pIndiceMinimo)
{
	int retorno;
	retorno = -1;

	if ( arrayInt != NULL && tamanoArray >= 0 && pNumeroMinimo != NULL && pIndiceMinimo != NULL && posicion >= 0)
	{
		int minimo;
		int indice;

		minimo = arrayInt[posicion];
		indice = arrayInt[posicion];

		for (int i = posicion ; i < tamanoArray ; i++ )
		{
			if ( arrayInt[i] < minimo )
			{
				minimo = arrayInt[i];
				indice = i;
			}
		}

		retorno = 0;
		*pNumeroMinimo = minimo;
		*pIndiceMinimo = indice;
		}
	return retorno;
}
