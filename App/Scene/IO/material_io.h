/**********************************************************************
 Copyright (c) 2016 Advanced Micro Devices, Inc. All rights reserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ********************************************************************/

/**
 \file material_io.h
 \author Dmitry Kozlov
 \version 1.0
 \brief Contains an interface for material input & output
 */
#pragma once

#include <string>

namespace Baikal
{
    class Scene1;
    
    /**
     \brief Interface for material loading and writing
     
     MaterialIO is responsible for material loading from disk.
     */
    class MaterialIo
    {
    public:
        // Create XML based material IO
        static MaterialIo* CreateMaterialIoXML();
        
        // Constructor
        MaterialIo() = default;
        // Destructor
        virtual ~MaterialIo() = 0;
        
        // Save materials from scene into a file
        virtual void SaveMaterials(std::string const& filename, Scene1 const& scene) = 0;
        
        // Disallow copying
        MaterialIo(MaterialIo const&) = delete;
        MaterialIo& operator = (MaterialIo const&) = delete;
    };
    
    inline MaterialIo::~MaterialIo()
    {
    }
}
