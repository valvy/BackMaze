//
//  Scene.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 24-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Scene_hpp
#define BackMaze_Scene_hpp
#pragma once
#include "Monster.hpp"
#include <vector>
#include "Tile.hpp"

/*!
 *  an scene containing all elements en renders everything
 *  @author Heiko van der Heijden
 */
class Scene{
public:
    Scene();
    ~Scene();
    /*!
     *  The main loop
     */
    void Update();
    
    /*!
     *  When clicked this is called
     *  @param x the x location of the mouse when clicked
     *  @param y the y location of the mouse when clicked
     */
    void OnMouseDown(float x, float y);
    
    /*!
     *  When an button is pressed this method is called
     *  @param keycode The code of the button that has been pressed
     */
    void OnPressedKey(unsigned short keycode);
private:
    /*!
     *  The crawler in the world
     */
    SMonster monster;
    
    /*!
     *  The grid
     */
    std::vector<std::vector<STile>> cells;
    
    /*!
     *  would you want to add or remove tiles
     */
    bool invert;
    
    /*!
     *  Should the monster crawl
     */
    bool startMonster;
};

/*!
 *  The scene but wrapped in a pointer
 */
typedef std::unique_ptr<Scene> SScene;

#endif
