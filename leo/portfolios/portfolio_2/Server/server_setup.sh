#!/bin/bash

#
# This file is to do make all nessesary preparations for seting up
# the server
#

imageName="apa2"
containerName="server"
#myHostname="192.168.1.113"


# remove old container
echo "Stopping server container: $containerName"
docker stop $containerName

echo "Removing server container: $containerName"
docker rm $containerName


# remove old image
docker rmi $imageName


# build new image
docker build -t $imageName .


# run the container 
docker run -dit -p 80:80 --name $containerName -v $(pwd)/includes/:/var/www/html $imageName

