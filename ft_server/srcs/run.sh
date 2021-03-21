#!/bin/bash

apt update
service nginx start
service mysql start
service php7.3-fpm start
mysql -e "create database wordpress;"
mysql -e "create user 'ylee'@'localhost' identified by 'password'"
mysql -e "grant all privileges on *.* to 'ylee'@'localhost' with grant option;"
mysql -e "flush privileges;"
service nginx restart
service mysql restart
service php7.3-fpm restart
