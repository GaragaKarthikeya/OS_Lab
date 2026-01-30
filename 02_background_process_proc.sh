# Program Number: 2
# Student Name: Karthikeya Garaga; Register Number: IMT2024073
# Date: 30-01-2026
# Description: This shell script displays process information
# from the /proc filesystem for a given PID.

echo "Enter PID:"
read pid

echo "Process status:"
cat /proc/$pid/status

echo ""
echo "Process stat:"
cat /proc/$pid/stat

echo ""
echo "Open file descriptors:"
ls -l /proc/$pid/fd
