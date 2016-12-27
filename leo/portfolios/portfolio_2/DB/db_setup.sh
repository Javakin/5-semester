#!/bin/bash

#
# This dockerfile will create the database
#

# remove old container


# remove old image
docker rmi db


# build new image
docker build -t db .


# run container 

