#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
#define SIZE 10
int main()
{
 
//The reduction clauses are data-sharing attribute clauses 
 	int sum = 0;
 	int arr1={1,2,3,4,5,6,7,8,9};
	#pragma omp parallel for shared(sum, arr1) reduction(+: sum)
	for (auto i = 0; i < 9; i++)
	{
   	 	sum += arr1[i]
	}	 // all threads join master thread and terminates
 
 
// Master.:Specifies that only the master thread should execute a section of the program.
  	int arr[5], i;

    #pragma omp parallel
    {
        // Perform some computation.
        #pragma omp for
        for (i = 0; i < 5; i++)
            arr[i] = i * i;

        // Print intermediate results.
        #pragma omp master
            for (i = 0; i < 5; i++)
                printf("a[%d] = %d\n", i, a[i]);

    }
//Critical : Specifies that code is only executed on one thread at a time.
	int index;
    int max;
    int a[SIZE];

    for (index = 0; index < SIZE; index++)
    {
        a[index] = rand();
        printf("%d\n", a[index]);
    }

    max = a[0];
    #pragma omp parallel for num_threads(4)
        for (index = 1; index < SIZE; index++)
        {
            if (a[index] > max)
            {
                #pragma omp critical
                {
                    // compare a[i] and max again because max
                    // could have been changed by another thread after
                    // the comparison outside the critical section
                    if (a[index] > max)
                        max = a[index];
                }
            }
        }

    printf("max = %d\n", max);
	
}
