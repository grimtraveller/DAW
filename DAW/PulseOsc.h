//
//  PulseOsc.h
//  pulse osc claass
//
//  Created by Alexander Zywicki on 7/21/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __pulse_osc_claass__PulseOsc__
#define __pulse_osc_claass__PulseOsc__

#include <iostream>
#include <math.h>

class PulseOsc
{
public:
    PulseOsc(float* _sampleRate,float _phasorTollerance,float _pulseWidth);
    ~PulseOsc();
    
    float ProcessCycle(float _noteFrequency, float _pulseWidth);
        
protected:
    
    float Phasor(float Period);
    float PulseOscillatorCalc(float PhasorVal,float PW);
    float SinOscillatorCalc(float PhasorVal);
    float SetupCalcs(float SampleRate, float Frequency);

    
    float SampleRate;
    float NoteFrequency;
    float PulseWidth;
    float Period;
    float PhasorValue;
    float PhasorTollerance;
};




#endif /* defined(__pulse_osc_claass__PulseOsc__) */
