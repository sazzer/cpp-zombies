#include "ui/ui.h"
#include <ncurses.h>
#include <memory>
#include "ui/curses/window.h"

namespace UI {
  namespace Curses {
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
	
	mapWindow_.reset(new UI::Curses::Window("Zombies RL", COLS, LINES));
      }
      /**
       * Destroy the UI
       */
      ~CursesUI() {
	endwin();
      }
    private:
      std::unique_ptr<UI::Curses::Window> mapWindow_;
    };
  }
  
  /**
   * Start running the UI
   */
  void start() {
    UI::Curses::CursesUI ui;
    getch();
  }
}
