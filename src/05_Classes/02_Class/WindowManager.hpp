//
// Created by Paulus on 2/17/18.
//

#ifndef __WINDOWMANAGER_HPP__
#define __WINDOWMANAGER_HPP__

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Screen;
class Window;

class WindowManager {

public:

    typedef struct {
        unsigned long width = 0;
        unsigned long height = 0;
    } dimensions_t;

    typedef struct {
        long x = 0;
        long y = 0;
    } position_t;

    typedef struct {
        string name;
        position_t position;
    } cursor_t;

    WindowManager() = default;
    WindowManager(Screen* screen);
    WindowManager(vector<Screen*> screens);
    vector<Screen*> getScreens();
    Screen* getScreenByID(unsigned long id);
    Screen* getScreenByName(string &name);
    vector<Window*> getAllWindows();
    void moveScreen(Screen *screen, position_t position);
    void resizeScreen(Screen *screen, dimensions_t dimensions);
    void moveWindow(Window *window, position_t position);
    void resizeWindow(Window *window, dimensions_t dimensions);
    inline unsigned int screenCount() { return screen_count; };
    inline unsigned int windowCount() { return window_count; };

private:
    Screen* findWindowScreen(Window* window);
    vector<Screen*> screens;
    /*mutable unsigned int screen_count = 1;
    mutable unsigned int window_count = 0;*/
};


#endif
