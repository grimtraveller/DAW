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
PulseOscillator p2;
TwoChannelMixer t;
BufferStereo buf;
float f1=30;
float f2=33;
BufferStereo AudioManager::ProcessBufferStereo(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
{
    BufferStereo b;
    BufferStereo l;
    for (int i=0; i<inNumberFrames; ++i) {
        b.Channel_1[i] =p.GenerateSample(f1+=0.002);
        b.Channel_2[i] = b.Channel_1[i];
        l.Channel_1[i] =p2.GenerateSample(f2+=0.002);
        l.Channel_2[i]=l.Channel_1[i];
        
        
    }
    buf=t.ProcessBufferStereo(b, l);
    
    
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