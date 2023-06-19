#ifndef MAIN_H
#define MAIN_H

/**
 * @file main.h
 * @brief Header file for the main module.
 */

/**
 * @brief Initializes the program.
 *
 * This function initializes the necessary resources and prepares the program
 * for execution.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return An integer indicating the success (0) or failure (non-zero) of the initialization.
 */
int initialize(int argc, char** argv);

/**
 * @brief Runs the program.
 *
 * This function starts the main execution of the program.
 *
 * @return An integer indicating the exit status of the program.
 */
int run();

/**
 * @brief Cleans up resources and exits the program.
 *
 * This function releases any allocated resources and performs necessary cleanup
 * before exiting the program.
 */
void cleanup();

#endif  // MAIN_H

