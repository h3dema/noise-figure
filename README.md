# Noise Power and Noise Figure

This repo contains a simple way to **computing noise figure (NF) for LTE receivers** extracted from [NS-3](https://gitlab.com/cttc-lena/ns-3-dev/-/blob/master/src/lte/model/lte-spectrum-value-helper.cc) in *Ptr\<SpectrumValue\>
LteSpectrumValueHelper::CreateNoisePowerSpectralDensity()*.

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

  $10\log_{10}(180000) \approx 52.5527\ \Rightarrow P_N\approx -174 + 52.5527 = -121.45\ \text{dBm}$


* In ns-3 LTE, the **received SINR** for each sub-band is computed as:

$\text{SINR} = \frac{P_{\text{signal}}}{P_{\text{interference}} + P_{\text{noise}}}$

Where the **thermal noise** is internally derived as:
$P_{\text{noise,lin}} = k T_0 B \times F$

  - $k$: Boltzmann’s constant
  - $T_0 = 290 \text{K}$
  - $B$: bandwidth per subband (e.g., RB = $180 \text{kHz}$)
  - $F$: **noise figure (linear)** = $10^{NF_\text{dB}/10}$

So ns-3 already includes both the $-174\text{ dBm/Hz}$ thermal noise density and the configured Noise Figure. ns-3 automatically adds the equivalent of the equation below behind the scenes:

$P_\text{thermal} = -174\text{ dBm/Hz} + 10\log_{10}(B) + NF$


# From watts to dBW or dBm

* $P_{\text{dBW}} = 10 \log_{10}(P_{\text{W}})$

* $P_{\text{dBm}} = 10 \log_{10}(P_{\text{W}}) + 30$


That “+30” simply converts watts → milliwatts (since $1 \text{W} = 1000 \text{mW}$).


You can compute noise power in Watts before converting to dB:

$P_N(W) = 10^{\frac{-174 + 10\log_{10}(B) + NF - 30}{10}}$

(because -174 dBm/Hz + 30 dB → -204 dBW/Hz)


# C++ example

```cpp
double k = 1.38064852e-23;  // Boltzmann
double T = 290.0;           // K
double B = 10e6;            // Hz
double NF = 5.0;            // dB

double F_lin = std::pow(10.0, NF/10.0);
double noisePower_W = k * T * B * F_lin;
double noisePower_dBm = 10 * std::log10(noisePower_W) + 30;

NS_LOG_UNCOND("Noise Power: " << noisePower_dBm << " dBm");
```
