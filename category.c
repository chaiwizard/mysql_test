#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void insert_category(char *category, MYSQL* conn)
{
	MYSQL_RES *result;
	unsigned int num_fields;
	unsigned int num_rows;

	if (mysql_query(conn,"insert into CATEGORY (category_description) values('Go');"))
	{
		// error
		printf("mysql query error!\n");
	}
	else // query succeeded, process any data returned by it
	{
		result = mysql_store_result(conn);
		if (result)  // there are rows
		{
			num_fields = mysql_num_fields(result);
			// retrieve rows, then call mysql_free_result(result)
		}
		else  // mysql_store_result() returned nothing; should it have?
		{
			if(mysql_field_count(conn) == 0)
			{
				// query does not return data
				// (it was not a SELECT)
				num_rows = mysql_affected_rows(conn);
			}
			else // mysql_store_result() should have returned data
			{
				fprintf(stderr, "Error: %s\n", mysql_error(conn));
			}
		}
	}

}

int main(int argc, char *argv[]) 
{
	MYSQL *conn = NULL;
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
	char server[] = "localhost";
	char user[] = "root";
	char password[] = "123456";
	char database[] = "books";

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	/*
	 * show tables in books
	 */
	if (mysql_query(conn, "show tables")) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);

	printf("MySQL Tables in books database:\n");

	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \n", row[0]);
	}

	mysql_free_result(res);

	//insert_category("",conn);
	
	if(mysql_query(conn, "select * from CATEGORY")){
		printf("%s\n",mysql_error(conn));
		exit(1);
	}
	res = mysql_use_result(conn);

	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s %s\n", row[0],row[1]);
	}

	mysql_free_result(res);



	mysql_close(conn);

	printf("finish! \n");
	return 0;
}
