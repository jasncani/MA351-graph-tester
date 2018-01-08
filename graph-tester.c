// Created by Jason Bacani
// Created for MA351, Fall Intersession 2017
// Checks if a graph is disjoint or not.

#include <stdio.h>
#include <stdlib.h>

void matrix_sum(int v, int mat1[v][v], int mat2[v][v], int res[v][v]) {
	int i, j;
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			res[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void matrix_product(int v, int mat1[v][v], int mat2[v][v], int res[v][v]) {
	int i, j, k;
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			res[i][j] = 0;
			for(k = 0; k < v; k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void fill_matrix(FILE *fptr, int v, int matrix[v][v]) {
	int i, j;
	for(i = 0; i < v; i++) {
		for(j = 0; j < v; j++) {
			fscanf(fptr, "%d", &matrix[i][j]);
		}
	}
}

void fill_id_matrix(int v, int id_matrix[v][v]) {
	int i, j;
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			id_matrix[i][j] = i == j;
		}
	}
}

int main() {
	int i, j, vertices;

	FILE *fptr = fopen("matrix.dat", "r");
	if(fptr == NULL) {
		printf("Error opening matrix.dat");
		exit(1);
	}

	fscanf(fptr, "%d", &vertices);
	int matrix[vertices][vertices];
	fill_matrix(fptr, vertices, matrix);
	fclose(fptr);

	return 0;
}
