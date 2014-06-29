#include "ui/curses/window.h"

namespace UI {
  namespace Curses {
    /**
     * Default constructor
     */
    Window::Window(const std::string& title, const unsigned int width, const unsigned int height) : UI::Window(title, width, height) {
      win_ = subwin(stdscr, height, width, 0, 0);
      box(win_, 0, 0);

      // Where to put the title
      unsigned int titleX = (width - title.length()) / 2;
      mvwprintw(win_, 0, titleX, title.c_str());
      wnoutrefresh(win_);
    }
    /**
     * Virtual destructor
     */
    Window::~Window() {
      delwin(win_);
      win_ = 0;
    }
  }
}
