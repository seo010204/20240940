#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) target[i][j] = s1[i][j] + s2[i][j];
	}
}

void subMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) target[i][j] = s1[i][j] - s2[i][j];
	}
}

void multiMatrix(int Matrix1[][100], int Matrix2[][100], int result[][100], int row1, int col1, int row2, int col2)
{
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < col1; k++) result[i][j] += Matrix1[i][k] * Matrix2[k][j];
		}
	}
}

void input2DArray(int array[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) array[i][j] = rand() % 10;
	}

}

void print2DArray(int array[][100], int row, int col)
{
	printf("===============================================\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) printf("[%4d] ", array[i][j]);
		printf("\n");
	}
}

int main()
{
	int matrix1[ROW][COL];
	int matrix2[ROW][COL];
	int result[ROW][COL];
	int row1, col1, row2, col2;
	
	srand(time(NULL));
	printf("input matrix 1 row & col : ");
	scanf("%d %d", &row1, &col1);
	printf("input matrix 2 row & col : ");
	scanf("%d %d", &row2, &col2);
	
	if (col1 == row2)
	{
		input2DArray(matrix1, row1, col1);
		input2DArray(matrix2, row2, col2);
		multiMatrix(matrix1, matrix2, result, row1, col1, row2, col2);

		print2DArray(matrix1, row1, col1);
		print2DArray(matrix2, row2, col2);
		print2DArray(result, row1, col2);

	}
	else printf("no");
	

	return 0;
}