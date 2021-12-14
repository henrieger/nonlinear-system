#!/bin/bash

# Apaga os remanescentes de outras iterações
rm -f *.dat

# Procura e exporta dados nos arquivos de log do LIKWID
for i in 10 32 #50 64 100 128 200 250 256 300 400 512 600 1000 1024 2000 2048 3000 4096
do
    TEMPO=$(grep 'Tempo Total' l3_$i.txt | cut -d' ' -f4)
    echo $i ${TEMPO[@]} >> tempo_newton.dat
    TEMPO=$(grep 'Tempo Derivadas' l3_$i.txt | cut -d' ' -f4)
    echo $i ${TEMPO[@]} >> tempo_derivadas.dat
    TEMPO=$(grep 'Tempo Jacobiana' l3_$i.txt | cut -d' ' -f4)
    echo $i ${TEMPO[@]} >> tempo_matriz.dat
    TEMPO=$(grep 'Tempo SL' l3_$i.txt | cut -d' ' -f4)
    echo $i ${TEMPO[@]} >> tempo_sistema.dat

    L3=$(grep 'L3 bandwidth' l3_$i.txt | cut -d'|' -f3)
    L3ARRAY=($L3)
    echo $i ${L3ARRAY[0]} ${L3ARRAY[4]} >> l3_derivadas.dat
    echo $i ${L3ARRAY[1]} ${L3ARRAY[5]} >> l3_newton.dat
    echo $i ${L3ARRAY[2]} ${L3ARRAY[6]} >> l3_matriz.dat
    echo $i ${L3ARRAY[3]} ${L3ARRAY[7]} >> l3_sistema.dat

    L2=$(grep 'L2 miss ratio' l2cache_$i.txt | cut -d'|' -f3)
    L2_CACHE=($L2)
    echo $i ${L2_CACHE[0]} ${L2_CACHE[4]} >> l2cache_derivadas.dat
    echo $i ${L2_CACHE[1]} ${L2_CACHE[5]} >> l2cache_newton.dat
    echo $i ${L2_CACHE[2]} ${L2_CACHE[6]} >> l2cache_matriz.dat
    echo $i ${L2_CACHE[3]} ${L2_CACHE[7]} >> l2cache_sistema.dat

    FLOPS=$(grep 'DP \[MFLOP/s\]' flops_dp_$i.txt | cut -d'|' -f3)
    FLOPS_DP=($FLOPS)
    echo $i ${FLOPS_DP[0]} ${FLOPS_DP[4]} >> flops_dp_derivadas.dat
    echo $i ${FLOPS_DP[1]} ${FLOPS_DP[5]} >> flops_dp_newton.dat
    echo $i ${FLOPS_DP[2]} ${FLOPS_DP[6]} >> flops_dp_matriz.dat
    echo $i ${FLOPS_DP[3]} ${FLOPS_DP[7]} >> flops_dp_sistema.dat
done