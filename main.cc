// C++ program test

/*
 * Compilar: ./compile.sh
 * Ejecutar: ./run.sh
 */

// [directivas del pre-procesador: includes y defines]
// <>: busca el fichero en el directorio "include" del compilador.
// "": se buscará primero en el directorio actual. Si no lo encuentra,
// 		se buscará como en el caso anterior.
#include <iostream>		// cout, cin
#include <stdint.h>		// uint8_t, uint16_t
#include <cmath>		// sqrt

#define max(a,b) (((a) > (b)) ? (a) : (b))

inline int min(int a, int b) { a < b? a : b; }

using namespace std;

/*********************************************
 ***** DECLARACIÓN DE VARIABLES GLOBALES *****
 *********************************************/

struct estructura {
// Class with public elements
	int A,B;
	struct C {
		char c;
      	char d;
   	} y;
   	struct {
   		char e;
   	};
	int getA() {return A;}
	int getB() {return B;}
	void SetA(int n) {A = n;}
	void SetB(int n) {B = n;}
} strct;

// Definición de tipos nuevos

typedef unsigned int UINT;
typedef unsigned char BYTE;			// 1B = 8b
typedef unsigned short int WORD;	// 2B = 16b

// [prototipos de funciones]

// Pointer as parameter
void Imprimir(const char*);
// Parameter as reference
void funcion_referencia(uint16_t &a, uint16_t &b);
// Array parameter as reference
void array_as_reference(int *tabla, int n);
// Function with default parameters
double VelocidadFinal(double h, double v0=0.0, double g=9.81);

// [declaraciones de clases]

// función main 

int main(int argc, char **argv)
{
	// Argumentos del main
	for(int i = 0; i < argc; i++) 
      cout << argv[i] << " "; 
   	cout << endl; 

	int var = 0;				// 4B = 32b
	bool binary = false;		// 1B = 8b

	long double variable;		// 16B = 128b
	void* nada;					// 8B = 64b

	signed char caracter;		// 1B = 8b
	double pi = 3.141592e0;

	enum orden {primero=1, segundo, tercero} id1, id2, id3;

	cout << "var: " << sizeof(var) << endl;
	cout << "binary: " << sizeof(binary) << endl;
	cout << "variable: " << sizeof(variable) << endl;
	cout << "nada: " << sizeof(nada) << endl;
	cout << "caracter: " << sizeof(caracter) << endl;

	// Long
	long x = 123L;
	if(0L == x) Imprimir("Valor nulo");
	// Unsigned
	unsigned int xx = 123U;
	if(3124232U == xx) Imprimir("Valor encontrado");
	// Float
	// SI NO SE USA EL SUFIJO, ES DOUBLE!!
	float xxx = 0.0;
	if(xxx <= 1.0f) xxx += 0.01f;

	// Variables Char
	char A;
	A = 'a';
	A = 97;
	A = 0x61;
	A = '\x61';

	// Arrays
	char Mensaje[] = "Error de lectura";		// 16 + '\0' = 17
	char Saludo[] = {'H', 'o', 'l', 'a', 0};	// 5
	int N[] = {1, 2, 3, 6}; 					// 4

	cout << "size of Mensaje: " << sizeof(Mensaje)/sizeof(Mensaje[0]) << endl;
	cout << "size of Saludo: " << sizeof(Saludo)/sizeof(Saludo[0]) << endl;
	cout << "size of N: " << sizeof(N)/sizeof(int) << endl;

	// Estructura
	strct.SetA(15);
	strct.SetB(63);
	cout << "A = " << strct.getA() << endl;
	cout << "B = " << strct.getB() << endl;

	// Struct inside struct
	// Insider struct with name
	strct.y.c = 'A';
	// Insider struct without name
	strct.e = 'B';

	// Campos de bits
	// Uns. Short Int = 2B = 16b
	struct mapaBits {
		unsigned short int campo1:3;
		unsigned short int campo2:4;
   		unsigned short int campo3:2;
   		unsigned short int campo4:1;
   		unsigned short int campo5:6;
   		// 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
   		//|    CAMPO 5      |C4|  C3 |  CAMPO 2  |CAMPO 1 |
	};

	/********************
	 ***** PUNTEROS *****
	 ********************/

	cout << "#########################################" << endl;
	int *pEntero = NULL;
	pEntero = &var;	// Se apunta a la variable entera "var"
	cout << "var = " << var;
	*pEntero = 10;	// Cambio el valor de "var"
	cout << " --> " << var << endl;

	char *pChar = Saludo;
	cout << "Saludo\t";
	cout << Saludo << "\t"; 
	cout << Saludo + 1 << "\t";
	cout << Saludo + 2 << "\t";
	cout << Saludo + 3 << endl;

	// Puntero a estructura
	// Initialize pointer with direction of strct
	struct estructura *ptr = &strct;
	cout << "PUNTERO: \t" << ptr->A << "\t" << ptr->B;
	cout << "\t" << ptr->y.c << endl;
	cout << "OBJETO: ";
	cout << "\t" << strct.A << "\t" << strct.B << endl;

	/****************************************
	 ***** DYNAMIC ALLOCATION OF MEMORY *****
	 ****************************************/

	cout << "#########################################" << endl;
	int *mem_a = NULL;
	mem_a = new int(10); 	
	//	*mem_a = 10;
	cout << "a = " << *mem_a << endl;
	delete mem_a;	// IMPORTANTÍSIMO!!!

	char *mem_c = new char[5];
	delete[] mem_c;

	float **mem_f;
	mem_f = new float* [3];	// Array de 3 punteros a float
	// Cada elemento del array es un array de 2 float
	for(int i = 0; i < 3; ++i) mem_f[i] = new float[2];
	// Elimino memorias
	for(int i = 0; i < 3; ++i) delete[] mem_f[i];
	delete[] mem_f;

	/*********************************************
	 ***** PASANDO PARÁMETROS POR REFERENCIA *****
	 *********************************************/

	cout << "#########################################" << endl;
	uint16_t ref_a = 40, ref_b = 25;
	cout << "a = " << ref_a << "\t b = " << ref_b << endl;
	funcion_referencia(ref_a,ref_b);
	cout << "funcion_referencia() :" << endl;
	cout << "a = " << ref_a << "\t b = " << ref_b << endl;

	/*************************************************
	 ***** PUNTEROS COMO PARÁMETROS DE FUNCIONES *****
	 *************************************************/

	cout << "#########################################" << endl;
	char var_a = 'E';
	cout << "Var as Ptr: ";
	Imprimir(&var_a);

	/***********************************************
	 ***** ARRAYS COMO PARÁMETROS DE FUNCIONES *****
	 ***********************************************/

	cout << "#########################################" << endl;
	int tabla[] = {1,2,3,4,5,6,7,8,9};
	array_as_reference(tabla, sizeof(tabla)/sizeof(int));

	/*******************
	 ***** UNIONES *****
	 *******************/

	// Cada elemento se almacenará comenzando en la misma posición
	// de memoria.

	union unEjemplo {
		int A;
		char B;
		double C;
	} UnionEjemplo;

	UnionEjemplo.A = 100;
	UnionEjemplo.B = 'a';
	UnionEjemplo.C = 10.32;

	// 0 1 2 3 4 5 6 7  : Espacio de memoria
	// A A A A 			: int
	// B 				: char
	// C C C C C C C C  : double

	/**********************************************
	 ***** PARÁMETROS CON VALORES POR DEFECTO *****
	 **********************************************/

	cout << "Velocidad final en caida libre desde 100 metros,\n"
		<< "con una velocidad inicial de 10m/s en la Tierra " 
		<< VelocidadFinal(100, 10) << " m/s" << endl;



	/***************************************
	 ***** DIRECTIVAS AL PREPROCESADOR *****
	 ***************************************/

	#ifndef __linux__
		#error You need Linux to avoid the error
	#endif /* ! defined (BFD_HOST_64_BIT) */
	#ifdef OS_WINDOWS
		#warning Windows? Really?
	#endif

	return 0;
}

// [definiciones de funciones]

void Imprimir(const char* C) {
	// const: to avoid warning: 
	// "deprecated conversion from string constant to ‘char*’"

	// Las modificaciones en el valor del puntero C serán locales
	// a la función y no se mantendrán después de retornar.
	// No sucede lo mismo con el objeto apuntado por el puntero,
	// puesto que en ambos casos será el mismo, ya que tanto el puntero
	// como el parámetro tienen como valor la misma dirección de memoria.
	// Por lo tanto, los cambios que hagamos en los objetos apuntados por
	// el puntero se conservarán al abandonar la función.
	cout << C << endl;
}

void funcion_referencia(uint16_t &a, uint16_t &b) {
	a += 2;
	b += 50;
	cout << "(func. ref.) a = " << a << endl;
	cout << "(func. ref.) b = " << b << endl;
}

void array_as_reference(int *tabla, int n) {
	for (int i = 0; i < n; i++)
		cout << *(tabla + i) << "   ";
	cout << endl;
}

double VelocidadFinal(double h, double v0, double g) {
	double t = (-v0+sqrt(v0*v0 + 2*g*h))/g;
	return v0 + g*t;
}

// [definiciones de clases]