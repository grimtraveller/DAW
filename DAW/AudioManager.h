//
//  AudioManager.h
//  DAW
//
//  Created by Alexander Zywicki on 8/27/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__AudioManager__
#define __DAW__AudioManager__

#include <iostream>
#include <vector>

#include "AudioProccessing.h"
#include "AudioEntities.h"


#if defined (__APPLE__) & defined(__MACH__)
#include "CoreAudioUmbrella.h"
#endif

class AudioManager{
    
   
private:
    BufferStereo buffer;
    std::vector<AudioEntity*>Channels; //will house pointers to each channel in the daw.
    
    

    
public:
    #if defined (__APPLE__) & defined(__MACH__)
    
    BufferStereo ProcessBufferStereo(void *inRefCon,
                         AudioUnitRenderActionFlags *ioActionFlags,
                         const AudioTimeStamp *inTimeStamp,
                         UInt32 inBusNumber,
                         UInt32 inNumberFrames,
                         AudioBufferList *ioData);
    #endif

    AudioManager();
    
};
#endif /* defined(__DAW__AudioManager__) */
