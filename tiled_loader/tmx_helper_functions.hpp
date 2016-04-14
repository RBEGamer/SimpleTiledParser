//
//  tmx_helper_functions.hpp
//  tiled_loader
//
//  Created by Marcel Ochsendorf on 03.04.16.
//  Copyright © 2016 Marcel Ochsendorf. All rights reserved.
//

#ifndef tmx_helper_functions_hpp
#define tmx_helper_functions_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#endif /* tmx_helper_functions_hpp */


void replaceAll(std::string& str, const std::string& from, const std::string& to);
bool replace(std::string& str, const std::string& from, const std::string& to);
long getFileSize(FILE *inFile);
char *loadTextFromFile(const char *file, const char* _mode);
