//
//  main.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif



#include "PulseOscillator.h"
#include "CoreAudioProc.h"
#include "GUI_Manager.h"
#if defined (__APPLE__) & defined(__MACH__)

#include "PosixThreadLauncher.h"
#include<libkern/OSAtomic.h>

#endif





int main(int argc,  char ** argv)
{
    
    PosixThreadLauncher launcher = *new PosixThreadLauncher();
    pThreadRoutine p = &SetupProc;
    launcher.LaunchThread(p);
    SetupGUI(argc, argv);
         
    
    char c;
        std::cin>>c;
        
    
    
    return 0;
}


