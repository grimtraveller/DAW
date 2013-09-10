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
    virtual Sample ProcessSample(Sample inSample);
    virtual Sample GenerateSample(ParamVal Frequency);
    
    virtual Buffer ProcessBuffer(Buffer inBuffer);
    virtual Buffer GenerateBuffer(ParamVal Frequency);
    
    virtual BufferStereo ProcessBufferStereo(BufferStereo inBufferStereo);
    
    virtual BufferStereo GenerateBufferStereo(ParamVal Frequency);
    virtual BufferStereo GenerateBufferStereo();

    
    //Parameters
    virtual void SetParameter(ParamVal _value, std::string ParamID);//need to figure out implementaion ideas
    virtual void SetParameter(ParamVal _value);
    virtual ParamVal GetParameter( std::string ParamID);//same here
    
};


#endif
