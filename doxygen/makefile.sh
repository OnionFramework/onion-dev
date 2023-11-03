OLD=$(< buildnumber.txt)
NEW=$(($OLD + 1))
echo $NEW > buildnumber.txt
sed -i '' -E "s/Version&message=([0-9]+.[0-9]+.[0-9]+) build [0-9]+/Version\&message=\1 build $NEW/" mainpage.md
doxygen Doxyfile