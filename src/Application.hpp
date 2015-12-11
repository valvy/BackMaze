//
//  Application.hpp
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifndef BackMaze_Application_hpp
#define BackMaze_Application_hpp
#pragma once
#include <memory>

/*!
 *  @author Heiko van der Heijden
 *  This class manages the main thread and handles the input
 */
class Application{
public:
    Application();
    ~Application();
    /*!
     * The main loop
     */
    virtual void Update() = 0;
    
    /*!
     *  will be called when the mouse is clicked
     *  @param x the x axis the mouse was when clicked
     *  @param y the y axis the mouse was when clicked
     */
    virtual void OnMouseDown(float x, float y) = 0;
    
    /*!
     *  will be called when an keyboard key is pressed
     *  @param keycode the key that has been clicked
     */
    virtual void OnKeyDown(unsigned short keycode) = 0;
    
    /*!
     *  The content path which contains the binary file
     *  @return the contentpath
     */
    static std::string AppPath();
protected:
    /*!
     * Stops the app
     */
    void ExitApp();
    
    /*!
     *  Starts the app background
     */
    void StartApp();
};

/*!
 *  the app wrapped in a smart pointer
 */
typedef std::unique_ptr<Application> App;

#endif
