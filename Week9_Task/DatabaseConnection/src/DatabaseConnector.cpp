#include <ConnectionHeader.h>

DatabaseConnector::DatabaseConnector(string filePath){
	try{
		cout<<filePath<<endl;
		YAML::Node config = YAML::LoadFile(filePath);
		host = config["host"].as<string>();
		user = config["username"].as<string>();
		pass = config["password"].as<string>();
		db = config["database"].as<string>();
	}
	catch(YAML::Exception &e){
		cerr<<"!!! YAML parsing error - "<<e.what()<<" !!!"<<endl;
	}
}

DatabaseConnector::~DatabaseConnector(){
	delete con;
}

void DatabaseConnector::connectToDatabase(){
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(host,user,pass);
	con->setSchema(db);
}

void DatabaseConnector::queryExecution(){
	sql::Statement *stmt = con->createStatement();
	sql::ResultSet *res = stmt->executeQuery("SELECT EmployeeID,FirstName,Department,Salary FROM Employee_Details WHERE Salary>60000");
	cout<<"EmployeeId\t"<<"FirstName\t"<<"Department\t"<<"Salary\t"<<endl;
	while(res->next()){
		cout<<"   "<<res->getInt(1)<<"\t\t"<<res->getString(2)<<"\t\t"<<res->getString(3)<<"\t\t"<<res->getInt(4)<<endl;
	}
	delete res;
	delete stmt;
}

