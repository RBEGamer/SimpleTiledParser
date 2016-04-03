//
//  tmx_manager.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_manager_hpp
#define tmx_manager_hpp

#include <stdio.h>
#include <iostream>
#include "../glfw/include/GLFW/glfw3.h"

class tmx_manager{
public:
    tmx_manager();
    ~tmx_manager();

    
    
    
   static  tmx_manager& getManagerInstance();
    static void destroyTmxManager();
};


#endif /* tmx_manager_hpp */
