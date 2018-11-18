FROM debian:testing
ARG env

LABEL maintainer Petr Chmel petr@chmel.net

RUN apt-get update && apt-get install -y \
    g++ \
    libreadline-dev \
    make

# Clean ups.
RUN apt-get clean

# Copy everything necessary to the image.
RUN mkdir /var/zima
COPY . /var/zima
# RUN rm -rf /var/www/app/.git

