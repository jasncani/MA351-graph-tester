// Created by Jason Bacani
// Created for MA351, Fall Intersession 2017
// Checks if a graph is disjoint or not.

#include <stdio.h>
#include <stdlib.h>

int vertices, *matrix[0];

void matrix_sum(int *mat1[], int *mat2[], int res[vertices][vertices]) {
	int i, j;
	for(i = 0; i < vertices; i++)
		for(j = 0; j < vertices; j++)
			res[i][j] = mat1[i][j] + mat2[i][j];
}

void matrix_product(int *mat1[], int *mat2[], int res[vertices][vertices]) {
	int i, j, k;
	for(i = 0; i < vertices; i++)
		for(j = 0; j < vertices; j++) {
			res[i][j] = 0;
			for(k = 0; k < vertices; k++)
				res[i][j] += mat1[i][k] * mat2[k][j];
		}
}

void fill_matrix() {
	int row, col;
	FILE *fptr = fopen("matrix.dat", "r");
	if(fptr == NULL) {
		printf("Error opening matrix.dat");
		exit(1);
	}

	fscanf(fptr, "%d", &vertices);
	realloc(matrix, vertices * sizeof(int *));

	for(row = 0; row < vertices; row++) {
		matrix[row] = (int *)malloc(vertices * sizeof(int));
		for(col = 0; col < vertices; col++)
			fscanf(fptr, "%d", &matrix[row][col]);
	}

	fclose(fptr);
}

int main() {
	fill_matrix();

	int ms[vertices][vertices];
	matrix_sum(matrix, matrix, ms);

	int row, col;
	for(row = 0; row < vertices; row++) {
		for(col = 0; col < vertices; col++)
			printf("%d ", ms[row][col]);
		printf("\n");
	}

	return 0;
}
