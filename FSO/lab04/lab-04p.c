#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#define SIZE 10000

int *array;
int length, *count,countTotal;


int length_per_thread; // array slice size per thread
unsigned long int chunk_size;
// Code executed by each thread
void *count3s_thread(void *id){
	unsigned long int id2= ((unsigned long int)id);
	unsigned long int start=id2*length_per_thread;
	unsigned long int end=(id2+1)*length_per_thread;
	
//	printf("Thread %lu começou na posicao: %lu\n",id2,start);
	for(int i=start;i<end;i++){
		if(array[i]==3){
		 count[id2]++;
		}
	}
//	printf("Thread %lu terminou na posicao: %lu\n",id2,end);
    	

	
	return NULL;
}
//mcg@fct.unl.pt

// Code with the creation of multiple threads
void count3s(int nthreads){
	pthread_t tids[nthreads];
	
	int nthreads2=(unsigned long int) nthreads;
    countTotal=0;
	for(unsigned long int i=0;i<nthreads2;i++){
	
	count[i]=0;
	pthread_create(&tids[i],NULL,count3s_thread,(void*)i);
	
	}
    for(unsigned long int i=0;i<nthreads2;i++){

	pthread_join(tids[i],NULL);
	
	}
	    	printf("Chunk size: %lu\n",chunk_size);

}

int main( int argc, char *argv[]){

    if ( argc != 2 ) {
        printf("Usage: %s <num_threads>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if ( (SIZE % n) != 0 ) {
        printf("%d must be divisible by <number of threads>\n", SIZE);
        return 1;
    }

    int arrayTmp[SIZE]={0};
    length = SIZE;
    length_per_thread = SIZE / n;
    array=arrayTmp;
    printf("Using %d threads; length_per_thread =  %d\n", n, length_per_thread);
    int countaux[n];
    count= countaux;
    memset(count,0,n*sizeof(int));
    count3s(n);
    
    for(int i=0;i<n;i++){

	countTotal+=count[i];
	}
    printf("Count of 3s (Zeroed out mem) = %d\n", countTotal);
    
	
    srand(0);  // always the same sequence
    
	
	for (int i=0; i < length; i++){
        array[i] = rand() % 4;
    }
	
	count3s(n);
    for(int i=0;i<n;i++){

	countTotal+=count[i];
	}
    printf("Count of 3s = %d\n", countTotal);
    return 0;
}

