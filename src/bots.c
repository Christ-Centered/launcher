#include "bots.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Start a bot
 * 
 * @param bot - the bot
 */
void start_bot(bot *bot)
{
    // get command
    char *command = (char*) malloc(100);
    sprintf(command, "cd %s && node %s", bot->dir, bot->name);

    // execute command
    system(command);

    // free memory
    free(command);

    // sleep
    usleep(LAUNCH_DELAY);
}

/**
 * @brief Get a bot
 */
void *get_bot(void *args)
{
    // get args
    thread_args *_args = (thread_args*) args;

    // get directory
    char *str = (char*) malloc(100);
    BOT_DIR(str, _args->name);

    // create bot struct
    bot bot = {
        str,
        NODE_FILE
    };

    // start bot
    start_bot(&bot);

    // free memory
    free(str);
}