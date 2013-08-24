//
//  PulseOsc.cpp
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/21/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "PulseOsc.h"
PulseOsc::PulseOsc(float* _sampleRate,float _phasorTollerance,float _pulseWidth)
{
        SampleRate= *_sampleRate;
    PhasorTollerance=_phasorTollerance;
    PhasorValue=0;
    PulseWidth=_pulseWidth;
}

float PulseOsc::ProcessCycle(float _noteFrequency, float _pulseWidth)
{
    float temp_Period=0;
    temp_Period=PulseOsc::SetupCalcs(this->SampleRate, _noteFrequency);
    PhasorValue = PulseOsc::Phasor(temp_Period);
    float temp_OscVal=PulseOsc::PulseOscillatorCalc(PhasorValue, _pulseWidth);
    return temp_OscVal;
    
}


float PulseOsc::SetupCalcs(float SampleRate, float Frequency)
{
    
    Period=1/(SampleRate/Frequency);
    return Period;
}
float PulseOsc::Phasor(float _Period)
{
    if(PhasorValue>=PhasorTollerance)
    {
        PhasorValue=0;
    }
    else
    {
        PhasorValue+=_Period;
    }
    
    return PhasorValue;
    
}
float PulseOsc::PulseOscillatorCalc(float PhasorVal,float PW)
{
    if(PhasorVal<PW)
    {
        return 1;
    }
    else if (PhasorVal>PW)
    {
        return -1;
        
    }
    else return 0;
    }
float PulseOsc::SinOscillatorCalc(float PhasorVal)
{
    return sinf((2*3.14159)*PhasorVal); // Sin Wave Oscillator. Not Sure If Accurate yet.
}


PulseOsc::~PulseOsc()
{
    
    
}