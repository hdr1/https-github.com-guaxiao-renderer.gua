#include <SDL/SDL.h>

#include "window.h"

int
main(int argc, char *argv[]) {
    Window win = Window(argc, argv);
    
    win.run();
    
    return 0;
}
