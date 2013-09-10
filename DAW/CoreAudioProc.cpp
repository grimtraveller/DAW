     //
//  CoreAudioProc.c
//  AudioBasicSineGenerator
//
//  Created by Alexander Zywicki on 8/22/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "CoreAudioProc.h"

Float32 phi = 0;

#pragma mark callback function


OSStatus RenderProc(void *inRefCon,
                            AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inBusNumber,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
{

    DriverStruct *player = (DriverStruct*)inRefCon;
    BufferStereo b = player->manager.ProcessBufferStereo(inRefCon,
                                                         ioActionFlags,
                                                         inTimeStamp,
                                                         inBusNumber,
                                                         inNumberFrames,
                                                         ioData);
    
    
    for (int frame = 0; frame<inNumberFrames; ++frame) {
        Float32 *data = (Float32*)ioData->mBuffers[0].mData;
        (data)[frame] = (Float32)b.Channel_1[frame].Value;
        data = (Float32*)ioData->mBuffers[1].mData;
        (data)[frame] = (Float32)b.Channel_2[frame].Value;
    }
   
    
    /* <TEST TONE>
    Float32 test[256];
    
    for(int i=0;i<256;i++)
    {
        test[i]=0.0f;
        //phi+=0.016f;
        //if(phi>1)
        //{
        //    --phi;
        //}
        //test[i]=phi;
    }
    for(int i=0;i<64;i++)
    {
        test[i]=1.0f;
    }
    for(int i=128;i<192;i++)
    {
        test[i]=1.0f;
    }
    
    for (int frame = 0; frame<inNumberFrames; ++frame) {
        Float32 *data = (Float32*)ioData->mBuffers[0].mData;
        (data)[frame] = test[frame];
        data = (Float32*)ioData->mBuffers[1].mData;
        (data)[frame] = test[frame];
    }
     </TEST TONE>*/
    //synth.process(

    /*double j = player->startingFrameCount;
    
    double cycleLength = HostSampleRate/sineFrequency;
    int frame=0;
    for(frame = 0; frame<inNumberFrames; ++frame)
    {
        Float32 *data = (Float32*)ioData->mBuffers[0].mData;
        (data)[frame] = (Float32)sin(2 * M_PI *(j / cycleLength));
     
        data = (Float32*)ioData->mBuffers[1].mData;
        (data)[frame] = (Float32)sin(2 * M_PI * (j / cycleLength));
    }*/

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

void CreateAndConnectOutputUnit(DriverStruct *player)
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
    input.inputProc = RenderProc;
    
    //add synth to rotating memory
    //player->synth=*new Synth();
    
    input.inputProcRefCon=&player;
    player->bufferSize=HostBufferSize;
    player->SampleRate=HostSampleRate;
    CheckError(AudioUnitSetProperty(player->outputUnit,
                                    kAudioUnitProperty_SetRenderCallback,
                                    kAudioUnitScope_Input,
                                    0,
                                    &input,
                                    sizeof(input)),
               "AudioUnitSetProperty failed");
    CheckError(AudioUnitSetProperty(player->outputUnit, kAudioUnitProperty_SampleRate, kAudioUnitScope_Input, 0, &player->SampleRate,sizeof(player->SampleRate)), "Failed To Set Sample Rate");
    CheckError(AudioUnitSetProperty(player->outputUnit, kAudioDevicePropertyBufferFrameSize, kAudioUnitScope_Input, 0, &player->bufferSize, sizeof(player->bufferSize)), "Failed To Set Buffer Size");
    CheckError(AudioUnitInitialize(player->outputUnit),
               "Couldn't initialize output unit");
    
}

void* SetupProc(void* data)
{
    DriverStruct player = {0};
    
    
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
