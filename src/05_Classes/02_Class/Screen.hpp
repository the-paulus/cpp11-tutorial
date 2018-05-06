#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

#include "Window.hpp"
#include "WindowManager.hpp"

using std::ostream;
using std::string;
using std::vector;

class Screen {

public:
    Screen() = default;
    Screen(string name, WindowManager::dimensions_t di, WindowManager::position_t pos) : name(name), dimensions(di), position(pos) {};
    Screen(string name, unsigned long width, unsigned long height, long x, long y);
    string &getName() { return this->name; };
    WindowManager::position_t getCursorPosition() const { return cursor.position; } // Implicit inline declaration.
    Screen &move(WindowManager::position_t position);
    WindowManager::position_t getPosition() { return this->position; };
    void resize(WindowManager::dimensions_t dimensions) { this->dimensions = dimensions; };
    WindowManager::dimensions_t getDimensions() { return this->dimensions; };
    Screen &display(ostream &os, Window *win) { render(os, win); return *this; };
    const Screen &display(ostream &os, Window *win) const { render(os, win); return *this; };
    vector<Window*> getWindows() { return windows; };

private:
    WindowManager::cursor_t cursor;
    WindowManager::dimensions_t dimensions;
    WindowManager::position_t position;
    string name;
    void render(ostream &os, Window *win) const;
    vector<Window*> windows;

};

#endif