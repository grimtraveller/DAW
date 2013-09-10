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
    PhasorTollerance=1;
    PhasorValue=0;
    PulseWidth=0.5f;
    
    


}

BufferStereo PulseOscillator::GenerateBufferStereo(ParamVal Frequency)
{
    
    for (int i=0; i<HostBufferSize; ++i) {
        buffer.Channel_1[i]=GenerateSample(Frequency);
        buffer.Channel_2[i] = buffer.Channel_1[i];
    }
    return buffer;
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
    PhasorValue+=Period;
    if(PhasorValue>=PhasorTollerance)
    {
        PhasorValue-=1;
    }
    
    return PhasorValue;
}
Sample PulseOscillator::OSCGen(ParamVal PhasorVal,ParamVal _PulseWidth)
{
    Sample s;
    if(PhasorVal<_PulseWidth)
    {
        s.Value = 1;
        return s;
    }
    else if (PhasorVal>_PulseWidth)
    {
        s.Value = -1;
        return s;
        
    }
    else s.Value= 0;
    
    //return s;
    //s.Value=PhasorVal;
    return s;
    
}

ParamVal PulseOscillator::SetupCalcs(ParamVal SampleRate,ParamVal Frequency)
{
    Period=1/(SampleRate/Frequency);
    return Period;
}