#ifndef CONNECTIONHEADER_H
#define CONNECTIONHEADER_H

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <yaml-cpp/yaml.h>

using namespace std;

class DatabaseConnector{
	private:
		string host;
		string user;
		string pass;
		string db;
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;
	
	public:
		DatabaseConnector();
		~DatabaseConnector();
		void connectToDatabase();
		void queryExecution();
};
#endif

