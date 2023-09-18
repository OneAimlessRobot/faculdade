/*****
 * AC DI-FCT/UNL
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>


// Este programa parece funcionar bem, mas na
// realidade tem erros! Localize-os e corrija-os...



int soma( int x[3] ) {
  	for(int i=0;i<3;i++){


	printf("%d\n",x[i]);
	}
	return  x[0]+x[1]+x[2];
}

char *dupstr (char *str) {
  // find the size of the original string
  int size = 0;

  while (str[size] != '\0')
    size++;

  // allocate space for the new string
  char *newstr = malloc(size+1);

  // copy original string to new string 
  for (int i = 0; i < size; i++)
    newstr[i] = str[i];

  // add the terminator to the string
  newstr[size] = '\0';

  // return the new string
  return newstr;
}


char maior( char c ) {
  return c+ ('A'-'a');  // passa minuscula a maiuscula
}

void transforma( char *str ) {
  int i = 0;
  while ( str[i] != '\0' ) {
    if ( str[i] >='a' && str[i]<='z' ) str[i] = maior( str[i] );
	i++;  
}
}


int main (int argc, char *argv[]) {
  char *s1 = "abcde0";
  char *s2 = dupstr (s1);
  int z[3];
  int x=1;

  printf("Original = '%s'\n   Copia = '%s'\n", s1, s2);
  transforma( s2 );
  z[0]=z[1]=z[2]=1;
  soma( z );
  printf( "nova= %s,%d X=%d\n", s2,sizeof(z), x );
  free(s2);
  return 0;
}

