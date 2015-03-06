#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void show_result(MYSQL_RES *result)
{
	MYSQL_ROW row;
	unsigned int num_fields;
	unsigned int i;

	num_fields = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result)))
	{
		unsigned long *lengths;
		lengths = mysql_fetch_lengths(result);
		for(i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int) lengths[i],
					row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

}

int main(int argc, char *argv[]) 
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char server[] = "localhost";
	char user[] = "root";
	char password[] = "123456";
	char database[] = "employee";

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	if (mysql_query(conn, "select * from employee;")) 
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	res = mysql_store_result(conn);
	printf("Number of fields:%d\n",mysql_num_fields(res));

	printf("MySQL Tables in mysql database:\n");
#if 0
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("%s \n", row[0]);
	}
#endif
	show_result(res);

	mysql_free_result(res);

	mysql_close(conn);

	printf("finish! \n");
	return 0;
}
