// Templates in OOP C++ test

/*
 * Compilar y ejecutar: ./run.sh
 */

/**************************************************************
 ***** DIRECTIVAS DEL PRE-PROCESADOR: INCLUDES Y DEFINES  *****
 **************************************************************/

#include <iostream>		// cout, cin
#include <stdint.h>		// uint8_t, uint16_t

using namespace std;

/*********************************************
 ***** DECLARACIÓN DE VARIABLES GLOBALES *****
 *********************************************/

/***********************************
 ***** PROTOTIPOS DE FUNCIONES *****
 ***********************************/

/***********************************
 ***** DECLARACIONES DE CLASES *****
 ***********************************/

template <class T>
class Bucky
{
	T first, second;	// Private variables
public:
	Bucky(T a, T b){	// Constructor
		first = a;		// Assignment to priv. vars
		second = b;
	};	
	
	T bigger();	
};

template <class T>
T Bucky<T>::bigger() {
	return first > second? first : second;
}

/************************
 ***** FUNCIÓN MAIN *****
 ************************/

int main(int argc, char **argv)
{
	// http://c.conclase.net/curso/index.php?cap=040#inicio
	// https://www.youtube.com/watch?v=U2QvTsMvWmM

	int x = 69, y = 105;
	Bucky <int> bo(x, y);	// Calling the constructor...

	/*
	 * NOTE: bigger() doen't take arguments because it uses private
	 * variables of the class "Bucky".
	 */
	cout << "The biggest between " << x << " and " << y <<
	 " is: " << bo.bigger() << endl;

	return 0;
}

/*************************************
 ***** DEFINICIONES DE FUNCIONES *****
 *************************************/

/**********************************
 ***** DEFINICIONES DE CLASES *****
 **********************************/

