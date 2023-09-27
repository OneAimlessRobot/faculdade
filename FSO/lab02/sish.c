/*
 * sish - FSO LEI/MIEI
 *
 * vad DI FCT UNL
 * 18/19 - 23/24
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


#define ARGVMAX 100
#define LINESIZE 1024


/* makeargv - build an argv vector from words in a string
 * in: s points a text string with words
 * out: argv[] will point to all words in the string s (*s is modified!)
 * pre: array provided by caller: argv should be declared as char *argv[ARGVMAX]
 * return: number of words pointed to by argv (or -1 in case of error)
 */
int makeargv(char *s, char *argv[ARGVMAX]) {
    int ntokens = 0;

    if (s == NULL || argv == NULL || ARGVMAX == 0)
        return -1;
    argv[ntokens] = strtok(s, " \t\n");
    while ((argv[ntokens] != NULL) && (ntokens < ARGVMAX)) {
        ntokens++;
        argv[ntokens] = strtok(NULL, " \t\n");
    }
    argv[ntokens] = NULL; // it must terminate with NULL
    return ntokens;
}




/* prompt - print a prompt string
 */
void prompt() {
    printf("sish> ");
    fflush(stdout); //writes the prompt
}

/******  MAIN  ******/
int main() {
    char* line=malloc(LINESIZE); //[LINESIZE];
	memset(line,0,LINESIZE);
    char* cmd=malloc(LINESIZE);//[LINESIZE];
	memset(cmd, 0, LINESIZE);
   char**argv=malloc(ARGVMAX);
	memset(argv,0,ARGVMAX);
	//[ARGVMAX];

    while (1) {
        prompt();
        if (fgets(line, LINESIZE, stdin) == NULL){ break;}  // EOF
		line[strlen(line)-1]=0;
	if(!strcmp(line,"exit")){ break;}
		
		for(int i=0;line[i];i++){

			cmd[i]=line[i];
		}
	int bg=line[strlen(line)-1]=='&';
	if(bg){line[strlen(line)-1]=0;}
	char*args= line+strlen(cmd);
	makeargv(args, argv);
	int pid=fork();
	switch(pid){

		case 0:
			printf("Sou o processo do comando\n Commando: %s\n",line);
			execlp(line,line,NULL);
			perror("erro no exec. Processo nao mudou.");
			
			free(line);
			free(cmd);
			for(int i=0;argv[i];i++){


				free(argv[i]);

			}
			free(argv);
				exit(1);
	
		
		default:
			printf("n sei\n");
			if(!bg){
			while(wait(NULL)!=pid);
			}
			break;
	} 
   }

	free(line);
	free(cmd);
	for(int i=0;argv[i];i++){


		free(argv[i]);

	}
	free(argv);
    return 0;
}

