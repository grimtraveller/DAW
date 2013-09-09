//
//  Filter_SVF.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "Filter_SVF.h"

Filter_SVF::Filter_SVF()
{
    //SampleRate = HostSampleRate;
    Delay1=0;
    Delay2=0;
    Frequency = 500;
    Q=1;
    state=LowPass;
    FilterPoleCount=2;
    
    
}


BufferStereo Filter_SVF::ProcessBufferStereo(BufferStereo inBufferStereo)
{
    BufferStereo b;
    for (int i=0; i<HostBufferSize; ++i) {
        b.Channel_1[i]=ProcessSample(inBufferStereo.Channel_1[i]);
        b.Channel_2[i]=ProcessSample(inBufferStereo.Channel_2[i]);
    }
    return b;
}
Sample Filter_SVF::ProcessSample(Sample inSample)
{
    Q1=1/Q;
    F1=2*(3.14159f)*(Frequency/HostSampleRate);
    F1= 2* sinf(3.14159f*(Frequency/HostSampleRate));
    
    for(int i = 0;i<FilterPoleCount;i++)
    {
        output_LowPass.Value=Delay2+F1*Delay1;
        output_HighPass.Value=inSample.Value-output_LowPass.Value-(Q1*Delay1);
        output_BandPass.Value=(F1*output_HighPass.Value) +Delay1;
        output_Notch.Value=output_HighPass.Value+output_LowPass.Value;
        
        Delay1=output_BandPass.Value;
        Delay2=output_LowPass.Value;
    }
    
    
    switch (state) {
        case LowPass:
            return output_LowPass;
            break;
        case HighPass:
            return output_HighPass;
            break;
        case BandPass:
            return output_BandPass;
            break;
        case Notch:
            return output_Notch;
            break;
        default:
            return output_LowPass;
            break;
    }

}

void Filter_SVF::SetParameter(ParamVal _value, std::string ParamID)
{
    
}

ParamVal Filter_SVF::GetParameter(std::string ParamID)
{
    ParamVal p=0;
    return p;
}

