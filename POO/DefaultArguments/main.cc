// Default Arguments to functions in OOP C++ test

/*
 * Compilar y ejecutar: ./run.sh
 */

/**************************************************************
 ***** DIRECTIVAS DEL PRE-PROCESADOR: INCLUDES Y DEFINES  *****
 **************************************************************/

#include <iostream>		// cout, cin
#include <stdint.h>		// uint8_t, uint16_t
#include <vector>		// vector
#include <cmath>		// sqrt

using namespace std;

/*********************************************
 ***** DECLARACIÓN DE VARIABLES GLOBALES *****
 *********************************************/

struct Point3D {
	int x;
	int y;
	int z;
};

struct Point2D {
	int x;
	int y;
};

/***********************************
 ***** PROTOTIPOS DE FUNCIONES *****
 ***********************************/

/***********************************
 ***** DECLARACIONES DE CLASES *****
 ***********************************/

class Point {
	int x,y,z;
public:
	Point(int, int, int);
	Point(Point2D);
	Point(Point3D);
	vector<int> getPoint(void);
	void setPoint(int, int, int);
};

Point::Point(int _x=0, int _y=0, int _z=0) : x(_x), y(_y), z(_z) {};

Point::Point(Point2D pp) : x(pp.x), y(pp.y), z(0) {};

Point::Point(Point3D ppp) : x(ppp.x), y(ppp.y), z(ppp.z) {};

/************************
 ***** FUNCIÓN MAIN *****
 ************************/

int main(int argc, char **argv)
{
	vector<int> P;

	Point P1(1,2,3);
	
	Point P2;

	Point P3(1,2);

	struct Point2D pp = {.x=4,.y=5};
	struct Point3D ppp = {.x=7,.y=8,.z=9};

	Point P4(pp);
	Point P5(ppp);

	P = P1.getPoint();

	P = P2.getPoint();

	P = P3.getPoint();

	return 0;
}

/*************************************
 ***** DEFINICIONES DE FUNCIONES *****
 *************************************/

/**********************************
 ***** DEFINICIONES DE CLASES *****
 **********************************/
vector<int> Point::getPoint(void) {
	vector<int> v;

	v.resize(3);
	v.at(0) = this->x;
	v.at(1) = this->y;
	v.at(2) = this->z;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	return v;
}

void Point::setPoint(int x=0, int y=0, int z=0) {
	this->x = x;
	this->y = y;
	this->z = z;
};