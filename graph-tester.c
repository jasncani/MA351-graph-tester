// Created by Jason Bacani
// Created for MA351, Fall Intersession 2017
// Checks if a graph is disjoint or not.

#include <stdio.h>
#include <stdlib.h>

int vertices, *matrix[0];

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
	
	int row, col;
	for(row = 0; row < vertices; row++) {
		for(col = 0; col < vertices; col++)
			printf("%d ", matrix[row][col]);
		printf("\n");
	}
	
	return 0;
}