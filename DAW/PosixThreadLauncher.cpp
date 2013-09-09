//
//  PosixThreadLauncher.cpp
//  threading?
//
//  Created by Alexander Zywicki on 8/19/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "PosixThreadLauncher.h"

void PosixThreadLauncher::CatchThread(pthread_t threadID)
{
    char m = 'T';
    char* message=&m;
    pthread_join(threadID, (void**)message);
}

pthread_t PosixThreadLauncher::LaunchThread(pThreadRoutine ThreadRoutine)
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
    return posixThreadID;
    /*char message;
    returnVal=pthread_join(posixThreadID, (void**)&message);
    assert(!returnVal);*/
    
    
}
pthread_t PosixThreadLauncher::LaunchThread(pThreadRoutine ThreadRoutine,void * args)
{
    pthread_attr_t attr;
    pthread_t posixThreadID;
    int returnVal;
    
    returnVal=pthread_attr_init(&attr);
    
    assert(!returnVal);
    returnVal=pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    assert(!returnVal);
    
    int threadError = pthread_create(&posixThreadID, &attr, ThreadRoutine, args);
    returnVal = pthread_attr_destroy(&attr);
    assert(!returnVal);
    if(threadError !=0)
    {
        //handle error.
        printf("thread error\n\r");//this is not handling the error just telling me there is one
    }
    
    return posixThreadID;
    
    /*char message;
     returnVal=pthread_join(posixThreadID, (void**)&message);
     assert(!returnVal);*/
    
    
}
