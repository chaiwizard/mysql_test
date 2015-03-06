#!/bin/sh
sudo apt-get install mysql-server libmysql++-dev
sudo apt-get install libmysqlcppconn-dev

 g++ -o app sp_scenario1.cpp -lmysqlcppconn
