//
//  PosixThreadLauncher.cpp
//  threading?
//
//  Created by Alexander Zywicki on 8/19/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "PosixThreadLauncher.h"

void PosixThreadLauncher::LaunchThread(pThreadRoutine ThreadRoutine)
{
    pthread_attr_t attr;
    pthread_t posixThreadID;
    int returnVal;
    
    returnVal=pthread_attr_init(&attr);
    
    assert(!returnVal);
    returnVal=pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  
    assert(!returnVal);
    
    int threadError = pthread_create(&posixThreadID, &attr, ThreadRoutine, NULL);
    returnVal = pthread_attr_destroy(&attr);
    assert(!returnVal);
    if(threadError !=0)
    {
        //handle error.
        printf("thread error\n\r");//this is not handling the error just telling me there is one
    }
    
    char message;
    returnVal=pthread_join(posixThreadID, (void**)&message);
    assert(!returnVal);
    
    
}
