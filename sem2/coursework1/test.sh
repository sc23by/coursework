echo -e "\n-- Argument Tests --"
#args
echo -n "Testing no arguments - "
#no args displays error code
./mazeGame > tmp
if grep -q "Usage: mazeGame <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 2 arguments (too many) - "
#too many args displays error code
./mazeGame extra extra > tmp
if grep -q "Usage: mazeGame <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing incorrect argument - "
#args is not a map numberecho -n "Testing 2 arguments (too many) - "
#too many args displays error code
./mazeGame maps/notAMap.txt > tmp
if grep -q "Error: Bad filename" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing correct arguments - "
#opens and displays goodMap.txt and instructions
./mazeGame maps/goodMap.txt > tmp
if grep -q "
goodMap selected:
######F###
###### ###
###### ###
###### ###
#   ## ###
# # ## ###
# #    ###
# ########
# ########
#S########

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
F is the finishing point
X is your position

------------------------------

Make your way to the F to win!

------------------------------
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi



echo -e "\n-- Bad user inputs --"
#user inputs

echo -n "Testing invalid keystroke - "
#wrong user input displays error code
./mazeGame maps/goodMap.txt < userInput/incorrectKeystroke.txt > tmp
if grep -q "Error: Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e "\n-- Good user inputs --"
#Outputs
#movements

echo -n "Testing W for forward - "
#w moves forwards and displays on map
./mazeGame maps/testMap.txt < userInput/up.txt > tmp
if grep -q "
-- Map --
##########
##########
#####F####
#####X####
#### S ###
##### ####
##########
##########
##########
##########
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "Testing A for left - "
#a moves left
./mazeGame maps/testMap.txt < userInput/up.txt > tmp
if grep -q "
-- Map --
##########
##########
#####F####
##### ####
####XS ###
##### ####
##########
##########
##########
##########
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing S for down - "
#s moves back
./mazeGame maps/testMap.txt < userInput/down.txt > tmp
if grep -q "
-- Map --
##########
##########
#####F####
##### ####
#### S ###
#####X####
##########
##########
##########
##########
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing D for right - "
#d moves right
if grep -q "
-- Map --
##########
##########
#####F####
##### ####
#### SX###
##### ####
##########
##########
##########
##########
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing m to open map - "
#m opens map and displays where you are
./mazeGame maps/goodMap.txt < userInput/openMap.txt > tmp
if grep -q "
-- Map --
######F###
###### ###
###### ###
###### ###
#   ## ###
# # ## ###
# #    ###
# ########
# ########
#X########" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing X location on map - "
#moves up, opens map and displays new correct location
./mazeGame maps/goodMap.txt < userInput/moveAndOpenMap.txt > tmp
if grep -q "
-- Map --
######F###
###### ###
###### ###
###### ###
#   ## ###
# # ## ###
# #    ###
# ########
#X########
#S########" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing q to quit - "
#q quits the maze
./mazeGame maps/goodMap.txt < userInput/quit.txt > tmp
if grep -q "Exiting maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "\n-- Map Tests --"
#    files
#    map

echo -n "Testing map too small - "
#check if map too small displays error code
./mazeGame maps/smallMap.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map too big - "
#check if map too big displays error code
./mazeGame maps/bigMap.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map doesn't contain S - "
#check if map doesnt contain S displays error code
./mazeGame maps/noS.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map too many S's - "
#check if map has more than one S displays error code
./mazeGame maps/noS.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map doesn't contain F - "
#check if map doesnt contain F displays error code
./mazeGame maps/noF.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map too many F's - "
#check if map contains more than one F displays error code
./mazeGame maps/noF.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map contains invalid character - "
#check if map only contains #, ,S,F displays error code
./mazeGame maps/badCharacters.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map all columns same length - "
#check if column lengths arent the same displays error code
./mazeGame maps/badColumns.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map all row same length - "
#check if row lengths arent the same displays error code
./mazeGame maps/badRows.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "\n-- Map Functionality --"
#    rules

echo -n "Testing ' ' - "
#check if moving into ' ' moves into space displays error code
./mazeGame maps/testMap.txt < userInput/up.txt > tmp
if grep -q "
-- Map --
##########
##########
#####F####
#####X####
#### S ###
##### ####
##########
##########
##########
##########" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing '#' - "
#check if moving into '#' doesnt work and displays error code
./mazeGame maps/testWall.txt < key/wallKey.txt > tmp
if grep -q "
Error: Cannot move there
-- Map --
######F###
###### ###
###### ###
###### ###
#   ## ###
# # ## ###
# #    ###
# ########
##########
#X########
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 'S' - "
#check if moving into 'S' moves into space 
./mazeGame maps/testMap.txt < key/startKey.txt > tmp
if grep -q "
-- Map --
##########
##########
#####F####
##### ####
#### X ###
##### ####
##########
##########
##########
##########" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "Testing 'F' - "
#check if moving into 'F' finishes the maze and exits program.
./mazeGame maps/finishMap.txt < key/finishKey.txt > tmp
if grep -q "Congratulations you finish the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing empty wall 1 - "
#check if moving into side empty wall gives error displays error code
./mazeGame maps/testSide1.txt < key/side1Key.txt > tmp
if grep -q "Error: Cannot move there" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing empty wall 2 - "
./mazeGame maps/testSide2.txt < key/side2Key.txt > tmp
if grep -q "Error: Cannot move there" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e 

rm -f tmp