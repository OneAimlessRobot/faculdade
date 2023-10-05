
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

void trim (char *dest, char *src)
{
    if (!src || !dest)
       return;

    int len = strlen (src);

    if (!len) {
        *dest = '\0';
        return;
    }
    char *ptr = src + len - 1;

    // remove trailing whitespace
    while (ptr > src) {
        if (!isspace (*ptr))
            break;
        ptr--;
    }

    ptr++;

    char *q;
    // remove leading whitespace
    for (q = src; (q < ptr && isspace (*q)); q++)
        ;

    while (q < ptr)
        *dest++ = *q++;

    *dest = '\0';
}

int main(int argc, char**argv) {

	if(argc<2){

		perror("argv[1]");
		exit(-1);

	}
	int fd,redirect=0;
	char* filePath,buff[1024],buff2[1024];

	for(int i=0;i<argc;i++){

		if(argv[i][0]=='='){
			redirect=1;
			if(strlen(argv[i])>1){

			strcpy(buff2,&argv[i][1]);
			}
			else{
			trim(buff2,&argv[i+1][0]);
			
			argv[i+1]=0;
			
			}
			argv[i]=0;
			filePath=strcat(strcat(getcwd(buff,1024),"/"),buff2);
			
			break;

		}

	}




	int pid=fork();
	switch(pid){
		case -1:
			perror("fork");
			exit(-1);

		case 0:
			if(redirect){
			fd=creat(filePath,0666);
			if(fd<0){

				perror("creat");
				exit(-1);
			}
			dup2(fd,1);
			
			}
			execvp(argv[1],argv+1);
			perror("exec");
			exit(-1);

			
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

