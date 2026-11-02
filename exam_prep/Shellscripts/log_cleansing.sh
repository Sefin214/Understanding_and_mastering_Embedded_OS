#!/bin/bash
FILE="system_error.log"

if [ -f "$FILE" ]
then
	echo "File is found: $FILE"
	count=$(wc -l < "$FILE")
	echo "Total Lines : $count"
	> "$FILE"
else
	touch system_error.log
	echo "File : $FILE is created"
fi
