//
//  MasterMixer.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/29/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "MasterMixer.h"

MasterMixer::MasterMixer()
{
    Gain = 1.0f;
}
BufferStereo MasterMixer::GenerateBufferStereo(std::vector<BufferStereo> signals)
{
    BufferStereo b;
    for (int i =0; i<signals.size(); ++i) {
        b.Channel_1+=signals[i].Channel_1;
        b.Channel_2+=signals[i].Channel_2;
    }
    
    for(int i=0;i<HostBufferSize;++i)
    {
        b.Channel_1[i].Value = b.Channel_1[i].Value * Gain;
        b.Channel_2[i].Value = b.Channel_2[i].Value * Gain;
    }
    return b;
    
}
void MasterMixer::SetParameter(ParamVal _value)
{
    Gain=_value;
}