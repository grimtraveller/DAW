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
    GainMultiplier=1;
}
Sample GainSimple::ProcessSample(Sample inSample)
{
    if(GainMultiplier>=kGainMultMax)
    {
        GainMultiplier=kGainMultMax;
    }
    if(GainMultiplier<=kGainMultMin)
    {
        GainMultiplier=kGainMultMin;
    }
    inSample.Value=inSample.Value * GainMultiplier;
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