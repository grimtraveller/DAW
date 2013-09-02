//
//  Filter_SVF.h
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__Filter_SVF__
#define __DAW__Filter_SVF__

#include <iostream>
#include <math.h>
#include "AudioProccessing.h"
enum FilterState{LowPass=0,BandPass=1,HighPass=2,Notch=3};
class Filter_SVF:AudioEntity
{
public:
    Filter_SVF();
    
    Sample ProcessSample(Sample inSample);
    BufferStereo ProcessBufferStereo(BufferStereo inBufferStereo);
    
    void SetParameter(ParamVal _value, std::string ParamID);
    ParamVal GetParameter( std::string ParamID);
protected:
    Sample output_LowPass;
    Sample output_BandPass;
    Sample output_HighPass;
    Sample output_Notch;
    ParamVal Q1;
    ParamVal F1;
    ParamVal Delay1;
    ParamVal Delay2;
    //ParamVal SampleRate;
    ParamVal Frequency;
    ParamVal FilterPoleCount;
    
    ParamVal Q;
    FilterState state;
    
};
#endif /* defined(__DAW__Filter_SVF__) */
