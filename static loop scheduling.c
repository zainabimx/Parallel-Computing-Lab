#include<stdio.h>
#include<omp.h>

int main() {
    int num_iterations;
    printf("Enter the number of iterations:");
    scanf("%d",&num_iterations);
    #pragma omp parallel
    {
        #pragma omp for schedule(static,2)
        for(int i=0;i<num_iterations;i++){
            printf("Thread %d:iteration %d\n",omp_get_thread_num(),i);
        }
    }
    return 0;
}