//
//  AudioEntity.c
//  DAW
//
//  Created by Alexander Zywicki on 8/29/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "AudioEntity.h"

Sample AudioEntity::ProcessSample(Sample inSample)
{
    return inSample;
}
Sample AudioEntity::GenerateSample(ParamVal Frequency)
{
    Sample s;
    return s;
}

Buffer AudioEntity::ProcessBuffer(Buffer inBuffer)
{
    return inBuffer;
}
Buffer AudioEntity::GenerateBuffer(ParamVal Frequency)
{
    Buffer b;
    return b;
}

BufferStereo AudioEntity::ProcessBufferStereo(BufferStereo inBufferStereo)
{
    return  inBufferStereo;
}
BufferStereo AudioEntity::GenerateBufferStereo(ParamVal Frequency)
{
    BufferStereo bs;
    return bs;
}

//Parameters
void AudioEntity::SetParameter(ParamVal _value, std::string ParamID)//need to figure out implementaion ideas
{
    
}
ParamVal AudioEntity::GetParameter( std::string ParamID)//same here
{
    return 0;
}
