#!/bin/bash

mkdir -p secure_config

touch secure_config/database.env

chmod 600 secure_config/database.env

echo "File Successfully created with read and write permission for the group"

ls -l secure_config/database.env
