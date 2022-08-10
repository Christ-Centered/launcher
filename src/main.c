#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "exceptions.h"
#include "bots.h"

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
    if (argc != 1)
    {
        // create exception
        exception _exception = {
            "Correct Usage: launch",
            INCORRECT_USAGE
        };

        // throw exception
        throw(&_exception);
        exit(0);
    }

    // setup multithreading
    pthread_t ccecon, ccutilities;

    // get thread args
    thread_args econ_args = { "ChristCentered-Economy" };
    thread_args util_args = { "ccutilities" };

    // create threads
    pthread_create(&ccecon, NULL, get_bot, &econ_args);
    pthread_create(&ccutilities, NULL, get_bot, &util_args);

    // join threads
    pthread_join(ccecon, NULL);
    pthread_join(ccutilities, NULL);
    
    return 0;
}