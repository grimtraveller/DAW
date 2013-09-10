//
//  SignalPath.h
//  DAW
//
//  Created by Alexander Zywicki on 9/10/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__SignalPath__
#define __DAW__SignalPath__

#include <iostream>
#include "AudioTypes.h"
class SignalPath
{
public:
    virtual BufferStereo* ProcessBufferStereo();
    
};
#endif /* defined(__DAW__SignalPath__) */
