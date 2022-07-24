#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "bots.h"

/**
 * C EXCEPTIONS LIBRARY
 * By Yochran
 */

#include "exceptions.h"

// threading function declarations
void start_econ(void *var);
void start_utilities(void *var);

/**
 * FORMAT:
 * launch <all/name>
 */

/**
 * @brief Main function
 * 
 * @param argc - argument count
 * @param argv - argument array
 * @return int 
 */
int main(int argc, char *argv[])
{
    // check argument length
    if (argc != 2)
    {
        // create exception
        exception _exception = {
            "Correct Usage: launch <all/name>",
            INCORRECT_USAGE
        };

        // throw exception
        throw(&_exception);
        exit(0);
    }

    // create argument & option variables
    char *arg = (char*) argv[1];
    int option;

    // set option
    if (strstr(arg, "all")) option = 1;
    else option = 2;

    // check if null
    if (!option)
    {
        // create exception
        exception _exception = {
            "Correct Usage: launch <all/name>",
            INCORRECT_USAGE
        };

        // throw exception
        throw(&_exception);
        exit(0);
    }

    // switch option
    switch (option)
    {
        // all
        case 1:
            // setup multithreading
            pthread_t ccecon, ccutilities;

            // create threads
            pthread_create(&ccecon, NULL, (void*)(void*) start_econ, NULL);
            pthread_create(&ccutilities, NULL, (void*)(void*) start_utilities, NULL);

            // join threads
            pthread_join(ccecon, NULL);
            pthread_join(ccutilities, NULL);

            break;
    }
    
    return 0;
}

/**
 * @brief Start CC Economy
 */
void start_econ(void *var)
{
    // create bot struct
    bot _bot = {
        "/home/yochran/Documents/code/ChristCentered-Economy",
        "index.js"
    };

    // start bot
    start_bot(&_bot);
}

/**
 * @brief Start CC Utilities
 */
void start_utilities(void *var)
{
    // create bot struct
    bot _bot = {
        "/home/yochran/Documents/code/ccutilities",
        "index.js"
    };

    // start bot
    start_bot(&_bot);
}