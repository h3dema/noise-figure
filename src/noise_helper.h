#ifndef NOISE_HELPER_H
#define NOISE_HELPER_H

#include <unordered_map>
#include <memory>
#include <iostream>
#include <vector>

#include "noise_figure.h"


class NoiseHelper
{
public:
    // defaultBandwidthHz: default B used by NoiseFigure when computing noise power
    // defaultNoiseFigure_dB: fallback NF if IMSI not present
    NoiseHelper();

    // --- Add / Update APIs ---

    // Accept raw pointer and take ownership (shared_ptr wrapper)
    //    Caller must NOT delete the pointer after passing it here.
    void AddImsi(uint64_t imsi, std::shared_ptr<NoiseFigure>& noiseFigurePtr);

    // Remove IMSI mapping
    bool RemoveImsi(uint64_t imsi);

    // Check if IMSI exists
    bool HasImsi(uint64_t imsi) const;

    // Return pointer to NoiseFigure for IMSI (nullptr if not found)
    // Note: returns raw pointer for convenience; ownership remains with NoiseHelper
    std::shared_ptr<NoiseFigure> GetNoiseFigurePtr(uint64_t imsi) const;

    // Compute noise power (W) for IMSI, optional bandwidth override
    double GetNoisePowerW(uint64_t imsi, double bandwidthHz = -1.0) const;

    // Compute noise power (dBm) for IMSI, optional bandwidth override
    double GetNoisePowerdB(uint64_t imsi, double bandwidthHz = -1.0) const;

    std::vector<uint64_t> GetAllImsiKeys() const;
    // Print contents (for debug)
    void PrintAll() const;

private:
    std::unordered_map<uint64_t, std::shared_ptr<NoiseFigure>> m_noiseFigures;
};

#endif // NOISE_HELPER_H
