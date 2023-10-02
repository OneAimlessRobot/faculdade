
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <time.h>

#define ARGVMAX 100
#define LINESIZE 1024


/* makeargv - build an argv vector from words in a string
 * in: s points a text string with words
 * out: argv[] will point to all words in the string s (*s is modified!)
 * pre: array provided by caller: argv should be declared as char *argv[ARGVMAX]
 * return: number of words pointed to by argv (or -1 in case of error)
 */


int main(int argc, char**argv) {

	if(argc<2){

		perror("Precisas de um comando!!!\n");
		exit(-1);

	}

	int pid=fork();
	switch(pid){

		case 0:
			execvp(argv[1],argv+1);
			perror("erro no exec. Processo nao mudou.");
			exit(1);

			
		default:{

		
    struct timeval start, end;
 
    gettimeofday(&start, NULL);
 
	while(wait(NULL)!=pid);
    gettimeofday(&end, NULL);

    long seconds = (end.tv_sec - start.tv_sec);
    
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
 
    printf("The elapsed time is %ld micros\n",  micros);

			break;
		}	
}

    return 0;
}

