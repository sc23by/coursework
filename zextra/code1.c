//include librarys
#include "Library.h"

//input map into struct
//struct
typedef struct {
    char height [100];
    char width [100];
} maze;
// map min 5 max 100 rectangle

int getMap () { // choose a map and select it

    int map;
    printf("Choose a Map: \n 1 \n 2\n")
    scanf("%d", mapNumber);

    switch (map)
        case '1': printf("Map 1 selected.\n");
        break;

        case '2': printf("Map 2 selected.\n")
        break;

        File *file = fopen(MapNumber, "r");
        fgets()


        
    
}

int mapValidator () 
{   //function to check that map is not too small (height/width < 5)
    for (int i = 0, i < 5, i++) {
        if (maze.map[i] == NULL) 
        {
            printf("Error: Map is too small, minimum size of 5x5\n");
            return 0;
        }
    }   
}

int showInstructions () {
    //function to show instructions
}

int showMap () {
    //functino to show map
}

int movement () {
    //fucntion for WASD movement
}

int checkMovement () { 
    //check if i can move ther
    // (is there a space or a wall)

}


// 2d array

//how am i going to do this

// things i need:
// map: maze files (test data)
// input files for navigation (test data)
// how to move
// cant move into walls
// start
// finish and actually 
// main function
// other functions inside of a header file (modularity)


