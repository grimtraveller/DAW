//
//  CoreAudioProc.c
//  AudioBasicSineGenerator
//
//  Created by Alexander Zywicki on 8/22/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "CoreAudioProc.h"



#pragma mark callback function

OSStatus SineWaveRenderProc(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
{
    MySineWavePlayer *player = (MySineWavePlayer*)inRefCon;
    
    double j = player->startingFrameCount;
    double cycleLength = 44100./sineFrequency;
    int frame=0;
    for(frame = 0; frame<inNumberFrames; ++frame)
    {
        Float32 *data = (Float32*)ioData->mBuffers[0].mData;
        (data)[frame] = (Float32)sin(2 * M_PI *(j / cycleLength));
        
        data = (Float32*)ioData->mBuffers[1].mData;
        (data)[frame] = (Float32)sin(2 * M_PI * (j / cycleLength));
        
        j+=1.0;
        
        if(j>cycleLength)
            j-=cycleLength;
    }
    player->startingFrameCount=j;
    return noErr;
}

#pragma mark utility functions

static void CheckError(OSStatus error, const char *operation) {
    if (error == noErr) return;
    char errorString[20];
    // See if it appears to be a 4-char-code
    *(UInt32 *)(errorString + 1) = CFSwapInt32HostToBig(error);
    if (isprint(errorString[1]) && isprint(errorString[2]) && isprint(errorString[3]) && isprint(errorString[4])) { errorString[0] = errorString[5] = '\''; errorString[6] = '\0';
        
    }
    else
    {
        // No, format it as an integer
        sprintf(errorString, "%d", (int)error);
        fprintf(stderr, "Error: %s (%s)\n", operation, errorString);
        exit(1);
    }
}

void CreateAndConnectOutputUnit(MySineWavePlayer *player)
{
    AudioComponentDescription outputcd = {0};
    outputcd.componentType = kAudioUnitType_Output;
    outputcd.componentSubType = kAudioUnitSubType_DefaultOutput;
    outputcd.componentManufacturer = kAudioUnitManufacturer_Apple;
    
    AudioComponent comp = AudioComponentFindNext(NULL, &outputcd);
    if (comp == NULL) {
        printf("Can't get output unit");
        exit(-1);
    }
    CheckError(AudioComponentInstanceNew(comp,
                                         &player->outputUnit),
               "Couldn't open component for outputUnit");
    
    AURenderCallbackStruct input;
    input.inputProc = SineWaveRenderProc;
    input.inputProcRefCon=&player;
    
    CheckError(AudioUnitSetProperty(player->outputUnit,
                                    kAudioUnitProperty_SetRenderCallback,
                                    kAudioUnitScope_Input,
                                    0,
                                    &input,
                                    sizeof(input)),
               "AudioUnitSetProperty failed");
    
    CheckError(AudioUnitInitialize(player->outputUnit),
               "Couldn't initialize output unit");
    
}

int Setup()
{
    MySineWavePlayer player = {0};
    
    CreateAndConnectOutputUnit(&player);
    
    CheckError(AudioOutputUnitStart(player.outputUnit),"Couldn't start output unit");
    
    while (true) {
        continue;
    }
    
cleanup:
    
    AudioOutputUnitStop(player.outputUnit);
    AudioUnitUninitialize(player.outputUnit);
    AudioComponentInstanceDispose( (player.outputUnit));
    
    
    return 0;
}
