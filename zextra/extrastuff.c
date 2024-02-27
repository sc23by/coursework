
echo -n "Testing X location on map - "
# moves up, opens map and displays new correct location
./mazeGame maps/goodMap.txt < userInput/moveAndOpenMap.txt > tmp
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
#X########
#S########" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi