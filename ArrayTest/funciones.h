#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

void funcion1(int* M);
void funcion2(int (*M)[3]);

void funcion1(int *M) {
	int i;

	printf("VECTOR\n");

	for (i = 0; i < 5; ++i) {
		printf("%d\n", M[i]);
	}
}

void funcion2(int (*M)[3]) {
	int fil,col;

	printf("MATRIZ:\n");

	for (fil = 0; fil < 2; ++fil) {
		for (col = 0; col < 3; ++col) {
			printf("%d\n", M[fil][col]);
		}
	}
}

#endif // __FUNCIONES_H__