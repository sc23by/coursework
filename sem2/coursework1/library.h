#ifndef LIBRARY_H
#define LIBRARY_H

//include guards use in evry header file
#include <stdio.h>
#include <stdlib.h>

// struct for maze maps
typedef struct {
    int rows;
    int columns;
    char mapCharacters[100][100];
} maze;
// map size max 100 rectangle

#endif  
