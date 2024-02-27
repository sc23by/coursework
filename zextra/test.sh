echo -e "\n-- Argument Tests --"

echo -n "Testing no arguments - "
# no args should display error code
./mazeGame > tmp
if grep -q "Usage: mazeGame <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing too manyarguments - "
# too many args should display error code, tests 2 arguments
./mazeGame extra extra > tmp
if grep -q "Usage: mazeGame <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing bad argument - "
# args entered is not a map name, should display error code "
./mazeGame maps/notAMap.txt > tmp
if grep -q "Error: Bad filename" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing correct arguments - "
# should open and display goodMap.txt and instructions
./mazeGame maps/goodMap.txt > tmp
if grep -q "
goodMap selected:
######E###
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
E is the finishing point
X is your position

------------------------------

Make your way to the E to win!

------------------------------
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e "\n-- Bad user inputs --"

echo -n "Testing invalid keystroke - "
# wrong user input should display error code
./mazeGame maps/goodMap.txt < userInput/incorrectKeystroke.txt > tmp
if grep -q "Error: Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e "\n-- Map Tests --"

echo -n "Testing map too small - "
# if map too small should display error code
./mazeGame maps/smallMap.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map too big - "
# if map too big should display error code
./mazeGame maps/bigMap.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map doesn't contain 'S' - "
# if map doesnt contain S should display error code
./mazeGame maps/noS.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map too many S's - "
# if map has more than one S should display error code
./mazeGame maps/noS.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map doesn't contain 'E' - "
# if map doesnt contain 'E' should display error code
./mazeGame maps/noF.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map too many E's - "
# if map contains more than one 'E' should display error code
./mazeGame maps/noF.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map contains invalid character - "
# if map does not only only contain #, ,S,E should display error code
./mazeGame maps/badCharacters.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map all columns same length - "
# if column lengths arent the same should display error code
./mazeGame maps/badColumns.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing map all row same length - "
# if row lengths arent the same should display error code
./mazeGame maps/badRows.txt > tmp
if grep -q "Error: Map invalid format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi





echo -e "\n-- Good user inputs --"

echo -n "Testing 'M' to open map - "
# M should open map and display 'X' as where you are (the start)
echo "M" |./mazeGame maps/goodMap.txt > tmp
if grep -q "
-- Map --
######E###
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

echo -n "Testing 'm' to open map - "
# m should open map and displays where you are (the start)
echo "m" |./mazeGame maps/goodMap.txt > tmp
if grep -q "
-- Map --
######E###
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

# all movement key tests rely on open map tests being sucessful 

echo -n "Testing 'W' for up - "
# 'W' should move up the 'X' from the centre and display on map
echo "W" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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

echo -n "Testing 'w' for up - "
# 'w' should move up the 'X' from the centre and display on map
echo "w" "m" |./mazeGame maps/testMap.txt > tmp

grep "
-- Map --
##########
##########
#####E####
#####X####
#### S ###
##### ####
##########
##########
##########
##########
" tmp;

if grep -q "
-- Map --
##########
##########
#####E####
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

echo -n "Testing 'A' for left - "
# 'A' should move up the 'X' from the centre and display on map
echo "A" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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

echo -n "Testing 'a' for left - "
# 'a' should move up the 'X' from the centre and display on map
echo "a" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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

echo -n "Testing 'S' for down - "
# 'S' should move down the 'X' from the centre and display on map
echo "S" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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

echo -n "Testing 's' for down - "
# 's' should move down the 'X' from the centre and display on map
echo "s" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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
# 'D' should move up the 'X' from the centre and display on map
echo "D" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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

echo -n "Testing 'd' for right - "
# 'd' should move right the 'X' from the centre and display on map
echo "d" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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


echo -n "Testing 'Q' to quit - "
# 'Q' quits the maze
echo "Q" | ./mazeGame maps/goodMap.txt > tmp
if grep -q "Exiting maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 'q' to quit - "
# 'q' quits the maze
echo "q" |./mazeGame maps/goodMap.txt > tmp
if grep -q "Exiting maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi




echo -e "\n-- Map Functionality --"

# these tests rely on movement keys working and open map key working

echo -n "Testing ' ' - "
# if moving into ' ' moves into space X on the map moves
echo "w" "m" | ./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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
# if moving into '#' displays error code and doesn't move X on the map
./mazeGame maps/testWall.txt < key/wallKey.txt > tmp
if grep -q "
Error: Cannot move there
-- Map --
######E###
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
# if moving into 'S', 'X' should move into 'S' on the map (moving up from S then down into it)
echo "w" "s" | ./mazeGame maps/testMap.txt > tmp
if grep -q "
-- Map --
##########
##########
#####E####
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


echo -n "Testing 'E' - "
# if moving into 'E' should print finishing statement
./mazeGame maps/finishMap.txt < key/finishKey.txt > tmp
if grep -q "Congratulations you finished the maze!" tmp;
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