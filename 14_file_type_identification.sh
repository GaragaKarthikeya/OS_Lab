# Program Number: 14
# Student Name: Karthikeya Garaga; Register Number: IMT2024073
# Date: 30-01-2026
# Description: This shell script creates different file types
# and identifies them using the file type identification program.

touch regular.txt
mkdir testdir
ln -s regular.txt softlink14
mkfifo fifo14

./14 regular.txt
./14 testdir
./14 softlink14
./14 fifo14
