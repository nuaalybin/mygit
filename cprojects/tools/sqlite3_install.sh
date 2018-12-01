#!/bin/bash

cd tools
tar xvzf sqlite-autoconf-3070500.tar.gz
cd sqlite-autoconf-3070500
./configure
make
sudo make install