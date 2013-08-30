//
//  Channel.h
//  DAW
//
//  Created by Alexander Zywicki on 8/29/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__Channel__
#define __DAW__Channel__

#include <iostream>
#include <vector>
#include "AudioProccessing.h"
class Channel:AudioEntity
{
public:
    Channel();
    
     BufferStereo ProcessBufferStereo(BufferStereo inBufferStereo);
     BufferStereo GenerateBufferStereo();

private:
    
protected:
    std::vector<AudioEntity*> Components;
};
#endif /* defined(__DAW__Channel__) */
