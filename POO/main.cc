// Object Oriented Programming C++ test

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

class pareja {
	private:
		int a, b;
	public:
		// Constructor - con argumentos por defecto
		pareja(int, int);
		pareja(const pareja&);	// Constructor de copia
		//Destructor
		~pareja();
		// Funciones miembro
		// const: evita que alguna intrucción modifique los valores
		void getPareja(int &, int &) const;
		void setPareja(int, int);
		void setPareja(int);
		// Operadores miembros
		pareja& operator ++ ();		// Prefija : ++var
		pareja& operator ++ (int);	// Sufija  : var++
	protected:
		// Lo que se coloque aquí será privado, excepto para
		// clases derivadas.
};

pareja::pareja(int a2=0, int b2=0) : a(a2), b(b2) {
	cout << "Constructor" << endl;
}

// Constructor de copia
pareja::pareja(const pareja &p) {
    *this = p;
}

pareja::~pareja() {
	cout << "Destructor" << endl;
}

/************************
 ***** FUNCIÓN MAIN *****
 ************************/

int main(int argc, char **argv)
{
	// Argumentos del main
	for(int i = 0; i < argc; i++) 
      cout << argv[i] << " "; 
   	cout << endl; 

	/************************************
	 ***** DECLARACIÓN DE UNA CLASE *****
	 ************************************/

	cout << "#########################################" << endl;
	pareja par1(12,32), par2;
	int x,y;

	par1.getPareja(x,y);
	cout << "Pareja 1: (" << x << ", " << y << ")" << endl;
	par2.getPareja(x,y);
	cout << "Pareja 2: (" << x << ", " << y << ")" << endl;

	par1.setPareja(54);
	par1.getPareja(x,y);
	cout << "Pareja 1: (" << x << ", " << y << ")" << endl;

	++par2;
	par2.getPareja(x,y);
	cout << "++par2: (" << x << ", " << y << ")" << endl;

	// http://c.conclase.net/curso/index.php?cap=029#inicio

	return 0;
}

/*************************************
 ***** DEFINICIONES DE FUNCIONES *****
 *************************************/

/**********************************
 ***** DEFINICIONES DE CLASES *****
 **********************************/

void pareja::getPareja(int &a2, int &b2) const {
	a2 = this->a;
	b2 = this->b;
}

void pareja::setPareja(int a2, int b2) {
	this->a = a2;
	this->b = b2;
}

void pareja::setPareja(int a2) {
	this->a = a2;
	this->b = 0;
}

pareja& pareja::operator ++ () {
	this->a ++;
	this->b ++;
	return *this;
}

pareja& pareja::operator ++ (int) {
	// TODO: hacer operador
}