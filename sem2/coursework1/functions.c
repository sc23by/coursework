#include "library.h"

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

    // check map contains exactly one 'S' and 'E'
    // if map does not contain one 'S' or one 'E'
    // print error code
    // return 1

    // check map has all rows same length and columns same length
    // if not all rows are the same length
    // print error code
    // return 1

    // check map only contains characters 'S','E','#',' '
    // if not, print error code
    //return 1

    // number of rows and columns, then store struct 
    // and store map in 2d array in the struct
    

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


    //if int newi < 0 or newi > maze int columns
        //print error code

    //if int newj < 0 or newj > maze int rows
        //print error code


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
