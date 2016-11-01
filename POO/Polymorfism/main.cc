// Polymorfism OOP C++ test

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

// 				PERSONA
//					|
//			-----------------
//			|				|
//		EMPLEADO		ESTUDIANTE
//			|				|
//			-----------------
//					|
//				BECARIO

// Clase base : PERSONA
class People {
public:
//		People(string n, int e);
	People(string n);
	const string getName(void);
	int getAge() const;
	void setName(string n);
	void setAge(int e);
protected:
	string name;
	int age;
};
/*
People::People(string n, int e=-1) : name(n), age(e) {
	cout << "Constructor \"People\"" << endl;
};
*/
People::People(string n) : name(n), age(-1) {
	cout << "Constructor \"People\"" << endl;
}

// Clase derivada : EMPLEADO
class Employee : virtual public People {
public:
//		Employee(string n, int e, float s);
	Employee(string n, float s);
//	void getName(void);
	float getSalary() const;
	void setSalary(const float s);
protected:
	float Salary;
};
/*
Employee::Employee(string n, int e=-1, float s) : People(n,e), Salary(s) {
	cout << "Constructor \"Employee\"" << endl;
};
*/
Employee::Employee(string n, float s) : People(n), Salary(s) {};

// Clase derivada : ESTUDIANTE
class Student : virtual public People {
public:
	Student(string n, float score);
//	void getName(void);
	float getScore() const { return this->nota; }
	void setScore(float n) { this->nota = n; }
protected:
	float nota;
};

Student::Student(string n, float score) : People(n), nota(score) {
	cout << "Constructor \"Student\"" << endl;
};

class FellowReasearcher : public Employee, public Student {
public:
	FellowReasearcher(string, float, float);
};

// ES NECESARIO PASAR EL NOMBRE DE LA PERSONA A "People"!!
FellowReasearcher::FellowReasearcher(
	string name, float salary, float score) : 
	Employee(name,salary), Student(name,score), People(name) {};

/************************
 ***** FUNCIÓN MAIN *****
 ************************/

int main(int argc, char **argv)
{	
	FellowReasearcher Fulano("Fulano", 3000, 7.6);

	cout << Fulano.getName() << "\t" << 
			Fulano.getSalary() << "\t" <<
			Fulano.getScore() << endl;

	return 0;
}

/*************************************
 ***** DEFINICIONES DE FUNCIONES *****
 *************************************/

/**********************************
 ***** DEFINICIONES DE CLASES *****
 **********************************/

const string People::getName(void) {
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

float Employee::getSalary() const {
	return this->Salary;
}

void Employee::setSalary(const float s) {
	this->Salary = s;
}
