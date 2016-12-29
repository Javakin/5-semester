#!/bin/bash

#
# This dockerfile will create the database
#

imageName="db"
containerName="db_container"

# remove old container
#echo "Stopping database container: $containerName"
#docker stop $containerName
#echo "Removing database container: $containerName"
#docker rm $containerName

# remove old image
#docker rmi imageName


# build new image
docker build -t $imageName .


# run container 
#docker run -dit --name $containerName $imageName
