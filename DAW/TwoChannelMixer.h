//
//  2ChannelMixer.h
//  DAW
//
//  Created by Alexander Zywicki on 8/27/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW___ChannelMixer__
#define __DAW___ChannelMixer__

#include <iostream>
#include "AudioProccessing.h"

class TwoChannelMixer:AudioEntity
{
public:
    TwoChannelMixer(ParamVal _Chan1Gain,ParamVal _Chan2Gain,bool _isMono);
    
    BufferStereo ProcessBufferStereo(BufferStereo inBufferChan1,BufferStereo inBufferChan2);
private:
    ParamVal Chan1Gain,Chan2Gain;
    bool isMono;
};
#endif /* defined(__DAW___ChannelMixer__) */
