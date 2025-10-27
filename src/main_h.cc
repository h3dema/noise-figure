#include <iostream>
#include <memory>

#include "noise_figure.h"
#include "noise_helper.h"


int main()
{
    NoiseHelper noisehelper = NoiseHelper();

    std::shared_ptr<NoiseFigure> noisefigure1 = std::make_shared<NoiseFigure>(10e6, 5.0);
    std::shared_ptr<NoiseFigure> noisefigure2 = std::make_shared<NoiseFigure>(180000000, 1.0);

    noisehelper.AddImsi(1, noisefigure1);
    noisehelper.AddImsi(2, noisefigure2);

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
