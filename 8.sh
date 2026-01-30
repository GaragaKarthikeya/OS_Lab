# Program Number: 8
# Student Name: Karthikeya Garaga; Register Number: IMT2024073
# Date: 30-01-2026
# Description: This shell script creates a test file
# and runs the read-only line-by-line reader program.

cat << 'EOT' > input.txt
Line one
Line two
Line three
EOT

./8 input.txt
