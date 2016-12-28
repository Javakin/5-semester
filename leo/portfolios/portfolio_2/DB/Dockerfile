###############################################
# 
# Creates an mySQL dataabase 
# 											  
###############################################

# setup
 FROM ubuntu:latest
 MAINTAINER javakin danielharaldson@yahoo.com
 
 run apt-get update && apt-get upgrade -y
 
 run apt-get install mariadb-server -y
 
 run /etc/init.d/mysql start
 
 sleep 10s &&\
 
 CREATE DATABASE abookdb
 
 USE abookdb
 
 CREATE TABLE addressbook (
      equip_id int(5) NOT NULL AUTO_INCREMENT,
      name varchar(50) DEFAULT NULL,
      address varchar(50) DEFAULT NULL,
      PRIMARY KEY(equip_id)
      )
	  
 CREATE USER 'ubuntu' IDENTIFIED BY 'ubuntu';
 GRANT SELECT, INSERT, UPDATE, DELETE ON addressbook TO 'ubuntu';
 | mysql
 
 run sed -i "s|bind-address		= 127.0.0.1|#bind-address		= 127.0.0.1|g" /etc/mysql/mariadb.conf.d/50-server.cnf
 
# run container in forground

CMD ["/usr/bin/mysqld_safe"]
 
 
 
 
 
 
 
 
 
 
