//
//  AudioManager.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/27/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "AudioManager.h"
#include <ctime>
AudioManager::AudioManager()
{
    
}
PulseOscillator p;


static BufferStereo buf;
GainSimple g;

ParamVal f1=1000;


BufferStereo AudioManager::ProcessBufferStereo(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
{
    
    buf=p.GenerateBufferStereo(f1);
    buf=g.ProcessBufferStereo(buf);
    
    return buf;
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