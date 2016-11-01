/*
 * Para compilar: 
 * gcc main.c -o main.exe
 */

#include <stdio.h>
#include <conio.h>
 
#include "Funciones.h"

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,4,5};
	int B[3][3] = {
		{1,2,3},
		{4,5,6}
	};

	system("cls");

	funcion1(A);
	funcion2(B);

	getch();
	
	return 0;
}