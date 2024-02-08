#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

namespace sql {

    class DatabaseManager {
    public:
        DatabaseManager();
        ~DatabaseManager();

        void executeQuery();

    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
    };

} // namespace sql

#endif


