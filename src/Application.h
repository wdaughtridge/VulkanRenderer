//
// Created by William Daughtridge on 7/10/20.
//

#ifndef RENDERER_APPLICATION_H
#define RENDERER_APPLICATION_H

#include "Includes.h"
#include "Renderer.h"

namespace RVK
{

class Application
{
public:
    Application()
    {
        Renderer renderer;

        if (renderer.Start() != VK_SUCCESS)
            std::cout << "ERROR: RENDERER DID NOT START SUCCESSFULLY!\n";
    }
};

}

#endif //RENDERER_APPLICATION_H
