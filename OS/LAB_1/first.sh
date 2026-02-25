#!/usr/bin/bash

echo "Current directory: $(pwd)"
echo "Files here:"
ls -la

mkdir -p backup
cp *.txt backup/
echo "Text files backed up"
