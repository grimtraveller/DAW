//
//  AudioManager.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/27/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "AudioManager.h"

AudioManager::AudioManager()
{
    
}
PulseOscillator p;

BufferStereo AudioManager::ProcessBufferStereo(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
{
    BufferStereo b;
    for (int i=0; i<inNumberFrames; ++i) {
        b.Channel_1[i] = p.GenerateSample(500);
        b.Channel_2[i] = b.Channel_1[i];
    }
    
    
    
    return b;
    /*
     double cycleLength = HostSampleRate/sineFrequency;
     int frame=0;
     for(frame = 0; frame<inNumberFrames; ++frame)
     {
     Float32 *data = (Float32*)ioData->mBuffers[0].mData;
     
     (data)[frame] = (Float32)sin(2 * M_PI *(j / cycleLength));
     
     data = (Float32*)ioData->mBuffers[1].mData;
     (data)[frame] = (Float32)sin(2 * M_PI * (j / cycleLength));
     }*/
}