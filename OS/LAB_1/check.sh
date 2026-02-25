#!/usr/bin/bash

filename="$1"
if [ -f "$filename" ]; then
 echo "$filename exists"
 echo "Size: $(du -h $filename | cut -f1)"
else
 echo "$filename not found"
fi

