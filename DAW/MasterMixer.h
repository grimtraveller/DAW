//
//  MasterMixer.h
//  DAW
//
//  Created by Alexander Zywicki on 8/29/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__MasterMixer__
#define __DAW__MasterMixer__

#include <iostream>
#include "AudioProccessing.h"

class MasterMixer:AudioEntity
{
public:
    MasterMixer();
    void SetParameter(ParamVal _value);
    BufferStereo GenerateBufferStereo(std::vector<BufferStereo> signals);
protected:
    ParamVal Gain;
};

#endif /* defined(__DAW__MasterMixer__) */
