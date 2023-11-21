#include <iostream>
//#include "crow.h"
#include <sqlite3.h>
#include <controllers/controller.h>
using namespace std;

//int  getSomething() {
//    sqlite3 *db;
//    sqlite3_stmt *stmt;

//    // Open the database file
//    if (sqlite3_open("db.sqlite3", &db) != SQLITE_OK) {
//        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
//        return 1;
//    }

//    // Prepare the SQL statement to select all records from the "users" table
//    const char *sql = "SELECT * FROM User";
//    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
//        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << std::endl;
//        sqlite3_close(db);
//        return 1;
//    }

//    // Execute the SQL statement and fetch the results
//    int rc;
//    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//        // Get the values of the columns in the current row
//        int id = sqlite3_column_int(stmt, 0);
//        auto userName = std::string (reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
//        auto email = std::string (reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));
//        auto fullName = std::string (reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
//        auto profilePicture = std::string (reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
//        auto bio = std::string (reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
//        int createdAt = sqlite3_column_int(stmt, 6);


//        // Print the values of the columns
////        std::cout << "ID: " << id << " | Name: " << name << " | Email: " << email << std::endl;
//    }

//    // Finalize the SQL statement and close the database connection
//    sqlite3_finalize(stmt);
//    sqlite3_close(db);

//}

int main()
{

    Controller c;
//    auto listUSer = c.getUsers();
//    for(auto user: listUSer) {
//        std::cout<< "========\n";
//        std::cout<< user.toString();
//    }

    auto listLike = c.getLikes();
    for(auto like: listLike) {
       std::cout<< like.toString();
    }
//    getSomething();
//    crow::SimpleApp app;

//    CROW_ROUTE(app, "/")
//    ([]() {
//        return "Hello, world!";
//    });

//    app.port(18080).run();
    return 0;
}
