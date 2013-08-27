//
//  main.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include <iostream>




#include "PulseOsclillator.h"
#include "CoreAudioProc.h"

#if defined (__APPLE__) & defined(__MACH__)

#include "PosixThreadLauncher.h"
#include<libkern/OSAtomic.h>

#endif





int main(int argc, const char * argv[])
{
    
    PosixThreadLauncher launcher = *new PosixThreadLauncher();
    pThreadRoutine p = &SetupProc;
    launcher.LaunchThread(p);
    
 
    
    char c;
        std::cin>>c;
        
    
    
    return 0;
}


