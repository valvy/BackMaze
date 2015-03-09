//
//  Globals.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 23-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Globals_hpp
#define BackMaze_Globals_hpp
#include <string>
const float WINDOW_HEIGHT = 600;
const float WINDOW_WIDTH = 600;

const float TILE_SIZE = 0.05f;


//Keycodes
#ifdef __APPLE__
const unsigned short ESCAPE_KEY = 53;
const unsigned short SPACE_BAR = 49;
const unsigned short ENTER_KEY = 36;
const unsigned short S_KEY = 1;
#endif

#if _WIN32
const unsigned short ESCAPE_KEY = 27;
const unsigned short SPACE_BAR = 32;
const unsigned short ENTER_KEY = 13;
const unsigned short S_KEY = 83;
#endif

#endif
