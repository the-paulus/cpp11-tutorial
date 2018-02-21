#include "Window.hpp"

Window::Window &moveWindow(position_t position) {
    this->position = position;
    return *this;
}