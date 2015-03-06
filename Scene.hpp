//
//  Scene.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 24-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Scene_hpp
#define BackMaze_Scene_hpp
#include "Monster.hpp"
#include <vector>
#include "Tile.hpp"
#include <iostream>
#include "MazeLoader.hpp"

class Scene{
public:
    Scene();
    ~Scene();
    void Update();
    void OnMouseDown(float x, float y);
    void OnPressedKey(unsigned short keycode);
private:
    SMonster monster;
    std::vector<std::vector<STile>> cells;
    bool invert;
    bool startMonster;
};

typedef std::unique_ptr<Scene> SScene;

#endif
