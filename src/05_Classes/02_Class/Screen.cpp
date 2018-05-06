#include "Screen.hpp"
#include "WindowManager.hpp"

Screen::Screen(string name, unsigned long width, unsigned long height, long x, long y) {
    this->name = name;
    this->dimensions.width = width;
    this->dimensions.height = height;
    this->position.x = x;
    this->position.y = y;
}

Screen& Screen::move(WindowManager::position_t position) {

    this->position = position;

    return *this;
}

void Screen::addWindow(Window *window) {

    this->windows.push_back(window);

}

void Screen::removeWindow(Window *window) {

    for( auto window_it = this->windows.begin(); window_it != this->windows.end(); window_it++ ) {

        if( *window_it == window ) {

            this->windows.erase(window_it);

        }
    }
}

void Screen::render(ostream &os, Window *win) const {

}