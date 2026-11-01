#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Usage: $0 <IP address or domain"
	exit 1
fi

ping -c 3 "$1" > /dev/null 2>&1

if [ $? -eq 0 ]
then
	echo "Host reachable"
else
	echo "Host unreachable"
fi
