#include "main.h"
#include "ui/ui.h"
#include <iostream>

/**
 * Initialize the application
 */
void initialize() {
  std::cerr << "Initializing" << std::endl;
}

/**
 * Set the arguments that will be used by the application
 * @param args The arguments to use
 */
void setArguments(const std::vector<const char*>& args) {
  std::cerr << "Processing arguments" << std::endl;
  for (const char* a : args) {
    std::cerr << "Argument: " << a << std::endl;
  }
}

/**
 * Start running the application
 */
void start() {
  std::cerr << "Starting" << std::endl;
  UI::UI ui;
}
