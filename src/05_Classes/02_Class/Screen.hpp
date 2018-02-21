#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

#include "WindowManager.hpp"

class Screen {
public:
    Screen() = default;
    Screen(string name, dimensions_t di, position_t pos) : name(name), dimensions(di), position(pos) {};
    position_t getCursorPosition() const { return cursor.position; } // Implicit inline declaration.
    inline position_t getCursorPosition() const; // Explicit inline declaration.
    Screen &move(position_t position);
    Screen &display(ostream &os) { render(os); return *this; }
    const Screen &display(ostream &os) const { render(os); return *this; }
private:
    cursor_t cursor;
    dimensions_t dimensions;
    position_t position;
    string name;
    void render(ostream &os) const { os << contents; }
};

#endif