FROM ubuntu:18.04

RUN apt-get upgrade -y \
 && dpkg --add-architecture i386 \
 && apt-get update \
 && apt-get install gcc yarn nodejs npm zip bash tar unzip lib32z1 lib32ncurses5 screen wget curl mysql-client -y \
 && apt-get clean

RUN apt-get install nodejs

RUN npm install -g yarn

# RUN mkdir /usr/src/app
# RUN cd /usr/src/app

# RUN cd /usr/src/app
WORKDIR /usr/src/app

COPY . .

RUN ls




