# The server dockerfile

FROM ubuntu:latest

MAINTAINER Hello hello@world.com

run apt-get update -y

run apt-get upgrade -y

run apt-get install mariadb-server -y

run sudo mysql -u root -p

#skal have en mysql start

CREATE DATABASE abookdb;
USE abookdb;

CREATE TABLE addressbook (
      equip_id int(5) NOT NULL AUTO_INCREMENT,
      name varchar(50) DEFAULT NULL,
      address varchar(50) DEFAULT NULL,
      PRIMARY KEY(equip_id)
      );

CREATE USER 'ubuntu' IDENTIFIED BY 'ubuntu';
GRANT SELECT, INSERT, UPDATE, DELETE ON addressbook TO 'ubuntu';


# skal stadig bindes til adresser




















# This dockerfile contains the server

 #FROM docker/whalesay:latest
 #RUN apt-get -y update && apt-get install -y fortunes
 #CMD /usr/games/fortune -a | cowsay

# setup
# FROM ubuntu:latest

# MAINTAINER javakin danielharaldson@yahoo.com
 
# install php7.0
 #RUN apt-get -y update 
 #RUN apt-get install -y python-software-properties 
 #RUN apt-get install -y software-properties-common
 
 #RUN echo "MOVING ON"

 #RUN locale-gen en_US.UTF-8
 #RUN export LANG=C.UTF-8
 #RUN add-apt-repository ppa:ondrej/php -y
# RUN apt-get update -y 
# RUN apt-get install -y php7.0
 
# setup apachie2
 #RUN add-apt-repository ppa:ondrej/apache2 -y --allow-unauthenticated
 #RUN apt-get update -y 
# RUN apt-get install apache2 -y
# RUN /etc/init.d/apache2 start

 
# CMD apachectl -D FOREGROUND
 
 
 
 
 
 
 
 
 
 
