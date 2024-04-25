#ifndef SQLCONN_H
#define SQLCONN_H

#include <iostream>
#include <string>
#include <sstream>
#include <jsonLanguageParser/langParser.h>
#include <sbu2webapp/SBU2WebService.h>
#include <sbu2webapp/SBU2HTTPServer.h>
#include <ubacyaml/YamlConfig.h>
#include <ubacmysql/MySql.h>

using namespace std;
using namespace SBU2;
using namespace UBACSQL;

class sqlConn{
	public:
		sqlConn();
		~sqlConn();
		static void DBConn(string ip, string user,string pass,string dbName);
		static void userRegister(string userName,string userMail,string password,string role,bool& isAdd);
		static string getUserId(string userMail);
		static string createSessionId();
		static void isValidUser(string userName,string password,bool& isValid);
		static void isSessionValid(string sId,bool& isSValid);
		static void sessionBegin(string userId,string sId,bool& isSbegin);
		static void userLogOut(string sId, bool& isLogOut);
		static JsonObject getQuestions(string);
		static bool setAnswer(string,string,string);
		static bool modifyAnswer(string,string,string);
		static JsonObject reviewResponse(string);
		static bool setGrade(string,string);
		static int calculateMarks(string);
		static JsonObject getRankList();
		static JsonObject getGradeList(string);
		static bool checkUser(string);

		
	private:
		static UBACSql *mysqlConnection;
		static uint64_t nID;
		static string sError;
		static string host,userName,password,database;
};

#endif




