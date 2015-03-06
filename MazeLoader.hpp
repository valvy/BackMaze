//
//  MazeLoader.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 04-03-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_MazeLoader_hpp
#define BackMaze_MazeLoader_hpp
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Tile.hpp"

#define fileName "maze.txt"

class MazeLoader{
public:
    static std::vector<std::vector<STile>> LoadFile();
    static bool SaveFile(std::vector<std::vector<STile>> dat);
};

#endif
