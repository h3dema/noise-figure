#include <cmath>
#include "noise_figure.h"


    // Constructor: B in Hz, NF in dB
NoiseFigure::NoiseFigure(double bandwidthHz, double noiseFigure_dB)
        : m_bandwidthHz(bandwidthHz), m_noiseFigure_dB(noiseFigure_dB)
{}

    // Setters
void NoiseFigure::SetBandwidth(double bandwidthHz) { m_bandwidthHz = bandwidthHz; }

void NoiseFigure::SetNoiseFigure(double noiseFigure_dB) { m_noiseFigure_dB = noiseFigure_dB; }

// Get noise power in watts (optional bandwidth override)
double NoiseFigure::GetNoisePowerW(double bandwidthHz) const
{
    double B = (bandwidthHz > 0.0) ? bandwidthHz : m_bandwidthHz;
    const double k = 1.38064852e-23; // Boltzmann constant [J/K]
    const double T = 290.0;          // Reference temperature [K]
    double F = std::pow(10.0, m_noiseFigure_dB / 10.0);
    return k * T * B * F;
}

// Get noise power in dBm (optional bandwidth override)
double NoiseFigure::GetNoisePowerdB(double bandwidthHz) const
{
    double noiseW = GetNoisePowerW(bandwidthHz);
    return 10.0 * std::log10(noiseW) + 30.0; // W → dBm
}
