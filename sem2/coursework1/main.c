// includes file with libraries, struct and functions
#include "library.h"
#include "function.h"

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

