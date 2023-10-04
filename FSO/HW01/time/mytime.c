
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

#define ARGVMAX 100
#define LINESIZE 1024

#define BILLION  1000000000.0


int main(int argc, char**argv) {

	if(argc<2){

		perror("Precisas de um comando!!!\n");
		exit(-1);

	}
	int fd,redirect=0;
	char* filePath,*filename,buff[1024];

	for(int i=0;i<argc;i++){

		if(argv[i][0]=='='){
			redirect=1;
			filename= &argv[i][1];
			filePath=strcat(strcat(getcwd(buff,1024),"/"),filename);
			printf("%s\n",filePath);
			int j=i;
			for(;j<argc-1;j++){

				argv[j]=argv[j+1];
			}
			argv[j]=0;
			break;

		}

	}




	int pid=fork();
	switch(pid){

		case 0:
			if(redirect){
			fd=creat(filePath,0666);
			if(fd<0){

				perror("erro ao abrir ficheiro\n");
				exit(-1);
			}
			dup2(fd,1);
			
			}
			execvp(argv[1],argv+1);
			perror("erro no exec. Processo nao mudou.");
			exit(1);

			
		default:{

    struct timespec start, end;
 
    clock_gettime(CLOCK_REALTIME, &start);
	 
 		while(wait(NULL)!=pid);

    clock_gettime(CLOCK_REALTIME, &end);
 
    // time_spent = end - start
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;
 
    printf("\nThe elapsed time is %lf seconds\n", time_spent);

		

			break;
		}	
}

    return 0;
}

