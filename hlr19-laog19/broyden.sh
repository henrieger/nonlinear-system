#!/bin/bash

for N in 10 32 50 64 100 128 200 250 256 300 400 512 600 1000 1024 2000 2048 3000 4096
do
	echo $N >> entrada.txt
 	echo "(3-2*x1)*x1-2*x2+1" >> entrada.txt
	for i in $(seq 2 $((N-1)))
	do
		echo "(3-2*x$((i)))*x$((i))-x$((i-1))-2*x$((i+1))+1" >> entrada.txt
	done
 	echo "(3-2*x$((N)))*x$((N))-x$((N-1))+1" >> entrada.txt
 	for i in $(seq 1 $N)
	do
		echo -n "-1 " >> entrada.txt
	done
 	echo -e "\n0 20\n" >> entrada.txt

	#Executando testes
	echo "Processando sistema de dimensão $N"
	likwid-perfctr -C 7 -g L3 -m ./newtonSNL < entrada.txt >> l3_${N}.txt
	likwid-perfctr -C 7 -g L2CACHE -m ./newtonSNL < entrada.txt -o resultados_${N}.txt >> l2cache_${N}.txt
	likwid-perfctr -C 7 -g FLOPS_DP -m ./newtonSNL < entrada.txt >> flops_dp_${N}.txt
	likwid-perfctr -C 7 -g L3 -m ./newtonSNLOpt < entrada.txt >> l3_${N}.txt
	likwid-perfctr -C 7 -g L2CACHE -m ./newtonSNLOpt < entrada.txt -o resultados__opt_${N}.txt >> l2cache_${N}.txt
	likwid-perfctr -C 7 -g FLOPS_DP -m ./newtonSNLOpt < entrada.txt >> flops_dp_${N}.txt

	rm entrada.txt
	clear

done