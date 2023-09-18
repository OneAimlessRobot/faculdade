
CFLAGS = -Wall
# mem program *
# for MacOS/Darwin: disable ASLR by disabling PIE code at link time
# CFLAGS+=-Wl,-no_pie
# for Linux: disable ASLR by running with "setarch -R prog"
#

PROGS = fcopia copia timing Copia.class mem

all:	$(PROGS)

%.class:	%.java
	javac $<

clean:
	rm -f $(PROGS)  *.o *~
