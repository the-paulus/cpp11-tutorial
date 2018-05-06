#include <iostream>

#include "Screen.hpp"
#include "Window.hpp"
#include "WindowManager.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char **argv) {

    Screen* primary_screen = new Screen("Primary", 1920, 1080, 0, 0);
    Screen* secondary_screen = new Screen("Secondary", 1920, 1080, 1080, 0);
    vector<Screen*> screens = { primary_screen, secondary_screen };
    WindowManager wmgr = WindowManager(screens);

    cout << "WindowManager object address: " << &wmgr << endl;
    cout << "WindowManager::getScreenByID(0): " << wmgr.getScreenByID(0) << endl;

    cout << "***** Screen Objects *****" << endl;

    cout << "Screen address: " << primary_screen << endl;
    cout << "Screen name: " << primary_screen->getName() << endl;
    cout << "Screen position: " << primary_screen->getPosition().x << ", " << primary_screen->getPosition().y << endl;
    cout << "Screen dimensions: " << primary_screen->getDimensions().width << "x" << primary_screen->getDimensions().height << endl;

    cout << "Screen address: " << secondary_screen << endl;
    cout << "Screen name: " << secondary_screen->getName() << endl;
    cout << "Screen position: " << secondary_screen->getPosition().x << ", " << secondary_screen->getPosition().y << endl;
    cout << "Screen dimensions: " << secondary_screen->getDimensions().width << "x" << secondary_screen->getDimensions().height << endl;

    cout << "***** Screen Vector *****" << endl;

    for( Screen* s : screens ) {

        cout << "Screen address: " << s << endl;
        cout << "Screen name: " << s->getName() << endl;
        cout << "Screen position: " << s->getPosition().x << ", " << s->getPosition().y << endl;
        cout << "Screen dimensions: " << s->getDimensions().width << "x" << s->getDimensions().height << endl;

    }

    cout << "***** Screen Vector from WindowManager *****" << endl;

    for( Screen* s : wmgr.getScreens() ) {

        cout << "Screen address: " << s << endl;
        cout << "Screen name: " << s->getName() << endl;
        cout << "Screen position: " << s->getPosition().x << ", " << s->getPosition().y << endl;
        cout << "Screen dimensions: " << s->getDimensions().width << "x" << s->getDimensions().height << endl;

    }

    Screen *tmps = wmgr.getScreenByID(0);

    cout << (tmps == primary_screen) << endl;

    Window win = Window(0, 0, 1920, 1080, "ponies");

    cout << "Window address: " << &win << endl;
    cout << "Window ID: " << win.getWindowID() << endl;
    cout << "Window position: " << win.getPosition().x << ", " << win.getPosition().y << endl;
    cout << "Window dimensions: " << win.getDimensions().width << "x" << win.getDimensions().height << endl;

    WindowManager::dimensions_t new_dimensions;

    new_dimensions.width = 100;
    new_dimensions.height = 100;

    win.resize(new_dimensions);

    cout << "New dimensions:" << endl;
    cout << win.getDimensions().width << "x" << win.getDimensions().height << endl;

    WindowManager::position_t new_position;

    new_position.x = 100;
    new_position.y = 100;

    win.move(new_position);

    cout << "New position:" << endl;
    cout << win.getPosition().x << ", " << win.getPosition().y << endl;

    cout << "Window content: " << win.display() << endl;
}