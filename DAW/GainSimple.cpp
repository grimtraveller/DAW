//
//  GainSimple.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "GainSimple.h"


GainSimple::GainSimple()
{
    GainMultiplier=.707f;
}
BufferStereo GainSimple::ProcessBufferStereo(BufferStereo buffer)
{
    for (int i = 0; i<HostBufferSize; ++i) {
        buffer.Channel_1[i]=ProcessSample(buffer.Channel_1[i]);
        buffer.Channel_2[i]=ProcessSample(buffer.Channel_2[i]);
        
    }
    return buffer;
}
Sample GainSimple::ProcessSample(Sample inSample)
{
    if(GainMultiplier>=kGainMultMax)
    {
        GainMultiplier=kGainMultMax;
    }
    if(GainMultiplier<=kGainMultMin)
    {
        GainMultiplier=(float)kGainMultMin;
    }
    inSample.Value=inSample.Value * (float)GainMultiplier;
    return inSample;
}

void GainSimple::SetParameter(ParamVal _value, std::string ParamID)
{
    GainMultiplier = _value;
}
ParamVal GainSimple::GetParameter( std::string ParamID)
{
    return GainMultiplier;
}