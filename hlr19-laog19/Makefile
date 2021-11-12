# Henrique Luiz Rieger - GRR20190357 - hlr19
# Leon Augusto Okida Gonçalves - GRR20190365 - laog19

CC = gcc
CFLAGS = -Wall
LDLIBS = -lm -lmatheval

objects = vetores.o linhaComando.o utils.o newton.o gauss.o

all: newtonSNL

newtonSNL: newtonSNL.c $(objects)
vetores.o: vetores.c vetores.h
linhaComando.o: linhaComando.c linhaComando.h
newton.o: newton.c newton.h gauss.o
gauss.o: gauss.c gauss.h
utils.o: utils.c utils.h

debug: CFLAGS += -g 
debug: all

clean:
	-rm -f $(objects) newtonSNL

zip: clean
	tar -czvf ../hlr19-laog19.tgz *