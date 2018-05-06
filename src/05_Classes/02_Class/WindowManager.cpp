//
// Created by Paulus on 2/17/18.
//

#include "Screen.hpp"
#include "WindowManager.hpp"

using std::vector;

WindowManager::WindowManager(Screen* screen) {

    this->screens.push_back(screen);

}

WindowManager::WindowManager(vector<Screen*> screens) {

    this->screens = screens;

}

vector<Screen*> WindowManager::getScreens() {

    return this->screens;

}

Screen* WindowManager::getScreenByID(unsigned long id) {

    return this->screens.at(id);

}

Screen* WindowManager::getScreenByName(string &name) {

    for( unsigned long i = 0; i < this->screens.size(); i++ ) {

        if( this->screens.at(i)->getName().compare(name) == 0 ) {

            return this->screens.at(i);
        }


    }

    return nullptr;

}

vector<Window*> WindowManager::getAllWindows() {

    Screen* screen = nullptr;
    vector<Window*> windows;

    for(auto screen_it = this->screens.begin(); screen_it != this->screens.end(); screen_it++) {

        screen = *screen_it;

        windows.insert(windows.end(), screen->getWindows().begin(), screen->getWindows().end() );

    }

    return windows;

}

void WindowManager::moveScreen(Screen* screen, position_t position) {

    screen->move(position);

}

void WindowManager::resizeScreen(Screen* screen, dimensions_t dimensions) {

    screen->resize(dimensions);

}

void WindowManager::moveWindow(Window* window, position_t position, Screen* screen = nullptr) {

    Screen* sw;

    if( screen ) {



    }

    findWindowScreen(window)->move(position);

}

void WindowManager::resizeWindow(Window &window, dimensions_t dimensions) {

}

Screen* WindowManager::findWindowScreen(Window *window) {

    Screen* screen;
    Window* w;

    for( auto screen_it = this->screens.begin(); screen_it != this->screens.end(); screen_it++ ) {

        screen = *screen_it;

        for( auto window_it = screen->getWindows().begin(); window_it != screen->getWindows().end(); it++ ) {

            w = *window_it;

            if( w == window ) {

                return screen;

            }

        }

    }

    return nullptr;

}