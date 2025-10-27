#include <iostream>
#include "noise_power.h"


int main()
{
    // Create for 10 MHz bandwidth and 5 dB noise figure
    NoisePower noisepower(10e6, 5.0);

    std::cout << "Default B=10MHz:" << std::endl;
    std::cout << "  Noise Power (W):  " << noisepower.GetNoisePowerW() << std::endl;
    std::cout << "  Noise Power (dBm): " << noisepower.GetNoisePowerdB() << " dBm" << std::endl;

    // Use a custom bandwidth (e.g., 180 kHz for LTE RB)
    double rbBandwidth = 180e3;
    std::cout << "\nPer-RB (180 kHz):" << std::endl;
    std::cout << "  Noise Power (W):  " << noisepower.GetNoisePowerW(rbBandwidth) << std::endl;
    std::cout << "  Noise Power (dBm): " << noisepower.GetNoisePowerdB(rbBandwidth) << " dBm" << std::endl;

    return 0;
}
