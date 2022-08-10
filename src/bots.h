#pragma once

#ifndef BOTS_H
#define BOTS_H
#endif

#ifndef LAUNCH_DELAY
#define LAUNCH_DELAY 500 * 1000
#endif

#include "launcher.h"
#include "threading.h"

// bot structure
struct bot 
{
    char *dir;
    char *name;
};

// public accessible
typedef struct bot bot;

// functions
void *get_bot(void *args);
void start_bot(bot *bot);