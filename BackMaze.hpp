//
//  BackMaze.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_BackMaze_hpp
#define BackMaze_BackMaze_hpp
#include "Application.hpp"
#include "Tile.hpp"
#include "Monster.hpp"
#include "Scene.hpp"
#include <fstream>

class BackMaze : public Application{
public:
    BackMaze();
    ~BackMaze();
    void Update() override;
    void OnMouseDown(float x, float y) override;
    void OnKeyDown(unsigned short keycode) override;
private:
    
    SScene scene;
    
};



#endif
