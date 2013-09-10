//
//  Channel.cpp
//  DAW
//
//  Created by Alexander Zywicki on 8/29/13.
//  Copyright (c) 2013 Alexander Zywicki. All rights reserved.
//

#include "Channel.h"

Channel::Channel()
{
    
}

BufferStereo Channel::GenerateBufferStereo()
{
    return ChannelBuffer;
}

BufferStereo Channel::ProcessBufferStereo(BufferStereo inBufferStereo)
{
    
    return ChannelBuffer;
}