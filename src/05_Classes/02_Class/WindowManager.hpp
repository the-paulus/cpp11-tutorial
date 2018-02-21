//
// Created by Paulus on 2/17/18.
//

#ifndef __WINDOWMANAGER_HPP__
#define __WINDOWMANAGER_HPP__

#include <vector>

#include "Screen.hpp"

using std::vector;

class WindowManager {
public:
    typedef struct dimensions_t {
        unsigned long width = 0;
        unsigned long height = 0;
    };

    typedef struct position_t {
        long x = 0;
        long y = 0;
    };

    using cursor_t = struct {
        string name;
        position_t position;
    };

    WindowManager() = default;
    WindowManager(Screen screen) : screens(vector<Screen>(screen)) {};
    WindowManager(vector screens) : screens(screens) {};
    Screen &moveScreen(Screen &screen, position_t position);
    Screen &resizeScreen(Screen &screen, dimensions_t dimensions);

private:
    vector<Screen> screens{ Screen(1920,1080, "primary") };
};


#endif
