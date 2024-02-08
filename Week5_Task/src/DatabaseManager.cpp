#include "headers.h"

namespace sql {

    DatabaseManager::DatabaseManager() {
        // Constructor implementation, if needed
    }

    DatabaseManager::~DatabaseManager() {
        // Destructor implementation, if needed
    }

    void DatabaseManager::executeQuery() {
        try {
            // Create a MySQL driver instance
            driver = sql::mysql::get_driver_instance();  // Change this line

            // Create a connection
            con = driver->connect("localhost:3306", "root", "wordpass123");

            // Connect to the MySQL database
            con->setSchema("cars");

            // Execute a simple query
            sql::Statement *stmt = con->createStatement();
            sql::ResultSet *res = stmt->executeQuery("SELECT CarRank,CarName,QuaterMileTime_sec FROM QuaterMile");

            // Process the result set
            std::cout << "CarRank\t" << "CarName\t" << "\tQuater mile time" << std::endl;
            while (res->next()) {
                std::cout << "   " << res->getInt(1) << "\t" << res->getString(2) << "\t" << res->getDouble(3) << std::endl;
            }

            delete res;
            delete stmt;
            delete con;

        } catch (sql::SQLException &e) {
            std::cerr << "SQLException: " << e.what() << std::endl;
        }
    }

} // namespace sql

