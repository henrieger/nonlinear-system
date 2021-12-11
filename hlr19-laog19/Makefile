# Henrique Luiz Rieger - GRR20190357 - hlr19
# Leon Augusto Okida Gonçalves - GRR20190365 - laog19

LIKWID = /home/soft/likwid
LIKWID_FLAGS = -I$(LIKWID)/include -DLIKWID_PERFMON 
LIKWID_LIBS = -L$(LIKWID)/lib -llikwid

CC = gcc $(LIKWID_FLAGS) $(LIKWID_LIBS)
CFLAGS = -Wall -O3 -mavx -march=native
LDLIBS = -lm -lmatheval

objects = vetores.o linhaComando.o utils.o newton.o gauss.o saida.o
objectsOpt = vetoresOpt.o linhaComando.o utils.o newtonOpt.o gaussOpt.o saida.o

all: newtonSNL newtonSNLOpt

newtonSNL: newtonSNL.c $(objects)
newtonSNLOpt: newtonSNLOpt.c $(objectsOpt)
vetores.o: vetores.c vetores.h
vetoresOpt.o: vetoresOpt.c vetoresOpt.h utils.o
linhaComando.o: linhaComando.c linhaComando.h
saida.o: saida.c saida.h
newton.o: newton.c newton.h gauss.o saida.o utils.o
newtonOpt.o: newtonOpt.c newtonOpt.h gaussOpt.o saida.o utils.o
gauss.o: gauss.c gauss.h
gaussOpt.o: gaussOpt.c gaussOpt.h
utils.o: utils.c utils.h

debug: CFLAGS += -g 
debug: all

clean:
	-rm -f $(objects) $(objectsOpt) newtonSNL newtonSNLOpt

zip: clean
	tar -czvf ../hlr19-laog19.tgz *