
BINARY= mytime


# compile options for debug mode
all:	$(BINARY).c
	cc -Wall -fsanitize=address -g -o $(BINARY) $(BINARY).c

clean:
	rm -f $(BINARY)
