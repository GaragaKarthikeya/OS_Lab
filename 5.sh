# Program Number: 5
# Student Name: Karthikeya Garaga; Register Number: IMT2024073
# Date: 30-01-2026
# Description: This shell script displays the file descriptor
# table of a running process using /proc.

echo "Enter PID:"
read pid

echo "File Descriptor Table:"
ls -l /proc/$pid/fd
