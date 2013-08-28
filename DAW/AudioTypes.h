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


#define HostSampleRate 44100
#define HostBufferSize 256

typedef struct Sample
{
    float Value;
    clock_t TimeStamp;
    
    Sample& operator=(Sample& s){return s;}
    
    Sample& operator=(float v)
    {
        Value=v;
        return *this;
    }
    Sample& operator=(Sample s)
    {
        Value=s.Value;
        return *this;
    }

}Sample;

typedef struct Buffer
{
    Sample Values[HostBufferSize];
    
    const Sample& operator[](int i)const{
        return this->Values[i];
    }
    Sample& operator[](int i)
        {
            return this->Values[i];
        }
        
    
    
}Buffer;

typedef struct BufferStereo
{
    Buffer Channel_1;
    Buffer Channel_2;
}BufferStereo;

typedef double ParamVal;



#endif
