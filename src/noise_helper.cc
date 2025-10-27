
#include "noise_helper.h"

using namespace std;

// NoiseHelper manages IMSI -> NoiseFigure mappings.
// defaultBandwidthHz: default B used by NoiseFigure when computing noise power
// defaultNoiseFigure_dB: fallback NF if IMSI not present

NoiseHelper::NoiseHelper()
        : m_noiseFigures(std::unordered_map<uint64_t, std::shared_ptr<NoiseFigure>>())
{}

// --- Add / Update APIs --- shared_ptr (shared ownership)
void NoiseHelper::AddImsi(uint64_t imsi, std::shared_ptr<NoiseFigure>& noiseFigurePtr)
{
    if (!noiseFigurePtr) return;
    m_noiseFigures[imsi] = noiseFigurePtr;
}


// Remove IMSI mapping
bool NoiseHelper::RemoveImsi(uint64_t imsi)
{
    return m_noiseFigures.erase(imsi) > 0;
}

// Check if IMSI exists
bool NoiseHelper::HasImsi(uint64_t imsi) const
{
    return m_noiseFigures.find(imsi) != m_noiseFigures.end();
}

// Return pointer to NoiseFigure for IMSI (nullptr if not found)
// Note: returns shared_ptr so ownership can be shared; returns empty shared_ptr if not found
std::shared_ptr<NoiseFigure> NoiseHelper::GetNoiseFigurePtr(uint64_t imsi) const
{
    auto it = m_noiseFigures.find(imsi);
    if (it != m_noiseFigures.end())
    {
        return it->second;
    }
    return nullptr;
}

// Compute noise power (W) for IMSI, optional bandwidth override
double NoiseHelper::GetNoisePowerW(uint64_t imsi, double bandwidthHz) const
{
    const std::shared_ptr<NoiseFigure> nf = GetNoiseFigurePtr(imsi);
    if (!nf) return 0.0;
    double nf_W = nf->GetNoisePowerW(bandwidthHz);
    return nf_W;
}
// Compute noise power (dBm) for IMSI, optional bandwidth override
double NoiseHelper::GetNoisePowerdB(uint64_t imsi, double bandwidthHz) const
{
    const std::shared_ptr<NoiseFigure> nf = GetNoiseFigurePtr(imsi);
    if (!nf) return 0.0;
    double nf_dB = nf->GetNoisePowerdB(bandwidthHz);
    return nf_dB;
}

std::vector<uint64_t> NoiseHelper::GetAllImsiKeys() const {
    std::vector<uint64_t> keys;
    keys.reserve(m_noiseFigures.size());
    for (const auto& pair : m_noiseFigures) {
        keys.push_back(pair.first);
    }
    return keys;
}

// Print contents (for debug)
void NoiseHelper::PrintAll() const
{
    for (const auto& kv : m_noiseFigures)
    {
        std::cout << "  IMSI: " << kv.first
                  << "  NF(dB): " << kv.second->GetNoisePowerdB() << "\n";
    }
}
