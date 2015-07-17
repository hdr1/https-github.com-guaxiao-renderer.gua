#import <Cocoa/Cocoa.h>
#import <SDL/SDL.h>

#include "window.h"

int
main(int argc, char *argv[]) {
    Window win = Window();
    
    win.run();
    
    return 0;
}
