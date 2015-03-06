#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


#define MYSQL_HOST "localhost"
#define MYSQL_USER "root"
#define MYSQL_PWD  "123456"
#define MYSQL_DB   "books"

int main(int argc, char *argv[])
{
	string url = MYSQL_HOST;
	const string user = MYSQL_USER;
	const string password = MYSQL_PWD;
	const string database = MYSQL_DB;


	return 0;	
	return 0;
}
