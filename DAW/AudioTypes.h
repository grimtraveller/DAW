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


//#define HostSampleRate 44100
#define HostBufferSize 256
#define MaxChannels 128



const unsigned int HostSampleRate = 44100;


typedef unsigned short  BufferSize;


const BufferSize BufferSize_32=32;
const BufferSize BufferSize_64=64;
const BufferSize BufferSize_128=128;
const BufferSize BufferSize_256=256;
const BufferSize BufferSize_512=512;
const BufferSize BufferSize_1024=1024;





typedef struct Sample
{
    float Value;
    clock_t TimeStamp;
    
    //Sample& operator=(Sample& s){return s;}
    
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
    Buffer& operator+=(Buffer b)
    {
        for(int i =0; i<HostBufferSize; ++i)
        {
            Values[i].Value= Values[i].Value + b[i].Value;
        }
        return *this;
    }
    Buffer& operator=(Buffer b)
    {
        for(int i = 0;i<HostBufferSize;++i)
        {
            Values[i].Value=b[i].Value;
        }
        return *this;
    }
    Buffer& operator=(float v)
    {
        for(int i =0;i<HostBufferSize;i++)
        {
            Values[i].Value=v;
        }
        return *this;
    }
    Buffer& operator*=(float v)
    {
        for(int i=0;i<HostBufferSize;i++)
        {
            Values[i].Value*=v;
        }
        return *this;
    }
        
    
    
}Buffer;

typedef struct BufferStereo
{
    Buffer Channel_1;
    Buffer Channel_2;
    BufferStereo& operator=(float v)
    {
        Channel_1=v;
        Channel_2=v;
        return *this;
    }
    BufferStereo& operator=(BufferStereo buff)
    {
        Channel_1=buff.Channel_1;
        Channel_2=buff.Channel_2;
        return *this;
    }
    BufferStereo& operator=(Buffer b)
    {
        Channel_1=b;
        Channel_2=b;
        return *this;
    }
    BufferStereo& operator+=(BufferStereo buff)
    {
        Channel_1+=buff.Channel_1;
        Channel_2+=buff.Channel_2;
        return *this;
    }
    BufferStereo& operator*=(float v)
    {
        Channel_1*=v;
        Channel_2*=v;
        return *this;
    }
}BufferStereo;

typedef float ParamVal;



#endif
