//
//  2ChannelMixer.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/27/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "TwoChannelMixer.h"
TwoChannelMixer::TwoChannelMixer(ParamVal _Chan1Gain,ParamVal _Chan2Gain,bool _isMono)
{
    Chan1Gain=_Chan1Gain;
    Chan2Gain=_Chan2Gain;
    isMono=_isMono;
}


BufferStereo TwoChannelMixer::ProcessBufferStereo(BufferStereo inBufferChan1, BufferStereo inBufferChan2)
{
    BufferStereo b;
    
    for (int i = 0; i<HostBufferSize; ++i) {
        b.Channel_1[i]=(inBufferChan1.Channel_1[i].Value *Chan1Gain) +(inBufferChan2.Channel_1[i].Value * Chan1Gain);
        b.Channel_2[i]=(inBufferChan1.Channel_2[i].Value *Chan2Gain) +(inBufferChan2.Channel_2[i].Value * Chan2Gain);
        
        
    }
    
    if(isMono)
    {
        for (int i =0; i<HostBufferSize; ++i) {
            b.Channel_1[i].Value = (b.Channel_1[i].Value + b.Channel_2[i].Value)*Chan1Gain;
            b.Channel_2[i].Value = b.Channel_1[i].Value;
        }
    }
    return  b;
}