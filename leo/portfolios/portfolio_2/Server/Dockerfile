###############################################

# This dockerfile creates an apachie-2 server 
											  
###############################################

# setup
 FROM ubuntu:latest
 MAINTAINER javakin danielharaldson@yahoo.com
 
 
 
# install php7.0
 RUN apt-get install -y php7.0
 
# setup apachie2
 RUN apt-get install apache2 -y
 RUN /etc/init.d/apache2 start

# prevent the container from terminating
 CMD apachectl -D FOREGROUND
 
 
 
 
 
 
 
 
 
 
