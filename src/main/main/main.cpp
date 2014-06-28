#include "lib/main.h"

/**
 * Main entrypoint into the application
 * @param argc The number of arguments
 * @param argv The actual arguments
 */
int main(const int argc, const char** argv) {
  std::vector<const char*> args(argv + 1, argv + argc);

  initialize();
  setArguments(args);
  start();
  return 0;
}
