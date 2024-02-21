#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
//#include <cppconn/exception.h>

using namespace std;

int main(){
	sql::mysql::MySQL_Driver *driver;
	sql::Connection* con;
	try{
		//create a mysql driver instance;
		driver = sql::mysql::get_mysql_driver_instance();

		//create a connection
		con = driver->connect("localhost:3306","root","wordPass123");

		//connecting to mysql database
		con->setSchema("Employee");

		//Execute a simple query
		sql::Statement *stmt = con->createStatement();
		sql::ResultSet *res = stmt->executeQuery("select * from Employee_Details");

		//process and print result
		
		cout<<"EmployeeId\t"<<"FirstName\t"<<"LastName\t"<<"Department\t"<<endl;
		while(res->next()){
			cout<<"  "<<res->getInt(1)<<"\t\t"<<res->getString(2)<<"\t\t"<<res->getString(3)<<"\t\t"<<res->getString(4)<<endl;
		}

		delete res;
		delete stmt;
		delete con;
	}
	catch(sql::SQLException &e){
		cerr<<"SQLException- "<<e.what()<<endl;
	}
	return 0;
}

