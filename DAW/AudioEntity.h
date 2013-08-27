//
//  AudioEntity.h
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef DAW_AudioEntity_h
#define DAW_AudioEntity_h

#include "AudioTypes.h"
#include <string>

class AudioEntity
{
public:
    //Process
    virtual Sample ProcessSample(Sample inSample)=0;
    virtual Sample GenerateSample(ParamVal Frequency)=0;
    
    virtual Buffer ProcessBuffer(Buffer inBuffer)=0;
    virtual Buffer GenerateBuffer(ParamVal Frequency)=0;
    
    virtual BufferStereo ProcessBufferStereo(BufferStereo inBufferStereo)=0;
    virtual BufferStereo GenerateBufferStereo(ParamVal Frequency)=0;
    
    //Parameters
    virtual void SetParameter(ParamVal _value, std::string ParamID)=0;//need to figure out implementaion ideas
    virtual ParamVal GetParameter( std::string ParamID)=0;//same here
    
};


#endif
