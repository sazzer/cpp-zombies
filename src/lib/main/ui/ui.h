#ifndef ZOMBIES_UI_UI_H
#define ZOMBIES_UI_UI_H

#include <memory>

namespace UI {
  /**
   * The actual main UI
   */
  class UI {
  public:
    /**
     * Construct the UI
     */
    UI();
    /**
     * Destroy the UI
     */
    ~UI();
    /** The UI is not copyable */
    UI(const UI& other) = delete;
    /** The UI is default moveable */
    UI(UI&& other) = default;
    /** The UI is not copyable */
    UI& operator=(const UI& other) = delete;
    /** The UI is default moveable */
    UI& operator=(UI&& other) = default;
  protected:
  private:
    /** The internal implementation */
    struct Impl;
    /** The pImpl */
    std::shared_ptr<Impl> pImpl;
  };
}

#endif
