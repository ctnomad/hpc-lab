// Program to illustrate execution of parallel processes in MPI
// mproc2022.cpp
#include <iostream>
#include "mpi.h"
int rank;
int comsize;
int main(int* argc, char** argv[])
{
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comsize);
	printf(" Hello world MPI rank %d  size %d \n", rank, comsize);
	MPI_Finalize();
	return 0;
}
