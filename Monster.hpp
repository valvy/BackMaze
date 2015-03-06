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

class MeanMonster{
private:
    STile currentTile;
    void JumpTile(STile nTile);
    class Path{
    public:
        typedef std::unique_ptr<Path> SPath;
        SPath left;
        SPath forward;
        SPath down;
        SPath right;
        STile tile;
    };
    typedef std::unique_ptr<Path> SPath;
    SPath path;
    
public:
    MeanMonster(STile startingTile);
    void GetCurrentTile(unsigned short& x, unsigned short& y);
    void Update(STile l, STile f, STile r,STile d);
};

typedef std::unique_ptr<MeanMonster> SMonster;
#endif
