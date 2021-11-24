FROM node:latest

RUN apt-get upgrade -y
RUN apt-get update
RUN apt-get install libx11-dev -y
RUN apt-get install libgl1-mesa-dev -y
RUN apt-get install libglfw3-dev -y
RUN apt-get install libglu1-mesa-dev -y
RUN apt-get install libxi-dev -y

COPY . /usr/src/app
WORKDIR /usr/src/app

# RUN apt-get install libmesa-dev
# RUN apt-get upgrade -y
# RUN dpkg --add-architecture i386
# RUN apt-get update
# RUN apt-get install build-essential -y
# RUN apt-get install libssl-dev -y
# RUN apt-get clean
# RUN curl -sSL https://deb.nodesource.com/gpgkey/nodesource.gpg.key | apt-key add -
# RUN apt-get update
# RUN apt-get install nodejs -y
# RUN curl -sL https://deb.nodesource.com/setup_14.x
# RUN apt-get install -y nodejs
# RUN apt-get install -y npm
# RUN npm install -g npm@latest
