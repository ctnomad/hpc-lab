#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

static long num_steps = 1000;

void main() {
    int  i;
    double st, et;
    st = omp_get_wtime();

    double step = 1.0 / (double)num_steps, pi = 0.0;
    omp_set_num_threads(num_steps);

#pragma omp parallel for
    for (i = 0;i < num_steps;i++) {
        double x = (i + 0.5) * step;
        double local_pi = (4.0 * step) / (1 + x * x);
#pragma omp critical
        pi += local_pi;
    }
    et = omp_get_wtime();
    printf("Time Taken : %lf\n", (et - st));
    printf("Value of Pi = %f\n", pi);
}
