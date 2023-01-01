#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
int main() {
	int n, stud, i;
	double st, et;
	st = omp_get_wtime();
	printf("Enter the number of students : ");
	scanf_s("%d", &n);
	double* arr = (double*)malloc(n * sizeof(double));
	double arr_max = 0;

#pragma omp parallel for
	for (i = 0; i < n; i++) {
		srand(i);
		arr[i] = rand()%10 + (rand()%100) * 0.01;
	}

	printf("CGPA of students : ");
	for (i = 0; i < n; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");
#pragma omp parallel for
	for (i = 0; i < n; i++) {
		if (arr_max < arr[i])
#pragma omp critical 
		{
			arr_max = arr[i];
			stud = i;
		}
	}
	et = omp_get_wtime();
	printf("Student with highest CGPA = %.2lf by student %d\n", arr_max, stud);
	printf("Time Taken : %.2lfms\n", (et - st) );
}
