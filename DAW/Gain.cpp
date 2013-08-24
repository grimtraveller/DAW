//
//  Gain.cpp
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/26/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "Gain.h"

float Gain::Process_Sample(float Input_Sample, float Gain_Multiplier)
{
    float TempCurSamp=0;
    if(Gain_Multiplier>=kGainMultMax)
    {
        Gain_Multiplier=kGainMultMax;
    }
    if(Gain_Multiplier<=kGainMultMin)
    {
        Gain_Multiplier=kGainMultMin;
    }
    TempCurSamp=Input_Sample*Gain_Multiplier;
    
    return TempCurSamp;
}
