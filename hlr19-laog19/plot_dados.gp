# Configurações gerais
set terminal pngcairo size 1024,512
set xlabel "N"

# Método de Newton

# Gráfico de L3
set output "l3_newton.png"
set title "Largura de Banda de L3"
set ylabel "bandwidth [MBytes/s]"
plot "l3_newton.dat" using 2:xticlabels(1) title "Sem otimização" lt 7 lc 7 w lp , \
     "l3_newton.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de L2 miss ratio
set output "l2cache_newton.png"
set title "Razão de cache miss de L2"
set ylabel "L2 cache miss ratio"
plot "l2cache_newton.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "l2cache_newton.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de FLOPS_DP e FLOPS_AVX
set output "flops_dp_newton.png"
set title "Número de Operações de Ponto Flutuante"
set ylabel "MFLOP/s"
plot "flops_dp_newton.dat" using 2:xticlabels(1) title "Sem otimização DP" lc 7 lt 7 w lp , \
     "flops_dp_newton.dat" using 3:xticlabels(1) title "Sem otimização AVX" lc 7 lt 7 dt 2 w lp , \
     "flops_dp_newton.dat" using 4:xticlabels(1) title "Com otimização DP" lc 6 lt 7 w lp , \
     "flops_dp_newton.dat" using 5:xticlabels(1) title "Com otimização AVX" lc 6 lt 7 dt 2 w lp

# Gráfico de tempo
set output "tempo_newton.png"
set title "Tempo de Execução das Funções"
set ylabel "tempo [ms]"
set logscale y
plot "tempo_newton.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "tempo_newton.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp
unset logscale y

#Derivadas parciais

# Gráfico de L3
set output "l3_derivadas.png"
set title "Largura de Banda de L3"
set ylabel "bandwidth [MBytes/s]"
plot "l3_derivadas.dat" using 2:xticlabels(1) title "Sem otimização" lt 7 lc 7 w lp , \
     "l3_derivadas.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de L2 miss ratio
set output "l2cache_derivadas.png"
set title "Razão de cache miss de L2"
set ylabel "L2 cache miss ratio"
plot "l2cache_derivadas.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "l2cache_derivadas.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de FLOPS_DP e FLOPS_AVX
set output "flops_dp_derivadas.png"
set title "Número de Operações de Ponto Flutuante"
set ylabel "MFLOP/s"
plot "flops_dp_derivadas.dat" using 2:xticlabels(1) title "Sem otimização DP" lc 7 lt 7 w lp , \
     "flops_dp_derivadas.dat" using 3:xticlabels(1) title "Sem otimização AVX" lc 7 lt 7 dt 2 w lp , \
     "flops_dp_derivadas.dat" using 4:xticlabels(1) title "Com otimização DP" lc 6 lt 7 w lp , \
     "flops_dp_derivadas.dat" using 5:xticlabels(1) title "Com otimização AVX" lc 6 lt 7 dt 2 w lp

# Gráfico de tempo
set output "tempo_derivadas.png"
set title "Tempo de Execução das Funções"
set ylabel "tempo [ms]"
set logscale y
plot "tempo_derivadas.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "tempo_derivadas.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp
unset logscale y

# Matriz jacobiana

# Gráfico de L3
set output "l3_jacobiana.png"
set title "Largura de Banda de L3"
set ylabel "bandwidth [MBytes/s]"
plot "l3_matriz.dat" using 2:xticlabels(1) title "Sem otimização" lt 7 lc 7 w lp , \
     "l3_matriz.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de L2 miss ratio
set output "l2cache_jacobiana.png"
set title "Razão de cache miss de L2"
set ylabel "L2 cache miss ratio"
plot "l2cache_matriz.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "l2cache_matriz.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de FLOPS_DP e FLOPS_AVX
set output "flops_dp_jacobiana.png"
set title "Número de Operações de Ponto Flutuante"
set ylabel "MFLOP/s"
plot "flops_dp_matriz.dat" using 2:xticlabels(1) title "Sem otimização DP" lc 7 lt 7 w lp , \
     "flops_dp_matriz.dat" using 3:xticlabels(1) title "Sem otimização AVX" lc 7 lt 7 dt 2 w lp , \
     "flops_dp_matriz.dat" using 4:xticlabels(1) title "Com otimização DP" lc 6 lt 7 w lp , \
     "flops_dp_matriz.dat" using 5:xticlabels(1) title "Com otimização AVX" lc 6 lt 7 dt 2 w lp

# Gráfico de tempo
set output "tempo_jacobiana.png"
set title "Tempo de Execução das Funções"
set ylabel "tempo [ms]"
set logscale y
plot "tempo_matriz.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "tempo_matriz.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp
unset logscale y

# Sistema linear

# Gráfico de L3
set output "l3_sistema_linear.png"
set title "Largura de Banda de L3"
set ylabel "bandwidth [MBytes/s]"
plot "l3_sistema.dat" using 2:xticlabels(1) title "Sem otimização" lt 7 lc 7 w lp , \
     "l3_sistema.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de L2 miss ratio
set output "l2cache_sistema_linear.png"
set title "Razão de cache miss de L2"
set ylabel "L2 cache miss ratio"
plot "l2cache_sistema.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "l2cache_sistema.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp

# Gráfico de FLOPS_DP e FLOPS_AVX
set output "flops_dp_sistema_linear.png"
set title "Número de Operações de Ponto Flutuante"
set ylabel "MFLOP/s"
plot "flops_dp_sistema.dat" using 2:xticlabels(1) title "Sem otimização DP" lc 7 lt 7 w lp , \
     "flops_dp_sistema.dat" using 3:xticlabels(1) title "Sem otimização AVX" lc 7 lt 7 dt 2 w lp , \
     "flops_dp_sistema.dat" using 4:xticlabels(1) title "Com otimização DP" lc 6 lt 7 w lp , \
     "flops_dp_sistema.dat" using 5:xticlabels(1) title "Com otimização AVX" lc 6 lt 7 dt 2 w lp

# Gráfico de tempo
set output "tempo_sistema_linear.png"
set title "Tempo de Execução das Funções"
set ylabel "tempo [ms]"
set logscale y
plot "tempo_sistema.dat" using 2:xticlabels(1) title "Sem otimização" lc 7 lt 7 w lp , \
     "tempo_sistema.dat" using 3:xticlabels(1) title "Com otimização" lc 6 lt 7 w lp
unset logscale y