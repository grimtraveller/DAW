//
//  Synth.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/26/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "Synth.h"
Buffer Synth::ProcessBuffer(void *inRefCon,
                     AudioUnitRenderActionFlags *ioActionFlags,
                     const AudioTimeStamp *inTimeStamp,
                     UInt32 inBusNumber,
                     UInt32 inNumberFrames,
                     AudioBufferList *ioData)
{
    
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