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

BufferStereo PulseOscillator::GenerateBufferStereo(ParamVal Frequency, BufferStereo* inBufferStereo)
{
    
    for (int i=0; i<HostBufferSize; ++i) {
        inBufferStereo->Channel_1[i]=GenerateSample(Frequency,&inBufferStereo->Channel_1[i]);
        inBufferStereo->Channel_2[i] = inBufferStereo->Channel_1[i];
    }
    return *inBufferStereo;
}

Sample PulseOscillator::GenerateSample(ParamVal Frequency,Sample* inSamp)
{
    
   
    ParamVal period=PulseOscillator::SetupCalcs(this->SampleRate,Frequency);
    this->PhasorValue=PulseOscillator::Phasor(period);
    inSamp = PulseOscillator::OSCGen(this->PhasorValue, this->PulseWidth,inSamp);
    //inSample.Value=PhasorValue;
    return *inSamp;
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
        PhasorValue--;
    }
    
    return PhasorValue;
}
Sample* PulseOscillator::OSCGen(ParamVal PhasorVal,ParamVal _PulseWidth,Sample* insamp)
{
    
    if(PhasorVal<_PulseWidth)
    {
        insamp->Value = 1;
        return insamp;
    }
    else if (PhasorVal>_PulseWidth)
    {
        insamp->Value = -1;
        return insamp;
        
    }
    else insamp->Value= 0;
    
    //return s;
    //s.Value=PhasorVal;
    return insamp;
    
}

ParamVal PulseOscillator::SetupCalcs(ParamVal SampleRate,ParamVal Frequency)
{
    Period=1/(SampleRate/Frequency);
    return Period;
}