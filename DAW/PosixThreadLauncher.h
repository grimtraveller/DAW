//
//  PosixThreadLauncher.h
//  threading?
//
//  Created by Alexander Zywicki on 8/19/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __threading___PosixThreadLauncher__
#define __threading___PosixThreadLauncher__

#include <iostream>
#include <pthread.h>
#include <assert.h>
#include <CoreFoundation/CoreFoundation.h>

typedef void* (*pThreadRoutine)(void*);

class PosixThreadLauncher {
       
public:
   
    pthread_t LaunchThread(pThreadRoutine ThreadRoutine);
    pthread_t LaunchThread(pThreadRoutine ThreadRoutine, void * args);
    void CatchThread(pthread_t threadID);

};

#endif /* defined(__threading___PosixThreadLauncher__) */
