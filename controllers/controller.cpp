#include "controller.h"

#include <iostream>

Controller::Controller()
    : mDb(nullptr)
    , mStmt(nullptr)

{
    // Open the database file
    if (sqlite3_open("db.sqlite3", &mDb) != SQLITE_OK)
        std::cerr << "Error opening database: " << sqlite3_errmsg(mDb) << std::endl;
}

std::vector<User> Controller::getUsers()
{

    const char *sql = "SELECT * FROM User";
    if (sqlite3_prepare_v2(mDb, sql, -1, &mStmt, NULL) != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(mDb) << std::endl;
//        sqlite3_close(mDb);
    }
    int rc;
    while ((rc = sqlite3_step(mStmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(mStmt, 0);
        auto userName = std::string (reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 1)));
//        auto email = std::string (reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 2)));
        auto fullName = std::string (reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 3)));
        auto profilePicture = std::string (reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 4)));
//        auto bio = std::string (reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 5)));
        long int createdAt = sqlite3_column_int(mStmt, 6);
        userList.push_back(
            User(id,userName,"email",fullName,profilePicture,"bio",createdAt)
            );
    }
    return userList;
}

std::vector<Like> Controller::getLikes()
{
    // Prepare the SQL statement to select all likes
    const char *sql = "SELECT * FROM like ORDER BY created_at ASC";
    if (sqlite3_prepare_v2(mDb, sql, -1, &mStmt, NULL) != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(mDb) << std::endl;
        sqlite3_close(mDb);
    }

    // Execute the SQL statement and fetch the results
    int rc;
    while ((rc = sqlite3_step(mStmt)) == SQLITE_ROW) {
        // Get the values of the columns in the current row
        int id = sqlite3_column_int(mStmt, 0);
        int createdAt = sqlite3_column_int(mStmt, 1);
        int postId = sqlite3_column_int(mStmt, 2);
        int userId = sqlite3_column_int(mStmt, 3);

        // Print the values of the columns in the current row
        std::cout << "ID: " << id << ", Created At: " << createdAt << ", Post ID: " << postId << ", User ID: " << userId << std::endl;
        likeLists.push_back(
            Like(id,postId,userId,createdAt));
    }
    // Finalize the SQL statement and close the database connection
    sqlite3_finalize(mStmt);
    sqlite3_close(mDb);

    return likeLists;
}

std::vector<Post> Controller::getposts(int id)
{
    // Prepare the SQL statement to select all posts
    std::string query = "SELECT * FROM post WHERE user_id==" + std::to_string(id) + "ORDER BY created_at ASC";
    const char *sql = query.c_str();
    if (sqlite3_prepare_v2(mDb, sql, -1, &mStmt, NULL) != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(mDb) << std::endl;
        sqlite3_close(mDb);
    }
    std::vector<Post> postList;
    // Execute the SQL statement and fetch the results
    int rc;
    while ((rc = sqlite3_step(mStmt)) == SQLITE_ROW) {
        // Get the values of the columns in the current row
        int id = sqlite3_column_int(mStmt, 0);
        std::string description = reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 1));
        int userId = sqlite3_column_int(mStmt, 2);
        std::string image = reinterpret_cast<const char *>(sqlite3_column_text(mStmt, 3));
        int createdAt = sqlite3_column_int(mStmt, 4);

        // Print the values of the columns in the current row
        std::cout << "ID: " << id << ", Description: " << description << ", User ID: " << userId << ", Image: " << image << ", Created At: " << createdAt << std::endl;
        postList.push_back(
            Post(id,description,userId,image,createdAt)
            );
    }

    // Finalize the SQL statement and close the database connection
    sqlite3_finalize(mStmt);
    sqlite3_close(mDb);
    return postList;
}

std::vector<int> Controller::getFollow(int id)
{

    // Prepare the SQL statement to select all follows
    std::vector<int> followingIds;
    std::string query = "SELECT following_id FROM follow WHERE follower_id== " + std::to_string(id) + + "ORDER BY created_at ASC";
    const char *sql = query.c_str();
    if (sqlite3_prepare_v2(mDb, sql, -1, &mStmt, NULL) != SQLITE_OK) {
        std::cerr << "Error preparing SQL statement: " << sqlite3_errmsg(mDb) << std::endl;
        sqlite3_close(mDb);
    }

    // Execute the SQL statement and fetch the results
    int rc;
    while ((rc = sqlite3_step(mStmt)) == SQLITE_ROW) {
        // Get the values of the columns in the current row
        int followingId = sqlite3_column_int(mStmt, 1);
        followingIds.push_back(followingId);
    }

    // Finalize the SQL statement and close the database connection
    sqlite3_finalize(mStmt);
    sqlite3_close(mDb);
    return followingIds;
}

