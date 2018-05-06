#include <sstream>
#include "Window.hpp"

using std::cout;
using std::ostream;
using std::ostringstream;

Window::Window(long x, long y, unsigned long w, unsigned long h, string content) {
    this->position.x = x;
    this->position.y = y;
    this->dimensions.width = w;
    this->dimensions.height = h;
    this->content = content;
}

/*ostream& Window::display() {
    ostringstream oss(this->content);
    ostream os(oss.rdbuf());
    return os;
}*/

string Window::display() {
    return content;
}


Window& Window::move(WindowManager::position_t position) {
    this->position = position;
    return *this;
}

Window& Window::resize(WindowManager::dimensions_t dimensions) {
    this->dimensions = dimensions;
    return *this;
}
