#include "ui/ui.h"
#include <ncurses.h>

namespace UI {
  struct UI::Impl {
  };

  UI::UI() : pImpl(new UI::Impl) {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    refresh();
    getch();
  }

  UI::~UI() {
    endwin();
  }

}
