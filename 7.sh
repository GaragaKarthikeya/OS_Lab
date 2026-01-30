# Program Number: 7
# Student Name: Karthikeya Garaga; Register Number: IMT2024073
# Date: 30-01-2026
# Description: This shell script creates a source file
# and verifies the copied destination file.

echo "This is a test file for cp implementation" > source.txt

./7 source.txt destination.txt

echo ""
echo "Source file contents:"
cat source.txt

echo ""
echo "Destination file contents:"
cat destination.txt
