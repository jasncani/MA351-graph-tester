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

void copy_matrix(int v, int original_matrix[v][v], int copy_matrix[v][v]) {
	int i, j;
	for (i = 0; i < v; i++) {
		for (j = 0; j < v; j++) {
			copy_matrix[i][j] = original_matrix[i][j];
		}
	}
}

void matrix_power(int v, int matrix[v][v], int power, int res[v][v]) {
	int i, tmp[v][v];
	if (power == 0) {
		fill_id_matrix(v, res);
		return;
	}
	if (power == 1) {
		copy_matrix(v, matrix, res);
	}
	copy_matrix(v, matrix, tmp);
	for (i = 1; i < power; i++) {
		matrix_product(v, tmp, matrix, res);
		copy_matrix(v, res, tmp);
	}
}

int disjoint_tester(int vertices, int matrix[vertices][vertices]) {
	int i, j;
	int sum_matrix[vertices][vertices], pwr_matrix[vertices][vertices];
	for (i = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++) {
			sum_matrix[i][j] = 0;
		}
	}
	for (i = 0; i < vertices; i++) {
		matrix_power(vertices, matrix, i, pwr_matrix);
		matrix_sum(vertices, pwr_matrix, sum_matrix, sum_matrix);
	}

	for (i = 0; i < vertices; i++) {
		for (j = 0; j < vertices; j++) {
			if (!sum_matrix[i][j]) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {
	int i, j, k, vertices;

	FILE *fptr = fopen("matrix.dat", "r");
	if(fptr == NULL) {
		printf("Error opening matrix.dat");
		exit(1);
	}

	fscanf(fptr, "%d", &vertices);
	int matrix[vertices][vertices];
	fill_matrix(fptr, vertices, matrix);
	fclose(fptr);

	int disjoint = disjoint_tester(vertices, matrix);
	if (disjoint) {
		printf("The graph is disjoint.\n");
	} else {
		printf("The graph is connected.\n");
	}

	return 0;
}
