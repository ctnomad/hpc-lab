#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int fib(int n) {
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int main() {
	int n, i;
	printf("Number of terms : ");
	scanf_s("%d", &n);
	int* fibo = (int*)malloc(n * sizeof(int));

	double st, et;
	st = omp_get_wtime();
	omp_set_num_threads(2);
#pragma omp parallel
	{
#pragma omp critical
		if (omp_get_thread_num() == 0)
		{
			printf("Calculating thread id = %d\n", omp_get_thread_num());
			for (i = 0; i < n; i++)
				fibo[i] = fib(i);
		}
		else if (omp_get_thread_num() == 1)
		{
			printf("Printing thread id = %d\n", omp_get_thread_num());
			printf("Fibonacci numbers : ");
			for (i = 0; i < n; i++)
				printf("%d ", fibo[i]);
			printf("\n");
		}
	}
	et = omp_get_wtime();
	printf("\nTime Taken : %lfms\n", (et - st));
	return 0;
}
