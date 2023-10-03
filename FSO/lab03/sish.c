/*x * sish - FSO LEI/MIEI * * vad DI FCT UNL * 18/19 - 23/24 */#include <string.h>#include <stdio.h>#include <stdlib.h>#include <unistd.h>#include <sys/wait.h>#include <fcntl.h>#define ARGVMAX 100#define LINESIZE 1024/* makeargv - build an argv vector from words in a string * in: s points a text string with words * out: argv[] will point to all words in the string s (*s is modified!) * pre: array provided by caller: argv should be declared as char *argv[ARGVMAX] * return: number of words pointed to by argv (or -1 in case of error) */int makeargv(char *s, char *argv[ARGVMAX]) {    int ntokens = 0;    if (s == NULL || argv == NULL || ARGVMAX == 0)        return -1;    argv[ntokens] = strtok(s, " \t\n");    while ((argv[ntokens] != NULL) && (ntokens < ARGVMAX)) {        ntokens++;        argv[ntokens] = strtok(NULL, " \t\n");    }    argv[ntokens] = NULL; // it must terminate with NULL    return ntokens;}/* prompt - print a prompt string */void prompt() {    printf("sish> ");    fflush(stdout); //writes the prompt}/******  MAIN  ******/int main(void) {    char line[LINESIZE]; //[LINESIZE];        memset(line,0,LINESIZE);   char*argv[ARGVMAX];        memset(argv,0,ARGVMAX*sizeof(char*));    char secondLine[LINESIZE];	memset(secondLine,0,LINESIZE);    char firstLine[LINESIZE];	memset(firstLine,0,LINESIZE);    char cmd[LINESIZE];//[LINESIZE];	memset(cmd, 0, LINESIZE);char*argv1[ARGVMAX];	memset(argv,0,ARGVMAX*sizeof(char*));   char*argv2[ARGVMAX];	memset(argv,0,ARGVMAX*sizeof(char*));	//[ARGVMAX];  int pipo[2];    while (1) {        prompt();        if (fgets(line, LINESIZE, stdin) == NULL){ break;}  // EOF		line[strlen(line)-1]=0;		memcpy(secondLine,line,strlen(line)+1);		memcpy(firstLine,line,strlen(line)+1);			if(!strcmp(line,"exit")){ break;}						for(int i=0;line[i];i++){			cmd[i]=line[i];		}	int bg=line[strlen(line)-2]=='&';	if(bg){		line[strlen(line)-2]=0;	}			char* wheretodivide;	int isPiping;		if((isPiping=(int)(wheretodivide=strchr(line,'|')))){						int indexInSecond= wheretodivide-line;			line[indexInSecond]=0;			strcpy(firstLine,line);			strcpy(secondLine,line+indexInSecond+1);			printf("Linha 1: %s\nLinha 2: %s\n",firstLine,secondLine);			makeargv(firstLine,argv1);			makeargv(secondLine,argv2);			printf("Pipin\n");			if(pipe(pipo)<0){			perror("Erro no pipo\n");			exit(-1);						}		}		else{			makeargv(line, argv);			}	int pid=fork(),cloneStatus;	switch(pid){		case 0:								if(isPiping){			cloneStatus=fork();				switch(cloneStatus){					case -1:						perror("Erro no fork feito pelo filho\n");						exit(1);					case 0:												dup2(pipo[0],0);						execvp(argv2[0],argv2);						perror("erro no exec. Processo nao mudou.");						exit(1);					default:												dup2(pipo[1],1);						execvp(argv1[0],argv1);						perror("erro no exec. Processo nao mudou.");						exit(1);								}		}				else{									execvp(argv[0],argv);						perror("erro no exec. Processo nao mudou.");						exit(1);				}					default:		if(!bg){			while(wait(NULL)!=pid);		}		break;	}   }    return 0;}