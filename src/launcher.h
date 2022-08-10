#pragma once

#ifndef LAUNCHER_H
#define LAUNCHER_H
#endif

#ifndef SOURCE_DIR
#define SOURCE_DIR "/home/yochran/Documents/code"
#endif

#ifndef BOT_DIR
#define BOT_DIR(str, dest) (sprintf(str, "%s/%s", SOURCE_DIR, dest))
#endif

#ifndef NODE_FILE
#define NODE_FILE "index.js"
#endif