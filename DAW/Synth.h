//
//  Synth.h
//  DAW
//
//  Created by Alexander Zywicki on 8/26/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__Synth__
#define __DAW__Synth__

#include <iostream>
#include "AudioProccessing.h"
#include "CoreAudioUmbrella.h"

#define sineFrequency 880.0

class Synth
{
private:
    Buffer bufferL;
    Buffer bufferR;
public:
    Buffer ProcessBuffer(void *inRefCon,
                         AudioUnitRenderActionFlags *ioActionFlags,
                         const AudioTimeStamp *inTimeStamp,
                         UInt32 inBusNumber,
                         UInt32 inNumberFrames,
                         AudioBufferList *ioData);
};
#endif /* defined(__DAW__Synth__) */
