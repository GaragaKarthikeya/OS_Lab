#!/usr/bin/env bash
# OS Lab cleanup script (SAFE)

if [ -n "$ZSH_VERSION" ]; then
  setopt NULL_GLOB
else
  shopt -s nullglob
fi

echo "Cleaning generated files..."

rm -f \
  *.o a.out core core.* \
  source.txt destination.txt input.txt statfile.txt \
  seekfile.txt dupfile.txt modefile.txt created_file.txt \
  testfile.txt regular.txt original.txt hardlink.txt \
  softlink.txt softlink14 fifo14 myfifo \
  file_*.txt

# Remove numeric-only executables (SAFE)
find . -maxdepth 1 -type f -regex './[0-9]+' -delete

echo "Cleanup complete."
