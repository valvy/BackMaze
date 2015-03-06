//
//  MacApp.m
//  BackMaze
//
//  Created by Heiko van der Heijden on 22-02-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//

#ifdef __APPLE__

#import "Application.hpp"
#import <Cocoa/Cocoa.h>

@interface MacApp : NSWindow  <NSApplicationDelegate>{}
@property (nonatomic) NSOpenGLView* scene;
@property (nonatomic) Application* appl;
-(void) UpdateScene;
-(void) SetOwner:(Application*) app;

@end


NSApplication* nsApplication;
MacApp* app;

@implementation MacApp
-(id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)aStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)flag{
    if(self = [super initWithContentRect:contentRect styleMask:aStyle backing:bufferingType defer:flag]){

        _scene = [[NSOpenGLView alloc]initWithFrame:contentRect];
        [self setContentView:_scene];
    }
    return self;
}

-(void)mouseDown:(NSEvent*) event{
    NSPoint point = [self mouseLocationOutsideOfEventStream];
    _appl->OnMouseDown((float)point.x, (float)point.y);
    
    
}

-(void)mouseDragged:(NSEvent*) event{
    NSPoint point = [self mouseLocationOutsideOfEventStream];
    _appl->OnMouseDown((float)point.x, (float)point.y);
}

-(void)keyDown:(NSEvent*) event{
    _appl->OnKeyDown([event keyCode]);
}



-(void) SetOwner:(Application*) app{
    
    _appl = app;
}

- (void)applicationDidFinishLaunching:(NSNotification *)notification {
    [self setTitle:[[NSProcessInfo processInfo] processName]];
    [self makeKeyAndOrderFront:self];
    [self setAcceptsMouseMovedEvents:YES];
    //set the main loop
    [NSTimer scheduledTimerWithTimeInterval:0.0001 target:self selector:@selector(UpdateScene) userInfo:nil repeats:YES];
}



-(void)UpdateScene{
    if(_appl != nullptr){
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        _appl->Update();
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
    [NSApp setMainMenu:mainMenu];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication{
    return YES;
}


@end


Application::Application(){
    nsApplication = [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    app = [[MacApp alloc] initWithContentRect:NSMakeRect(0, 0, WINDOW_HEIGHT, WINDOW_WIDTH) styleMask:NSTitledWindowMask | NSClosableWindowMask |  NSMiniaturizableWindowMask   backing:NSBackingStoreBuffered defer:YES];
    [app SetOwner:this];
    [nsApplication setDelegate:app];
}

void Application::StartApp(){
    [nsApplication run];
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


Application::~Application(){
    
}


#endif
