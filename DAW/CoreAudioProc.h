//
//  CoreAudioProc.h
//  AudioBasicSineGenerator
//
//  Created by Alexander Zywicki on 8/22/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef AudioBasicSineGenerator_CoreAudioProc_h
#define AudioBasicSineGenerator_CoreAudioProc_h

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include <AudioToolbox/AudioToolbox.h>
#include <CoreAudio/CoreAudio.h>


#define sineFrequency 880.0

#pragma mark user-data struct

typedef struct MySineWavePlayer
{
    AudioUnit outputUnit;
    
    double startingFrameCount;
    
} MySineWavePlayer;

OSStatus SineWaveRenderProc(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData);

static void CheckError(OSStatus error, const char *operation);

void CreateAndConnectOutputUnit(MySineWavePlayer *player);

int Setup();

#endif
