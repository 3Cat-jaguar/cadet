FROM debian:buster

ADD ./srcs /tmp/

RUN apt update
RUN apt-get -y install nginx openssl php-fpm mariadb-server php-mysql vim wget
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048  -keyout /etc/ssl/private/selfsigned.key -out /etc/ssl/certs/selfsigned.crt -subj "/C=KR/ST=Seoul/L=Mapo-gu/O=42Seoul/OU=Lee/CN=localhost"
RUN chmod 600 /etc/ssl/private/selfsigned.key
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN rm latest.tar.gz
RUN mv /wordpress /var/www/html/wordpress
RUN cp /tmp/wp-config.php /var/www/html/wordpress/wp-config.php
RUN chown -R www-data:www-data /var/www/html/wordpress
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv /phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
RUN cp /tmp/config.inc.php /var/www/html/phpmyadmin/config.inc.php
RUN chown -R www-data:www-data /var/www/html/phpmyadmin
RUN cp /tmp/default /etc/nginx/sites-available/default
RUN rm /tmp/*

EXPOSE 80 443

