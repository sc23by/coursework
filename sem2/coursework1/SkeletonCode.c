//include librarys
#include "Library.h"

int getMap () { // choose a map and select it

    // show user selection of maps and ask to select one

    // check if input is valid/ invlaid
    // invalid print Error: Invalid Map selection and show selection of maps again
    // if valid use selection to open map file

    // check if map can be openened
    // if not show error
    // if yes open


}

int mapValidator () {  //check that map is not too small (height/width < 5)

    // for loop i < 5 loop map does not == NULL
    // print error if map is too small

        //could this be a part of getMap?
}

int showInstructions () { //show instructions to user

    // print list of instructions on W,A,S,D,M,Q
    //use when there is an invalid input to remind user of valid inputs

}

int showMap () { // show map to user
    // use at start when map is selected
    // when M is clicked, show current map to user
    // include there current position using X

    // use nested loop to print 2d array


}

void movement () { //WASD movement
    // define what each letter does and what happens when pressed
    // using switch
    
    // W = up
    // A = left
    // S = down
    // D = right

    //then goes to checkMovement to check if able to move
    
}

void checkMovement () { //to check if user is allowed to move
    // if there is a # where they try to move
    // print Error: Wall in the way. Try again.

    // if it is the end of the map where they try to move
    // print Error: Map Wall in the way. Try again.

    // if there is a ' ', or an S:
    // allow user to carry out move
    // updates position on map for player X

    // if there is a F:
    // MAZE COMPLETED WELL DONE!

    // should this be a part of movement?? or happen before movememt
}

int main () {
    getMap (); // gets map and opens it
    mapValidator () ; //validates the map
    showInstructions (); //shows instructions
        
    //ask for input
    // switch input
    //case 'W || A || S || D || w || a || s || d ||':
        // movement ();
        // check movement ();
    //case 'M || m|':
        // show map ();
    //case 'Q || q':
        //closes the file and exits
    showMap () ; //shows map
    movement () ; //moves player

}




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


