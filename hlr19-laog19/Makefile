# Henrique Luiz Rieger - GRR20190357 - hlr19
# Leon Augusto Okida Gonçalves - GRR20190365 - laog19

CFLAGS = -Wall -lm -lmatheval

objects = vetores.o linhaComando.o utils.o

all: newtonSNL

newtonSNL: newtonSNL.c $(objects)
	gcc newtonSNL.c -o newtonSNL $(objects) $(CFLAGS)

vetores.o: vetores.c vetores.h
	gcc -c vetores.c -lmatheval

linhaComando.o: linhaComando.c linhaComando.h
	gcc -c linhaComando.c

utils.o: utils.c utils.h
	gcc -c utils.c

debug: CFLAGS += -g 
debug: all

clean:
	-rm -f $(objects) newtonSNL

zip: clean
	tar -czvf ../hlr19-laog19.tgz *