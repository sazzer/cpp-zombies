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
    Window(const std::string& title, const unsigned int width, const unsigned int height) :
      title_(title),
      width_(width),
      height_(height) {}
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

    /**
     * Get the title of the window
     * @return the title
     */
    const std::string& title() const {
      return title_;
    }
    /**
     * Get the width of the window
     * @return the width
     */
    const unsigned int& width() const {
      return width_;
    }
    /**
     * Get the height of the window
     * @return the height
     */
    const unsigned int& height() const {
      return height_;
    }
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
