#include "sqlConn.h"

sqlConn::sqlConn(){
}

sqlConn::~sqlConn(){
}

UBACSql* sqlConn::mysqlConnection = nullptr;
uint64_t sqlConn::nID = 0;
string sqlConn::sError = "";
string sqlConn::host = "";
string sqlConn::userName = "";
string sqlConn::password = "";
string sqlConn::database = "";

void sqlConn::DBConn(string ip,string user,string pass,string dbName){
	mysqlConnection = new UBACSql(ip,user,pass,dbName);
}

// user registration
void sqlConn::userRegister(string userName,string userMail,string password,string role,bool& isAdd){
	MYSQL_RES *mResult;

	stringstream ss;
	ss << "INSERT INTO UserDetails (userName,userMail,password,role) VALUES('";
	ss << userName <<"','";
	ss << userMail <<"','";
	ss << password <<"','";
	ss << role <<"')";

	string sQuery = ss.str();
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(sError == ""){
		isAdd = 1;
	}
	else{
		isAdd = 0;
	}
}

//getUserName 
string sqlConn::getUserId(string userMail){
	MYSQL_RES *mResult;

	string userID;
	string sQuery = "SELECT userName FROM UserDetails WHERE userMail = '"+userMail+"'";

	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(mResult){
		MYSQL_ROW mysqlRow;
		while(mysqlRow = mysql_fetch_row(mResult)){
			userID = mysqlRow[0];
		}
		return userID;
	}
	else{
		return NULL;
	}
}

string sqlConn::createSessionId(){
	int MaxVal = 26;
	char sessID[MaxVal] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };

	string result= "";
	for(int i=0;i<8;++i){
		result = result+sessID[rand()%MaxVal];
	}
	bool isSValid;
	sqlConn::isSessionValid(result,isSValid);
	if(isSValid){
		return sqlConn::createSessionId();
	}
	else{
		return result;
	}
}

void sqlConn::sessionBegin(string userId,string sId,bool& isSbegin){
	MYSQL_RES *mResult;

	stringstream ss;
	ss << "INSERT INTO userSession(userId,sId) VALUES ( '";
	ss << userId <<"','";
	ss << sId <<"')";

	string sQuery = ss.str();

	mysqlConnection->query(sQuery,mResult,nID,sError);

	if(sError == ""){
		isSbegin = true;
	}
	else{
		isSbegin = false;
		cout<<"User already logged in "<<endl;
	}
}

void sqlConn::isValidUser(string userName,string password,bool& isValid){
	MYSQL_RES *mResult;
	string sQuery = "SELECT EXISTS(SELECT * FROM UserDetails WHERE userName = '"+userName+"' AND Password = '"+password+"')";
	mysqlConnection->query(sQuery,mResult,nID,sError);
	string i;
	if (mResult)
	{
		MYSQL_ROW mysqlRow;
		while ((mysqlRow = mysql_fetch_row(mResult)))
		{
			i = mysqlRow[0];
		}
		if(i == "1")
		{
			isValid = true;
		}
		else
		{
			isValid = false;
		}

	}
}

void sqlConn::isSessionValid(string sId,bool& isSValid){
	MYSQL_RES *mResult;
	string sQuery = "SELECT EXISTS(SELECT * FROM userSession WHERE sId = '"+sId+"')";
	mysqlConnection->query(sQuery,mResult,nID,sError);
	string i;
	if (mResult)
	{
		MYSQL_ROW mysqlRow;
		while ((mysqlRow = mysql_fetch_row(mResult)))
		{
			i = mysqlRow[0];
		}
		if(i == "1")
		{
			isSValid = true;
		}
		else
		{
			isSValid = false;
		}

	}

}
JsonObject sqlConn::getQuestions(string sessId){
	JsonObject jsonObject;
	if(!mysqlConnection){

		jsonObject["Message"] = "Error: sql connection not initialized";
	}
	string sQuery = "SELECT * FROM questions";
	MYSQL_RES *mResult;
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(mResult){
		MYSQL_ROW mysqlRow;
		int i = 1;
		while(mysqlRow = mysql_fetch_row(mResult)){
			jsonObject[mysqlRow[0]] = "";
			jsonObject[mysqlRow[0]]["Question"] = mysqlRow[1];
			jsonObject[mysqlRow[0]]["options"] = mysqlRow[2];
		}
	}
	return jsonObject;
}

JsonObject sqlConn::reviewResponse(string userName){
	JsonObject jsonObject;
	if(!mysqlConnection){
		jsonObject["Message"] = "Error while sql connection";
	}
	string sQuery = "SELECT q.questionId, q.questionDetails, q.options, r.answer FROM questions q JOIN response r ON q.questionId = r.questionId WHERE r.userName ='"+userName+"'";
	MYSQL_RES *mResult;
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(mResult){
		MYSQL_ROW mysqlRow;
		int i = 1;
		while(mysqlRow = mysql_fetch_row(mResult)){
			jsonObject[mysqlRow[0]] = "";
			jsonObject[mysqlRow[0]]["Question"] = mysqlRow[1];
			jsonObject[mysqlRow[0]]["options"] = mysqlRow[2];
			jsonObject[mysqlRow[0]]["Your answer"] = mysqlRow[3];
		}
	}
	return jsonObject;
}

int sqlConn::calculateMarks(string userName){
	if(!mysqlConnection){
		cerr<<"Error while connecting to the db"<<endl;
	}
	MYSQL_RES *mResult;
	string sQuery ="SELECT r.questionId, r.answer AS user_answer, ak.ans AS correct_answer FROM response r JOIN answerKey ak ON r.questionId = ak.questionId WHERE r.userName ='"+userName+"'";
	bool success = mysqlConnection->query(sQuery,mResult,nID,sError);
	if(success){
		int totalMarks = 0;
		while(MYSQL_ROW row = mysql_fetch_row(mResult)){
			string questionNum = row[0];
			string answer = row[1];
			string correctAns = row[2];

			if(answer == correctAns){
				totalMarks += 4;
			}
			else if(answer == ""){
			}
			else{
				totalMarks -= 1;
			}
		}
		mysql_free_result(mResult);
		return totalMarks;
	} else {
		cerr << "Error: Failed to retrieve answers from the database. " << sError << endl;
		return 0;
	}
}

bool sqlConn::setGrade(string userName,string grade){
	if(!mysqlConnection){
		cerr<<"Error while connecting to the db"<<endl;
	}
	MYSQL_RES *mResult;
	string sQuery = "UPDATE UserDetails SET grade = '"+grade+"' WHERE userName = '"+userName+"'";
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(!mResult){
		cout<<"Update the grades"<<endl;
		return true;
	}
	else{
		cerr<<"Unable to update grades"<<endl;
		return false;
	}
}

JsonObject sqlConn::getRankList(){
	JsonObject jsonObject;
	if(!mysqlConnection){
		jsonObject["Message"] = "Error while sql connection";
	}
	string sQuery = "SELECT userName FROM UserDetails ORDER BY grade ;" ;
	MYSQL_RES *mResult;
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(mResult){
		MYSQL_ROW mysqlRow;
		int i = 1;
		while(mysqlRow = mysql_fetch_row(mResult)){
			if(mysqlRow[0] == NULL){
			}else{
				jsonObject[to_string(i)] = mysqlRow[0];
			}
			i++;
		}
	}
	return jsonObject;
}
JsonObject sqlConn::getGradeList(string grade){
	JsonObject jsonObject;
	if(!mysqlConnection){
		jsonObject["Message"] = "Error while sql connection";
	}
	string sQuery = "SELECT userName,grade FROM UserDetails WHERE grade = '"+grade+"'" ;
	MYSQL_RES *mResult;
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(mResult){
		MYSQL_ROW mysqlRow;
		int i = 1;
		while(mysqlRow = mysql_fetch_row(mResult)){
			if(mysqlRow[0] == NULL){
			}else{
				jsonObject[to_string(i)] = "";
				jsonObject[to_string(i)]["name"] = mysqlRow[0];
				jsonObject[to_string(i)]["grade"] = mysqlRow[1];
			}
			i++;
		}
	}
	int rows = mysql_num_rows(mResult);
	if(rows == 0){
		jsonObject["Message"] = "No students failed";
	}

	return jsonObject;
}

bool sqlConn::checkUser(string userName){
	if(!mysqlConnection){
		cerr<<"Error while connecting to the db"<<endl;
	}
	MYSQL_RES *mResult;
	string role;
	string sQuery = "SELECT role FROM UserDetails WHERE userName = '"+userName+"'";
	mysqlConnection->query(sQuery,mResult,nID,sError);
	if(mResult){
		MYSQL_ROW mysqlRow;
		while(mysqlRow = mysql_fetch_row(mResult)){
			if(mysqlRow[0] == NULL ){
			}
			else{
				 role = mysqlRow[0];
			}
		}
		if(role == "admin" || role == "Admin" || role == "ADMIN"){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}


bool sqlConn::setAnswer(string userName,string questNum,string ans){
	if(!mysqlConnection){
		cerr<<"Error while connecting to the db"<<endl;
	}
	string sQuery = "SELECT * from response WHERE userName = '"+userName+"' AND questionId = '"+questNum+"' AND answer = '"+ans+"'";
	MYSQL_RES *mResult;
	uint64_t affectedRows;
	bool success;
	success = mysqlConnection->query(sQuery, mResult, nID, sError);
	if(!success){
		cerr<<"Error checking for existing record: "<<sError<<endl;
		if(mResult){
			mysql_free_result(mResult);
		}
		return false;
	}

	int rows = mysql_num_rows(mResult);
	mysql_free_result(mResult);
	if(rows > 0){
		cerr<<"Record already exists"<<endl;
		return false;
	}

	// if record does not exist
	sQuery = "INSERT INTO response(userName,questionId,answer) values('" + userName + "', '" + questNum + "', '" + ans + "')";
	success = mysqlConnection->query(sQuery,nID,affectedRows,sError);
	if(!success){
		cerr<<"Error while storing to database - "<<sError<<endl;
		return false;
	}
	if (affectedRows == 0) {
		cerr << "No rows affected by the insertion" << endl;
		return false;
	}
	return true;
}

bool sqlConn::modifyAnswer(string userName,string questNum,string ans){
	if(!mysqlConnection){
		cerr<<"Error while connecting to the db"<<endl;
	}
	string sQuery = "SELECT * from response WHERE userName = '"+userName+"' AND questionId = '"+questNum+"'";
	MYSQL_RES *mResult;
	uint64_t affectedRows;
	bool success;
	success = mysqlConnection->query(sQuery, mResult, nID, sError);
	if(!success){
		cerr<<"Error checking for existing record: "<<sError<<endl;
		if(mResult){
			mysql_free_result(mResult);
		}
		return false;
	}

	int rows = mysql_num_rows(mResult);
	mysql_free_result(mResult);
	if (rows > 0){
		sQuery = "UPDATE response SET answer = '"+ans+"' WHERE userName = '"+userName+"' AND questionId = '"+questNum+"'";
	}
	else{
		sQuery = "INSERT INTO response(userName,questionId,answer) values('" + userName + "', '" + questNum + "', '" + ans + "')";
	}
	success = mysqlConnection->query(sQuery,nID,affectedRows, sError);
	if(!success){
		cerr<<"Error while storing to database - "<<sError<<endl;
		return false;
	}
	if (affectedRows == 0) {
		cerr << "No rows affected by the insertion" << endl;
		return false;
	}
	return true;

}


void sqlConn::userLogOut(string sId, bool& isLogOut){
	MYSQL_RES *mResult;
	string sQuery = "DELETE FROM userSession WHERE sId = '" +sId+ "'";
	mysqlConnection->query(sQuery, mResult, nID, sError);
	if(sError == "")
	{
		isLogOut = true;
	}
	else
	{
		isLogOut = false;
	}
	//delete mysqlConnection;
}
