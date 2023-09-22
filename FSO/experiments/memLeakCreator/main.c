#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

void func(char *str){

	for(int i=0;i<10;i++){

		printf("%s\n",str);

		sleep(1);
	}



}



int main(int argc, char ** argv){
	
	
	int pid= fork();
	func("printing pai");
	
	switch(pid){

		case -1:
			perror("Ok acabou a brincadeira");
			break;
		case 0:
			func("printing filho");
			exit(0);
		
		default:
			wait(NULL);
			break;


	}
	



	return 0;
}
