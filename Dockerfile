FROM gcc:9.5.0

RUN apt-get update && apt-get install -y curl && curl -sL https://deb.nodesource.com/setup_14.x | bash - && apt-get install -y nodejs
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add - && echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list && apt-get update && apt-get install -y yarn
RUN apt-get update && apt-get install -y python3 python3-pip

# FROM node:latest

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
