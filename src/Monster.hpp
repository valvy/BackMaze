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

/*!
 *  The monster that is actually walking
 *  @author Heiko van der Heijden
 */
class MeanMonster{
private:
    /*!
     *  The tile where the monster is
     */
    STile currentTile;
    
    /*!
     *  The tile the monster should jump to
     *  @param nTile the new tile
     */
    void JumpTile(STile nTile);
    
    
    /*!
     *  The tiles the monster went previously
     */
    std::vector<STile> prefTiles;
    
    /*!
     *  Check which tile the monster prefers
     *  @param l the left tile
     *  @param f the front tile
     *  @param r the right tile
     *  @param d the down tile
     */
    STile PreferedTile(STile l, STile f, STile r, STile d);
    
    /*!
     *  Is the monster at the goal?
     */
    bool isAtGoal;
    
    /*!
     *  Time left
     */
    float walkCooldown = 0;
    //for some reason the clock works differently on windows, then on a mac
#ifdef WIN32
    /*!
     *  The speed it moves
     */
    float movementSpeed = 100.0f;
#else
    /*!
     *  The speed it moves
     */
    float movementSpeed = 2400.0f;
#endif
public:
    /*!
     *  The constructor with the starting tile
     *  @param startingTile the tile where the monster starts
     */
    MeanMonster(STile startingTile);
    
    /*!
     *  Where is the monster now?
     *  @param x the tile position x
     *  @param y the tile position y
     */
    void GetCurrentTile(unsigned short& x, unsigned short& y);
    
    /*!
     *  update the monster
     *  @param l the left tile
     *  @param f the front tile
     *  @param r the right tile
     *  @param d the down tile
     */
    void Update(STile l, STile f, STile r,STile d);
};

typedef std::unique_ptr<MeanMonster> SMonster;
#endif
