//
//  Parallel.h
//  DAW
//
//  Created by Alexander Zywicki on 9/10/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__Parallel__
#define __DAW__Parallel__

#include <vector>
#include "SignalPath.h"
class Parallel:SignalPath
{
public:
    SignalPath* InputSignalPaths[MaxChannels];
    int InputSignalPathCount=0;
    BufferStereo OutputBufferStereo;
    
    Parallel();
    BufferStereo* ProcessBufferStereo();
    void ClearInputSignalPaths();
    void AddInputSignalPath(SignalPath* InputSignalPathIn);
};



#endif /* defined(__DAW__Parallel__) */
