#!/bin/bash

# Create the build directory if it doesn't exist
mkdir -p build

# Find all files (not directories) excluding .git and build folders
find . -type d \( -path "./.git" -o -path "./build" \) -prune -false -o -type f | while read -r file; do
    filename=$(basename "$file")

    # Skip hidden files (like .DS_Store, .env etc.)
    if [[ "$filename" == .* ]]; then
        continue
    fi

    # Check if the file has no extension
    if [[ "$filename" != *.* ]]; then
        echo "Moving $file to build/"
        mv "$file" "build/$filename"
    fi
done