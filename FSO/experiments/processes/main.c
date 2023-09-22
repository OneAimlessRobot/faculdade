#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>


int main(int argc, char** argv){

	printf("Processo pai: %d\n",getpid());
	
	int pid=fork();

	switch(pid){

		case -1:
			perror("ERRO!!!!\n");
		
		case 0:
			printf("Pid filho: %d\n",getpid());
			exit(0);
		default:
			printf("Pid do filho printado a partir do pai: %d\n",pid);
			break;






	}
	


	return 0;
}
