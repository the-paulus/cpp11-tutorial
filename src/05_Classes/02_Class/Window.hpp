#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "WindowManager.hpp"

using WindowManager::dimensions_t;
using WindowManager::position_t;

extern ostream &writeToWindow(ostream &, Window &);

class Window {
public:
    friend ostream &writeToWindow(ostream &, Window &);
    Window() = default;
    Window(position_t position, string content = "") : position(position), content(content) {};
    Window(long x, long y, string content = "") : x(position.x), y(position.y), content(content) {};
    Window(position_t position, dimensions_t dimensions) : position(position), dimensions(dimensions) {};
    Window(long x, long y, unsigned long w, unsigned long h);
    Window &moveWindow(position_t position);
    Window &resizeWindow(dimensions_t dimensions);

private:
    unsigned long wid = 0;
    string content;
    dimensions_t dimensions;
    position_t position;

};