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

echo -n "Testing too many arguments - "
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
if grep -q "#S## # # #" tmp;
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
# M should open map and display an X where the S was
echo "M" |./mazeGame maps/goodMap.txt > tmp
if grep -q "#X## # # #" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 'm' to open map - "
# m should show map and displays an X where the S was
echo "m" |./mazeGame maps/goodMap.txt > tmp
if grep -q "#X## # # #" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


# all movement key tests rely on show map tests being sucessful 

echo -n "Testing 'W/w' for up - "
# 'W' should move up the 'X' from the centre and display on map
# movement keys also test that ' ' can be moved into
echo "W" "w" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "# ###X####" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 'A/a' for left - "
# 'A/a' should move up the 'X' from the centre and display on map
echo "A" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "###X S ###" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "Testing 'S/s' for down - "
# 'S/s' should move down the 'X' from the centre and display on map
echo "S" "s" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "#####X## #" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 'D/d' for right - "
# 'D/d' should move up the 'X' from the centre and display on map
echo "D" "d" "m" |./mazeGame maps/testMap.txt > tmp
if grep -q "#### S X##" tmp;
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

echo -n "Testing '#' error code - "
# if moving into '#' displays error code
./mazeGame maps/testWall.txt < key/wallKey.txt > tmp
if grep -q "Error: Cannot move there" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing '#' X doesn't move - "
# if moving into '#' it doesn't move X on the map
./mazeGame maps/testWall.txt < key/wallKey.txt > tmp
if grep -q "#X####   #" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 'S' can be moved into - "
# if moving into 'S', 'X' should move into 'S' on the map (moving up from S then down into it)
echo "w" "s" "m" | ./mazeGame maps/testMap.txt > tmp
if grep -q "#### X ###" tmp;
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