//
//  Gain.h
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/26/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __pulse_osc_claass__Gain__
#define __pulse_osc_claass__Gain__

#define kGainMultMin 0.01
#define kGainMultMax 10
class Gain
{
public:
    
    float Process_Sample(float Input_Sample, float Gain_Multiplier);
    //float Process_Sample(float Sample_In,float Gain_Multiplier);
private:
    //const float kGainMultMin=.01f;
    //const float kGainMultMax=10f;
};
#endif /* defined(__pulse_osc_claass__Gain__) */
