#!/bin/bash

#
# This file must build the server and database connection
# the server
#

# build the apache2-php server
cd Server/
./server_setup.sh
cd ..

# build the SQL database
cd DB/
./db_setup.sh
cd ..

