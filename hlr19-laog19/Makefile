#Henrique e Leon

CFLAGS = -Wall -lm -lmatheval

objects = linhaComando.o utils.o

all: newtonSNL

newtonSNL: newtonSNL.c $(objects)
	gcc newtonSNL.c -o newtonSNL $(objects) $(CFLAGS)

linhaComando.o: linhaComando.c linhaComando.h
	gcc -c linhaComando.c

utils.o: utils.c utils.h
	gcc -c utils.c

debug: CFLAGS += -g 
debug: all

purge: clean
	-rm -f newtonSNL
clean:
	-rm -f $(objects)