#include <iostream>
#include "noise_figure.h"


int main()
{
    // Create for 10 MHz bandwidth and 5 dB noise figure
    NoiseFigure noisefigure(10e6, 5.0);

    std::cout << "Default B=10MHz:" << std::endl;
    std::cout << "  Noise Power (W):  " << noisefigure.GetNoisePowerW() << std::endl;
    std::cout << "  Noise Power (dBm): " << noisefigure.GetNoisePowerdB() << " dBm" << std::endl;

    // Use a custom bandwidth (e.g., 180 kHz for LTE RB)
    double rbBandwidth = 180e3;
    std::cout << "\nPer-RB (180 kHz):" << std::endl;
    std::cout << "  Noise Power (W):  " << noisefigure.GetNoisePowerW(rbBandwidth) << std::endl;
    std::cout << "  Noise Power (dBm): " << noisefigure.GetNoisePowerdB(rbBandwidth) << " dBm" << std::endl;

    return 0;
}
