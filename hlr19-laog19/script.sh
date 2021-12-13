#!/bin/bash

# Executando comandos para poder utilizar o likwid
echo "performance" | sudo tee /sys/devices/system/cpu/cpufreq/policy3/scaling_governor

#Compilando programas
make all
clear

# Rodando testes
./broyden.sh

# Gerando arquivos .dat
#echo "Gerando arquivos de dados"
#./gera_dados.sh
#clear

# Limpando arquivos temporários
make clean
#rm l3*.txt
#rm l2*.txt
#rm flops*.txt

# Gerando gráficos
#echo "Gerando gráficos"
#gnuplot ./plot_dados.gp
#rm *.dat
#clear

# Retornando para frequência original
clear
echo "Frequência do processador configurada para modo:"
echo "powersave" | sudo tee /sys/devices/system/cpu/cpufreq/policy3/scaling_governor 