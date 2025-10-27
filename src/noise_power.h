#ifndef NOISE_CALCULATOR_H
#define NOISE_CALCULATOR_H

#include <cmath>

class NoisePower
{
public:
    // Constructor: B in Hz, NF in dB
    NoisePower(double bandwidthHz = 1.0e6, double noiseFigure_dB = 5.0);

    // Setters
    void SetBandwidth(double bandwidthHz);
    void SetNoiseFigure(double noiseFigure_dB);

    // Get noise power in watts (optional bandwidth override)
    double GetNoisePowerW(double bandwidthHz = -1.0) const;

    // Get noise power in dBm (optional bandwidth override)
    double GetNoisePowerdB(double bandwidthHz = -1.0) const;

private:
    double m_bandwidthHz;
    double m_noiseFigure_dB;
};

#endif // NOISE_CALCULATOR_H
