#include <iostream>
#include <memory>

#include "noise_power.h"
#include "noise_helper.h"


int main()
{
    NoiseHelper noisehelper = NoiseHelper();

    std::shared_ptr<NoisePower> noisepower1 = std::make_shared<NoisePower>(10e6, 5.0);
    std::shared_ptr<NoisePower> noisepower2 = std::make_shared<NoisePower>(180000000, 1.0);

    noisehelper.AddImsi(1, noisepower1);
    noisehelper.AddImsi(2, noisepower2);

    std::cout << "Access directly by IMSI:" << std::endl;
    std::cout << "Imsi:" << "Noise Power (dBm): " << noisehelper.GetNoisePowerdB(1) << " dBm" << std::endl;
    std::cout << "Noise Power (dBm): " << noisehelper.GetNoisePowerdB(2) << " dBm" << std::endl;

    std::cout << "\nIterate over all IMSIs:" << std::endl;
    for(auto imsi : noisehelper.GetAllImsiKeys())
    {
        std::cout << "Imsi:" << imsi << " Noise Power (dBm): " << noisehelper.GetNoisePowerdB(imsi) << " dBm" << std::endl;
    }

    return 0;
}
