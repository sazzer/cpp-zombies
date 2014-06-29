#ifndef ZOMBIES_UI_CURSES_WINDOW_H
#define ZOMBIES_UI_CURSES_WINDOW_H

#include "ui/window.h"

namespace UI {
  namespace Curses {
    /**
     * An NCurses Window
     */
    class Window : public UI::Window {
    public:
      /**
       * Default constructor
       */
      Window(const std::string& title, const unsigned int width, const unsigned int height) : 
        UI::Window(title, width, height) {}
      /**
       * Virtual destructor
       */
      virtual ~Window() {};
      /** Non-copyable */
      Window(const Window& other) = delete;
      /** Non-moveable */
      Window(Window&& other) = delete;
      /** Non-copyable */
      Window& operator=(const Window& other) = delete;
      /** Non-moveable */
      Window& operator=(Window&& other) = delete;
      
    };
  }
}

#endif
