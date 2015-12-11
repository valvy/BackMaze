//
//  MazeLoader.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 04-03-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_MazeLoader_hpp
#define BackMaze_MazeLoader_hpp
#pragma once
#include <vector>
#include <string>
#include "Tile.hpp"
/*!
 *  The file containing the maze
 */
constexpr char fileName[] = "maze.dat";

/*!
 *  This class loads the maze
 *  @author Heiko van der Heijden
 */
class MazeLoader{
public:
    /*!
     *  Loads the file
     *  @return all the lines in the default maze file
     */
    static std::vector<std::string> LoadFile();
    
    /*!
     *  Saves a new maze to the default maze file
     *  @param dat the new data
     */
    static bool SaveFile(std::vector<std::vector<STile>> dat);
};

#endif
