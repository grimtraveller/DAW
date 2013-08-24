//
//  SVF_Filter.cpp
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/25/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "SVF_Filter.h"
SVF_FILTER::SVF_FILTER(float* _SampleRate)
{
    SampleRate = *_SampleRate;
    Delay1=0;
    Delay2=0;
}
float SVF_FILTER::Process_Sample(float Sample_Input,float Frequency,float Q,FilterState state)
{
    Q1=1/Q;
    F1=2*(3.14159)*(Frequency/SampleRate);
    F1= 2* sinf(3.14159*(Frequency/SampleRate));
    
    for(int i = 0;i<2;i++)
    {
        output_LowPass=Delay2+F1*Delay1;
        output_HighPass=Sample_Input-output_LowPass-(Q1*Delay1);
        output_BandPass=(F1*output_HighPass) +Delay1;
        output_Notch=output_HighPass+output_LowPass;
        
        Delay1=output_BandPass;
        Delay2=output_LowPass;
    }
    
    
    switch (state) {
        case FilterState::LowPass:
            return output_LowPass;
            break;
        case FilterState::HighPass:
            return output_HighPass;
            break;
        case FilterState::BandPass:
            return output_BandPass;
            break;
        case FilterState::Notch:
            return output_Notch;
            break;
        default:
            return output_LowPass;
            break;
    }
}