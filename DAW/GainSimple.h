//
//  GainSimple.h
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__GainSimple__
#define __DAW__GainSimple__

#include <iostream>
#include "AudioProccessing.h"

#define kGainMultMin 0.01
#define kGainMultMax 10
class GainSimple:AudioEntity
{
public:
    GainSimple();
    Sample ProcessSample(Sample inSample);
    BufferStereo ProcessBufferStereo(BufferStereo buffer);
    
    void SetParameter(ParamVal _value, std::string ParamID);
    ParamVal GetParameter( std::string ParamID);
private:
    //const ParamVal kGainMultMin=0.01;
    //const ParamVal kGainMultMax=10;
    
    ParamVal GainMultiplier;
};
#endif /* defined(__DAW__GainSimple__) */
