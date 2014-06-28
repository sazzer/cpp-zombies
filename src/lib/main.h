#ifndef ZOMBIES_MAIN_H
#define ZOMBIES_MAIN_H

#include <vector>

/**
 * Initialize the application
 */
void initialize();
/**
 * Set the arguments that will be used by the application
 * @param args The arguments to use
 */
void setArguments(const std::vector<const char*>& args);
/**
 * Start running the application
 */
void start();

#endif
