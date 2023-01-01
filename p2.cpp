#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
void main() {
	int i, j, sum = 0;
	srand(time(0));
	int b[4][100] = { 0 };
	int x[4] = { 0 };
	int c[4] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		c[i] = rand() % 10;
	}

	printf("\nClothing Section costs: ");
	for (int i = 0; i < c[0]; i++)
	{
		b[0][i] = rand() % 1000;
		printf("%d \t", b[0][i]);
	}

	printf("\nGaming Section costs: ");
	for (int i = 0; i < c[1]; i++)
	{
		b[1][i] = rand() % 1000;
		printf("%d \t", b[1][i]);
	}

	printf("\nGrocery Section costs: ");
	for (int i = 0; i < c[2]; i++)
	{
		b[2][i] = rand() % 1000;
		printf("%d \t", b[2][i]);
	}

	printf("\nStationery Section costs: ");
	for (int i = 0; i < c[3]; i++)
	{
		b[3][i] = rand() % 1000;
		printf("%d \t", b[3][i]);
	}

#pragma omp parallel 
	{
		for (int i = 0; i < 4; i++)
		{
			for (j = 0;j < c[i]; j++) {
				x[i] += b[i][j];
			}
#pragma omp critical 
			{
			sum += x[i];
			}
		}
	}
	printf("\n\n Sum is %d", sum);
}
