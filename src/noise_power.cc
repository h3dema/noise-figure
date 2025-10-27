#include <cmath>
#include "noise_power.h"


/**
 * Constructor for NoiseFigure.
 * @param bandwidthHz The default bandwidth of the noise in Hz. Used when computing noise power and the bandwidth is not specified.
 * @param noiseFigure_dB The noise figure in dB.
 */
 NoisePower::NoisePower(double bandwidthHz, double noiseFigure_dB)
        : m_bandwidthHz(bandwidthHz), m_noiseFigure_dB(noiseFigure_dB)
{}

    // Setters
void NoisePower::SetBandwidth(double bandwidthHz) { m_bandwidthHz = bandwidthHz; }

void NoisePower::SetNoiseFigure(double noiseFigure_dB) { m_noiseFigure_dB = noiseFigure_dB; }

// Get noise power in watts (optional bandwidth override)
double NoisePower::GetNoisePowerW(double bandwidthHz) const
{
    double B = (bandwidthHz > 0.0) ? bandwidthHz : m_bandwidthHz;
    const double k = 1.38064852e-23; // Boltzmann constant [J/K]
    const double T = 290.0;          // Reference temperature [K]
    double F = std::pow(10.0, m_noiseFigure_dB / 10.0);
    return k * T * B * F;
}

// Get noise power in dBm (optional bandwidth override)
double NoisePower::GetNoisePowerdB(double bandwidthHz) const
{
    double noiseW = GetNoisePowerW(bandwidthHz);
    return 10.0 * std::log10(noiseW) + 30.0; // W → dBm
}
