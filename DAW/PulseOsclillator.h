//
//  PulseOsclillator.h
//  DAW
//
//  Created by Alexander Zywicki on 8/23/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#ifndef __DAW__PulseOsclillator__
#define __DAW__PulseOsclillator__

#include <iostream>
#include "AudioProccessing.h"
class PulseOscillator:AudioEntity
{
public:
    PulseOscillator();
        
    Sample GenerateSample(ParamVal Frequency);

    void SetParameter(ParamVal _value,std::string ParamID);
    ParamVal GetParameter(std::string ParamID);
protected:
    ParamVal Phasor(ParamVal Period);
    Sample OSCGen(ParamVal PhasorVal,ParamVal _PulseWidth);
    
    ParamVal SetupCalcs(ParamVal SampleRate,ParamVal Frequency);
    
private:
    ParamVal SampleRate;
    ParamVal NoteFrequency;
    ParamVal PulseWidth;
    ParamVal Period;
    ParamVal PhasorValue;
    ParamVal PhasorTollerance;
    
};

#endif /* defined(__DAW__PulseOsclillator__) */
