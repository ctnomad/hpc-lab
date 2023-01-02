// Summation of Array elements distributed to multiple processes (in this case 4 processes.
//
#include <iostream>
//P0 broadcasts array to a all processes using Bcast function. 
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int rank, i;
    int sendbuf[12];
    int root = 0;
    int sum;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for (i = 0; i < 12; i++)
    {
        sendbuf[i] = 0;
    }
    printf("Process [%d]: Before Bcast,First element of buf is %d\n", rank, sendbuf[0]);
    if (rank == 0)
    {
        for (i = 0; i < 12; i++)
        {
            sendbuf[i] = 100 + i;
        }
    }
    MPI_Bcast(&sendbuf, 12, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process [%d]: After Bcast, 1st element of sendbuf corresponding to this process is %d\n", rank, sendbuf[rank * 3]);
    sum = 0;
    for (i = rank * 3; i < (rank + 1) * 3; i++)
    {
        sum += sendbuf[i];
    }
    printf("Process [%d]: Sum of array elements corresponding to this process is %d\n", rank, sum);
    MPI_Finalize();
    return 0;
}
