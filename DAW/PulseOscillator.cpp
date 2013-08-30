//
//  PulseOsclillator.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "PulseOscillator.h"

PulseOscillator::PulseOscillator()
{
    SampleRate= HostSampleRate;
    PhasorTollerance=.95;
    PhasorValue=0;
    PulseWidth=0.5;

    
    

}



Sample PulseOscillator::GenerateSample(ParamVal Frequency)
{
    Sample inSample;
    inSample.Value=0;
    ParamVal period=PulseOscillator::SetupCalcs(this->SampleRate,Frequency);
    this->PhasorValue=PulseOscillator::Phasor(period);
    inSample = PulseOscillator::OSCGen(this->PhasorValue, this->PulseWidth);
    
    return inSample;
}
void PulseOscillator::SetParameter(ParamVal _value, std::string ParamID){
    
}
ParamVal PulseOscillator::GetParameter( std::string ParamID)
{
    ParamVal v = 0;
    return v;
}


ParamVal PulseOscillator::Phasor(ParamVal Period)
{
    if(PhasorValue>=PhasorTollerance)
    {
        PhasorValue=0;
    }
    else
    {
        PhasorValue+=Period;
    }
    
    return PhasorValue;
}
Sample PulseOscillator::OSCGen(ParamVal PhasorVal,ParamVal _PulseWidth)
{
    Sample s;
    if(PhasorVal<_PulseWidth)
    {
        s.Value = 1;
    }
    else if (PhasorVal>_PulseWidth)
    {
        s.Value = -1;
        
    }
    else s.Value= 0;
    
    return s;
}

ParamVal PulseOscillator::SetupCalcs(ParamVal SampleRate,ParamVal Frequency)
{
    Period=1/(SampleRate/Frequency);
    return Period;
}