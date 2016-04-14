// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include "glfw_include.h"


// Include GLFW



// Include GLM
#include "glm_include.h"



#include "tmx_manager.hpp"
int main( void )
{
    tmx_manager* manager = &tmx_manager::getManagerInstance();
    
    manager->run_main_loop();
    
    
    manager->destroyTmxManager();
    return 0;
}