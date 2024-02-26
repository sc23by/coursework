#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "library.h"

int getMap (char mapName);

void showInstructions ();

void showMap ()

int checkMovement (char input, int placeHolder);

void move (int newi, int newj, int oldi, int oldj, int placeHolder);

#endif