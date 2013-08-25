//
//  main.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>


#include "PulseOsclillator.h"
#include "CoreAudioProc.h"
#include "PosixThreadLauncher.h"

static const ParamVal SampleRate = 44100;




int main(int argc, const char * argv[])
{
    
    PosixThreadLauncher launcher = *new PosixThreadLauncher();
    pThreadRoutine p = &SetupProc;
    launcher.LaunchThread(p);
    
 
    
    char c;
        std::cin>>c;
        
    
    
    return 0;
}


