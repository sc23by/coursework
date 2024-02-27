// include librarys
#include <stdio.h>
#include <stdlib.h>


// struct for maze maps
typedef struct {
    char mapCharacters [100][100];
} maze;
// map size max 100 rectangle


int getMap (char mapName) // input is a map name, opens it, and checks some requirements
{ 
    // print selected mapName 
    // open file mapName
    // if file mapName = NULL
    // print error code
    // return 1

    // check map is not too small or big
    // read file mapName and 
    // if length < 5 or length > 100
    // print error code
    // return 1

    // store map contents in struct

    // check map contains exactly one 'S' and 'E'
    // if map does not contain one 'S' or one 'E'
    // print error code
    // return 1

    // check map has all rows same length and columns same length
    // if not all rows are the same length
    // print error code
    // return 1

    // check map only contains '

    //return 0
}

void showInstructions () //shows instructions
{ 
    // print instructions on w,a,s,d,m,q
}

void showMap () //shows map
{ 
    //print map
    //using nested for loops to print a 2d array
}

int checkMovement (char input, int placeHolder) { 
    // input goes to switch then does some checks to see if valid 
    // then goes to movement function to do the movements if they are valid
    // then new placeHolder value is returned
    
    // read current position of X in maze [i][j] 
    // store as [i] = int oldi and [j] = int oldj


    // switch (input)

        //case w
        // in 2d array [j] (column) increase by 1
        // store [i] = int new i and [j] = int new j
        // read character (newPlace = character)
        // return newPlace

        //case a
        // in 2d array [i] (column) decreases by 1
        // store [i] = int new i and [j] = int new j
        //read character (newPlace = character)
        //return newPlace

        //case s
        // in 2d array [j] (column) decreases by 1
        // store [i] = int new i and [j] = int new j
        //read character (newPlace = character)
        //return newPlace

        //case d
        // in 2d array [i] (column) increase by 1
        // store [i] = int new i and [j] = int new j
        //read character (newPlace = character)
        //return newPlace

    // if newPlace = '#' 
        // print error code

    // if newPlace ' '
        // movement(oldi,oldj,newi,newj,placeHolder)
        // int placeHolder = 0

    // if newPlace = 'S' 
        // movement(oldi,oldj,newi,newj,placeHolder)
        // int placeHolder = 1

    // if newPlace = 'E'
        // print finish maze string
        // exits program

    //return placeHolder
}

void move (int newi, int newj, int oldi, int oldj, int placeHolder) //executes the movement 
{
    // in 2d array set maze[newi][newj] = 'X'

    // if placeHolder = 0
    // maze[oldi][oldj] = ' '  

    // if placeHolder = 1
    // maze [oldi][oldj] = 'S'
}

int main (int argc, char *argv[]) {
    //check arguments
    //if (argc != 2)
    //print error code

    // getMap (argv[1]) // gets map and opens it

    // show intructions and map first:
    // showInstructions ()
    // showMap ()

    // int placeHolder = 0
    // this sets the placeHolder as 0 to begin with because you always start on S

    //in 2d array read location of 'S' and replace with an 'X'

    // while (1)
        // wait for input:

        // switch (input)
            // w/a/s/d/W/A/S/D: checkMovement(input,placeHolder)
            // a new value for placeHolder is returned to use in next instance

            // m: show map()

            // q: print exiting statement and exit program // exit(0)

            //default: print error code 
    
}


/* list of error codes/ print statements to use:

for wrong number of arguments entered:
Usage: mazeGame <filename>

for files that dont exist
Error: Bad filename

for when a wall is in the way:
Error: Cannot move there

for invalid input errors:
Error: Invalid input

for any map formatting errors:
Error: Map invalid format

for when map is selected:
"mapName" selected:

for displaying instructions:
-- Instructions --
W to move up
A to move left
S to move down
D to move right
M to view the map
Q to quit

-- Rules --
# are walls, you cant go through them
S is the starting point
E is the finishing point
X is your position

------------------------------

Make your way to the E to win!

------------------------------

for when the map is displayed:
-- Map --
(MAP)....
.........


for when they get to 'E':
Congratulations you finished the maze!
*/


