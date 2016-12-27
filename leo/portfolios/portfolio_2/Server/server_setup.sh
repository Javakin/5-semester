#!/bin/bash

#
# This file is to do make all nessesary preparations for seting up
# the server
#

# remove old container
echo "$(docker stop server) has been stoped"
echo "$(docker rm server) has been removed"


# remove old image
docker rmi apa


# build new image
docker build -t apa .

# run container 
docker run -dit -p 80:80 --name server -v /home/daniel/Desktop/git/5-semester/leo/portfolios/portfolio_2/Server/includes/:/var/www/html apa
# docker run -dit -p 80:80 -v (host-dir:container dir)
