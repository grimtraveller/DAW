//
//  CoreAudioProc.h
//  AudioBasicSineGenerator
//
//  Created by Alexander Zywicki on 8/22/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef AudioBasicSineGenerator_CoreAudioProc_h
#define AudioBasicSineGenerator_CoreAudioProc_h

#include "AudioProccessing.h"   
#include "CoreaudioUmbrella.h"







#pragma mark user-data struct

typedef struct MySineWavePlayer
{
    AudioUnit outputUnit;
    UInt32 bufferSize;
    
        
} MySineWavePlayer;

OSStatus SineWaveRenderProc(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData);

static void CheckError(OSStatus error, const char *operation);

void CreateAndConnectOutputUnit(MySineWavePlayer *player);

void* SetupProc(void* data);

#endif
