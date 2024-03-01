#include <ProcedureHeader.h>

ProcedureCall::ProcedureCall(string filePath) : con(nullptr) {
    try {
        YAML::Node config = YAML::LoadFile(filePath);
        host = config["host"].as<std::string>();
        user = config["username"].as<std::string>();
        pass = config["password"].as<std::string>();
        db = config["database"].as<std::string>();
    } catch (YAML::Exception &e) {
        std::cerr << "!!! Yaml parsing error - " << e.what() << " !!!" << std::endl;
    }
}

ProcedureCall::~ProcedureCall() {
    if (con) {
        delete con;
    }
}

void ProcedureCall::connectToDatabase() {

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, user, pass);
        con->setSchema(db);
}

void ProcedureCall::callStoredProcedure() {
   
    if (con) {
        try {
            stmt = con->prepareStatement("CALL num_Employee(?)");
            stmt->setString(1, "IT"); 

            stmt->execute();
        } catch (const sql::SQLException &e) {
            std::cerr << "SQL Exception: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "Error: Database connection not established." << std::endl;
    }
}

void ProcedureCall::displayResult() {
    if (stmt) {
        try {
            sql::ResultSet *res = stmt->getResultSet();
            std::cout << "NumberofEmployee\t" << "Department" << std::endl;
            while (res->next()) {
                std::cout << "\t" << res->getInt(1) << "\t\t" << res->getString(2) << std::endl;
            }
            delete res;
        } catch (const sql::SQLException &e) {
            std::cerr << "SQL Exception: " << e.what() << std::endl;
        }
        delete stmt;
        stmt = nullptr;
    } else {
        std::cerr << "Error: Stored procedure not executed." << std::endl;
    }
}


