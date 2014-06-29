#include "ui/ui.h"
#include <ncurses.h>

namespace UI {
  /**
   * RAII wrapper around the Curses UI
   */
  class CursesUI {
  public:
    /**
     * Initialize the UI
     */
    CursesUI() {
      initscr();
      raw();
      keypad(stdscr, TRUE);
      noecho();
      
    }
    /**
     * Destroy the UI
     */
    ~CursesUI() {
      endwin();
    }
  };
  void start() {
    CursesUI ui;
    getch();
  }
}
