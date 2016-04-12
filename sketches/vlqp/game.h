#ifndef GAME_H
#define GAME_H

#include "globals.h"
#include "level.h"
#include "enemies.h"
#include "elements.h"
#include "bullet.h"
#include "weapon.h"
#include "door.h"

extern byte level;
extern byte displayLevel;

// methods prototypes ////////////////////////////////////////////////////////

void stateGamePlaying();
void stateGameNextLevel();
void stateGamePrepareLevel();
void stateGameOver();

#endif
