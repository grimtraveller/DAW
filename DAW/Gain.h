//
//  Gain.h
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/26/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __pulse_osc_claass__Gain__
#define __pulse_osc_claass__Gain__

class Gain
{
public:
    
    float Process_Sample(float Input_Sample, float Gain_Multiplier);
    //float Process_Sample(float Sample_In,float Gain_Multiplier);
private:
    const float kGainMultMin=0.01;
    const float kGainMultMax=10;
};
#endif /* defined(__pulse_osc_claass__Gain__) */
