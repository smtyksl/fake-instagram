#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <sqlite3.h>
#include <vector>

#include "models/user.h"
#include "models/follow.h"
#include "models/like.h"
#include "models/post.h"


class Controller
{
public:
    Controller();
    std::vector<User>getUsers();
    std::vector<Like>getLikes();
    std::vector<Post>getposts(int id);
    std::vector<Follow>getFollow(int id);
private:
    sqlite3 *mDb;
    sqlite3_stmt *mStmt;
    std::vector<User> userList;
    std::vector<Like> likeLists;
};

#endif // CONTROLLER_H
