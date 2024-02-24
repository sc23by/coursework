echo -n "Testing 'A' for left - "
# 'A' should move up the 'X' from the centre and display on map
echo "a" "m" |./fake > tmp
if grep -q "
a
m
" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi