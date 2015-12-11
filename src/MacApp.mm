//
//  MacApp.m
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifdef __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_MAC
#import"MacApp.h"
#import"BackMaze.hpp"
NSApplication* nsApplication;
MacApp* app;

App application;

@implementation MacApp
-(id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)aStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)flag{
    if(self = [super initWithContentRect:contentRect styleMask:aStyle backing:bufferingType defer:flag]){

        _scene = [[NSOpenGLView alloc]initWithFrame:contentRect];
        [self setContentView:_scene];
        application = App(new BackMaze());
        
    }
    return self;
}

-(void)mouseDown:(NSEvent*) event{
    NSPoint point = [self mouseLocationOutsideOfEventStream];
    application->OnMouseDown((float)point.x, (float)point.y);
    
    
}

-(void)mouseDragged:(NSEvent*) event{
    NSPoint point = [self mouseLocationOutsideOfEventStream];
    application->OnMouseDown((float)point.x, (float)point.y);
}

-(void)keyDown:(NSEvent*) event{
    application->OnKeyDown([event keyCode]);
}




- (void)applicationDidFinishLaunching:(NSNotification *)notification {
    [self setTitle:[[NSProcessInfo processInfo] processName]];
    [self makeKeyAndOrderFront:self];
    [self setAcceptsMouseMovedEvents:YES];
    //set the main loop
    [NSTimer scheduledTimerWithTimeInterval:0.0001 target:self selector:@selector(UpdateScene) userInfo:nil repeats:YES];
}



-(void)UpdateScene{
   if(application != nullptr){
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        application->Update();
        glFlush();
        
    }
}

- (void)applicationWillFinishLaunching:(NSNotification *)notification{
    
    //setup the menubar
    NSMenu* mainMenu = [[NSMenu alloc] initWithTitle:@"MainMenu"];
    NSMenuItem* appleMenuItem;
    NSMenu* appleSubMenu;
    NSString* applicationName = [[NSProcessInfo processInfo]processName];
    NSMenuItem* appMenuItem;
    
    appleMenuItem = [mainMenu addItemWithTitle:@"Apple" action:NULL keyEquivalent:@""];
    appleSubMenu = [[NSMenu alloc]initWithTitle:@"Apple"];
   // [NSApp performSelector:NSSelectorFromString(@"setAppleMenu:") withObject:appleSubMenu];
    
    appMenuItem = [appleSubMenu addItemWithTitle:[NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"About", nil), applicationName] action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""];
    [appMenuItem setTarget:NSApp];
    [appleSubMenu addItem:[NSMenuItem separatorItem]];
    
    appMenuItem = [appleSubMenu addItemWithTitle:[NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"Quit", nil), applicationName] action:@selector(terminate:) keyEquivalent:@"q"];
    [appMenuItem setTarget:NSApp];
    
    [mainMenu setSubmenu:appleSubMenu forItem:appleMenuItem];
    [NSApp setMainMenu:mainMenu];

}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication{
    return YES;
}


@end


Application::Application(){
   
}

void Application::StartApp(){
    
}

void Application::OnMouseDown(float x, float y){
    //virtual
}

void Application::OnKeyDown(unsigned short keycode){
    //virtual
}

void Application::Update(){
    //virtual
}

void Application::ExitApp(){
    [app close];
}

std::string Application::AppPath(){
    
    return [[[NSBundle mainBundle]bundlePath]UTF8String];
}

Application::~Application(){
    
}

int main(){
    nsApplication = [NSApplication sharedApplication];
     [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
     app = [[MacApp alloc] initWithContentRect:NSMakeRect(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH) styleMask:NSTitledWindowMask | NSClosableWindowMask |  NSMiniaturizableWindowMask   backing:NSBackingStoreBuffered defer:YES];
    [nsApplication setDelegate:app];
    [nsApplication run];
}

#endif
#endif
