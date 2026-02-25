#!/usr/bin/sh

touch file1 file2 file3 file4 file5

read -p "Enter extension (like .txt): " ext

for f in file1 file2 file3 file4 file5
do
    mv "$f" "$f$ext"
done

mkdir -p text_files others

mv *.txt text_files
mv * others/

echo "Organized! Text files: $count"
