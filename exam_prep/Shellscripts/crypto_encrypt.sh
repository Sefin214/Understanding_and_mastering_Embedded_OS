#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Usage : $0 <target_file>"
	exit 1
fi

FILE="$1"
LOG="maintenance_timeline.txt"

if [ ! -f "$FILE" ]
then
	echo "Error File not Found!"
	echo "$(date): Failed - File not Found: $FILE" >> "$LOG"
	exit 1
fi

if gpg -c "$FILE"
then
	echo "$(date): Success - File Encrypted: $FILE" >> "$LOG"
	echo "File Encrypted successfully"
else
	echo "$(date): Failed - File Not Encrypted: $FILE" >> "$LOG"
	echo "Encryption failed!"
	exit 1
fi

