//
//  Monster.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 24-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Monster_hpp
#define BackMaze_Monster_hpp
#include "Tile.hpp"
#include <vector>
#include <time.h>
class MeanMonster{
private:
    STile currentTile;
    void JumpTile(STile nTile);
    std::vector<STile> prefTiles;
    STile PreferedTile(STile l, STile f, STile r, STile d);
    bool isAtGoal;
    float walkCooldown = 0;
    //for some reason the clock works differently on windows, then on a mac
#ifdef WIN32
    float movementSpeed = 100.0f;
#else
    float movementSpeed = 2400.0f;
#endif
public:
    MeanMonster(STile startingTile);
    void GetCurrentTile(unsigned short& x, unsigned short& y);
    void Update(STile l, STile f, STile r,STile d);
};

typedef std::unique_ptr<MeanMonster> SMonster;
#endif
