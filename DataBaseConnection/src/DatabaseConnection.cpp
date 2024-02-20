#include <headers.h>

using namespace sql;
using namespace std;
int main() {
    mysql::MySQL_Driver *driver;
    Connection *con;

    try {
        // Create a MySQL driver instance
        driver = mysql::get_mysql_driver_instance();

        // Create a connection
        con = driver->connect("localhost:3306", "root","wordPass123");

        // Connect to the MySQL database
        con->setSchema("cars");

        // Execute a simple query
        Statement *stmt = con->createStatement();
        ResultSet *res = stmt->executeQuery("SELECT CarRank,CarName,QuaterMileTime_sec,TopSpeed_mph FROM QuaterMile");

        // Process the result set
	cout<<"CarRank\t"<<"CarName\t"<<"\tQuater mile time"<<"\tTopSpeed"<<endl;
        while (res->next()) {
            cout << "   " << res->getInt(1) << "\t" << res->getString(2) <<"\t"<< res->getDouble(3)<<"\t\t"<<res->getInt(4) <<endl;
        }

        delete res;
        delete stmt;
        delete con;

    } catch (SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
    }

    return 0;
}

