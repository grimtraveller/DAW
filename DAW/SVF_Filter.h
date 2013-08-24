//
//  SVF_Filter.h
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/25/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __pulse_osc_claass__SVF_Filter__
#define __pulse_osc_claass__SVF_Filter__

#include <iostream>
#include <math.h>
enum FilterState{LowPass=0,BandPass=1,HighPass=2,Notch=3};
class SVF_FILTER
{
public:
    SVF_FILTER(float* _SampleRate);
    
    float Process_Sample(float Sample_Input,float Frequency,float Q,FilterState state);
private:
    float output_LowPass;
    float output_BandPass;
    float output_HighPass;
    float output_Notch;
    float Q1;
    float F1;
    float Delay1;
    float Delay2;
    float SampleRate;
    
};
#endif /* defined(__pulse_osc_claass__SVF_Filter__) */
