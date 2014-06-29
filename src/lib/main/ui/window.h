#ifndef ZOMBIES_UI_WINDOW_H
#define ZOMBIES_UI_WINDOW_H

#include <string>

namespace UI {
  /**
   * Class to represent a window in the UI
   */
  class Window {
  public:
    /**
     * Default constructor
     */
    Window();
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
  private:
    /** The title of the window */
    std::string title_;
    /** The width of the window */
    unsigned int width_;
    /** The height of the window */
    unsigned int height_;
  };
}

#endif
