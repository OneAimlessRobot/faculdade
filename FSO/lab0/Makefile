
# options for release version
#CFLAGS=-O

# options for debug version
#CFLAGS=-g -Wall -fsanitize=address

all: lab0 simples


lab0: lab0.c
	cc -o lab0 lab0.c $(CFLAGS)

simples:  simples.c
	cc -o simples simples.c $(CFLAGS)

clean:
	rm -f simples lab0
