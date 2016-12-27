#!/bin/bash

#
# This file is to do make all nessesary preparations for seting up
# the server
#

# remove old container

# remove old image
docker rmi apa



# build new image
docker build -t apa .

# run container 
# docker run -p 80:80 
