//
//  AudioTypes.h
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef DAW_AudioTypes_h
#define DAW_AudioTypes_h

#include <ctime>
#include <CoreAudio/CoreAudio.h>


typedef struct Sample
{
    Float32 Value;
    clock_t TimeStamp;
}Sample;

typedef double ParamVal;



#endif
