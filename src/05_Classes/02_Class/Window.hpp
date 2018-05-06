#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>

#include "WindowManager.hpp"

using std::istream;
using std::ostream;
using std::string;

//extern ostream &writeToWindow(ostream &, Window &);

class Window {
public:
    using WINDOW_ID = const Window *;

    istream &writeToWindow(ostream &, Window &);
    //ostream& display();
    string display();

    Window() = default;
    Window(WindowManager::position_t position, WindowManager::dimensions_t dimensions, string &content) : position(position), dimensions(dimensions), content(content) {};
    Window(long x, long y, unsigned long w, unsigned long h, string content);
    WINDOW_ID getWindowID() const { return this; };
    Window &move(WindowManager::position_t position);
    WindowManager::position_t getPosition() { return position; };
    Window &resize(WindowManager::dimensions_t dimensions);
    WindowManager::dimensions_t getDimensions() { return dimensions; };


private:
    string content;
    WindowManager::dimensions_t dimensions;
    WindowManager::position_t position;

};

#endif