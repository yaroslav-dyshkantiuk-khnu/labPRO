#include <mpi.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
 int *buffer;
 int myrank;
 MPI_Status status;
 int buffsize = 1;
 int TAG = 0;
 MPI_Init(&argc, &argv);
 MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
 if(myrank == 0)
 {
 buffer = (int *)malloc(buffsize + MPI_BSEND_OVERHEAD);
 MPI_Buffer_attach(buffer, buffsize + MPI_BSEND_OVERHEAD);
 buffer = (int *)10;
 MPI_Bsend(&buffer, buffsize, MPI_INT, 1, TAG, MPI_COMM_WORLD);
 MPI_Buffer_detach(&buffer, &buffsize);
 }
else
{
 MPI_Recv(&buffer, buffsize, MPI_INT, 0, TAG, MPI_COMM_WORLD, &status); 
cout << "received: " << buffer << endl;

}
MPI_Finalize();
system("PAUSE");
return 0;
} 