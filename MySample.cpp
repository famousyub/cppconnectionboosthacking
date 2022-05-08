
#include <iostream>
#include <sstream>
#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
#include <cppconn/Statement.h>
#include <cppconn/ResultSet.h>

//define your own configurations in mysql_config.hpp
//for example: HOST = "tcp://127.0.0.1:3306", USER = "root", PASSWORD = "password"
//             DATABASE = "database_name"
#include "mysql_config.hpp"
using namespace std;

void test()


{

    stringstream sql_statement;

    try {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        unique_ptr<sql::Connection> con(driver->connect(HOST, USER, PASSWORD));
        unique_ptr<sql::Statement> stmt(con->createStatement());


        stmt->execute("USE " + DATABASE);
        stmt->execute("DROP TABLE IF EXISTS conference");
        stmt->execute("CREATE TABLE conference(cid int, name varchar(10))");
        cout << "conference table created." << endl;

        stmt->execute("INSERT INTO conference VALUES(1, 'SIGMOD')");
        stmt->execute("INSERT INTO conference VALUES(2, 'VLDB')");
        stmt->execute("INSERT INTO conference VALUES(3, 'ICDE')");
        stmt->execute("INSERT INTO conference VALUES(4, 'KDD')");

        unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM conference"));

        size_t row = 0;
        while (res->next()) {
            cout << row << "\t";
            /* You can use either numeric offsets... */
            cout << "cid = " << res->getInt(1);
            /* ... or column names for accessing results. The latter is recommended. */
            cout << ", name = '" << res->getString("name") << "' " << endl;
            row++;
        }

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__ << " on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        return EXIT_FAILURE;
    } catch (runtime_error &e) {
        cout << "# ERR: runtime_error in " << __FILE__ << " on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        return EXIT_FAILURE;
    }
}