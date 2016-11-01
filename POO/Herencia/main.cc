// Herency OOP C++ test

/*
 * Compilar y ejecutar: ./run.sh
 */

/**************************************************************
 ***** DIRECTIVAS DEL PRE-PROCESADOR: INCLUDES Y DEFINES  *****
 **************************************************************/

#include <iostream>		// cout, cin
#include <stdint.h>		// uint8_t, uint16_t
#include <string>		// string

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

// Clase base : PERSONA
class People {
	public:
		People(string n, int e);
		string getName(void);
		int getAge() const;
		void setName(string n);
		void setAge(int e);
		void redefineFunction(void);	// Función redefinida
	protected:
		string name;
		int age;
};

People::People(string n, int e) : name(n), age(e) {
	cout << "Constructor \"People\"" << endl;
};

// Clase derivada : EMPLEADO
class Employee : public People {
	public:
		Employee(string n, int e, float s);
		float getSalary() const;
		void setSalary(const float s);
		void redefineFunction(void);	// Función redefinida
	protected:
		float annualSalary;
};

Employee::Employee(string n, int e, float s) : People(n,e), annualSalary(s) {
	cout << "Constructor \"Employee\"" << endl;
};

class Student : public People {
	public:
		Student(string n) : People(n) {};
};

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
	Employee Pepe("Pepe", 34, 15000);

	cout << "NAME: " << Pepe.getName() << endl;
	cout << "AGE : " << Pepe.getAge() << endl;

	// Funciones redefinidas
	Pepe.redefineFunction();
	Pepe.People::redefineFunction();

	return 0;
}

/*************************************
 ***** DEFINICIONES DE FUNCIONES *****
 *************************************/

/**********************************
 ***** DEFINICIONES DE CLASES *****
 **********************************/

string People::getName(void) {
	return this->name;
}

int People::getAge(void) const {
	return this->age;
}

void People::setName(string n) {
	this->name = n;
}

void People::setAge(int e) {
	this->age = e;
}

void People::redefineFunction(void) {
	// Función redefinida
	cout << "People Function" << endl;
}

float Employee::getSalary() const {
	return this->annualSalary;
}

void Employee::setSalary(const float s) {
	this->annualSalary = s;
}

void Employee::redefineFunction(void) {
	// Función redefinida
	cout << "Employee Function" << endl;
}