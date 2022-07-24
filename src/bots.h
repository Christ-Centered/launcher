#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// bot structure
struct bot {
    char *dir;
    char *name;
};

// public accessible
typedef struct bot bot;

// setup function
void start_bot(bot *_bot)
{
    char *execute = (char*) malloc(100);
    sprintf(execute, "cd %s/ && node %s", _bot->dir, _bot->name);

    printf("%s\n", execute);

    // execute start command
    system(execute);

    // free memory
    free(execute);

    // sleep
    sleep(1);
}