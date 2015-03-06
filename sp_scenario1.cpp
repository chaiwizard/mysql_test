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

#if 0
void getDBMetaData(sql::Connection *conn)
{
	if(conn->isClosed()){
		cout << "Database connection closed!" << endl;
		return;
	}
}
#endif

int main(int argc, char *argv[])
{
	string url = MYSQL_HOST;
	const string user = MYSQL_USER;
	const string password = MYSQL_PWD;
	const string database = MYSQL_DB;

	sql::Driver* driver = get_driver_instance();
	std::auto_ptr<sql::Connection> connection(driver->connect(url,user,password));
	connection->setSchema(database);

	std::auto_ptr<sql::Statement> stmt(connection->createStatement());
	std::auto_ptr<sql::ResultSet> res(stmt->executeQuery("select * from CATEGORY"));
	
	cout << "Retrieved " << res->rowsCount() << " rows." << endl;
	while(res->next()){
		//column index
		cout << res->getString(2) << endl;
		cout << res->getString("category_description") << endl;
	}


	return 0;
}
