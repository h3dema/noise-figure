# noise-figure
This repo contains a simple way to **computing noise figure (NF) for LTE receivers** extracted from [NS-3]().

# What is Noise Figure

- Noise figure (linear) $F = \frac{\text{SNR} * \text{in}}{\text{SNR} * \text{out} }$

- Noise figure (dB): $NF = 10\log_{10}(F)$

Equivalently use equivalent noise temperature (T_e):

$F = 1 + \frac{T_e}{T_0},\quad T_0=290\ \text{K}$

so $NF = 10\log_{10}!\left(1+\frac{T_e}{290}\right)$

