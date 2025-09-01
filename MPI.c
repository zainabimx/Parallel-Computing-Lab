#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[]){
    int rank,size;
    int number;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(size<2){
        if(rank == 0){
            printf("This program requires at least 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }
    if(rank == 0){
        number = 42;
        printf("Process 0 is sending number %d to process 1 \n",number);
        MPI_Send(&number, 1, MPI_INT,1,0,MPI_COMM_WORLD);
    }else if(rank==1){
        MPI_Recv(&number, 1, MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Process 1 is received number %d to process 0 \n",number);
    }
    MPI_Finalize();
    return 0;
}