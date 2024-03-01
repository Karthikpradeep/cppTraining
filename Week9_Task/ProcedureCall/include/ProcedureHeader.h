#ifndef PROCEDUREHEADER_H
#define PROCEDUREHEADER_H

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <yaml-cpp/yaml.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class ProcedureCall{
	private:
		string host;
		string user;
		string pass;
		string db;
		sql::mysql::MySQL_Driver *driver;
		sql::Connection* con;
		sql::PreparedStatement *stmt;

	public:
		ProcedureCall(string filePath);
		~ProcedureCall();
		void connectToDatabase();
		void callStoredProcedure();
		void displayResult();
};

#endif

