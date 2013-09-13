//
//  Parallel.cpp
//  DAW
//
//  Created by Alexander Zywicki on 9/10/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "Parallel.h"
Parallel::Parallel()
{
    OutputBufferStereo = *new BufferStereo();
    OutputBufferStereo=0.0f;
}
void Parallel::AddInputSignalPath(SignalPath* InputSignalPathIn)
{
    InputSignalPaths[InputSignalPathCount]=InputSignalPathIn;
    InputSignalPathCount++;
    //Each SignalPath object needs to have a public integer that functions as an "ID" to the SignalPath that is holding it, this allows for dynamic removal and referencing of SignalPaths added. The ID should match the ID in the InputSignalPath array. It is possible that the index for the array ALONE could be enough of an ID for this concept to function.
}
void Parallel::ClearInputSignalPaths()
{
    
}
BufferStereo* Parallel::ProcessBufferStereo()
{
    
}