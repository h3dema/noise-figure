# noise-figure
This repo contains a simple way to **computing noise figure (NF) for LTE receivers** extracted from [NS-3]().

# What is Noise Figure

- Noise figure (linear) $F = \frac{\text{SNR} \times \text{in}}{\text{SNR} \times \text{out} }$

- Noise figure (dB): $NF = 10\log_{10}(F)$

Equivalently use equivalent noise temperature ($T_e$):

$F = 1 + \frac{T_e}{T_0},\quad T_0=290\ \text{K}$

so $NF = 10\log_{10} \left( 1 + \frac{T_e}{290} \right)$

# Thermal noise reference (useful for LTE)

Thermal noise power (dBm) for bandwidth (B) (Hz):

$P_N\text{(dBm)} = -174 \text{dBm/Hz} + 10 \log_{10}(B)$

Common examples:

* One LTE Resource Block (RB) = 180 kHz:
  
  $  10\log_{10}(180000) \approx 52.5527\ \Rightarrow P_N\approx -174 + 52.5527 = -121.45\ \text{dBm}$
  

